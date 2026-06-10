#include "mWorkTask.h"
#include "MFormWorkStep.h"
#include "ui_MFormWorkStep.h"
#include "MATEQ/combase.h"
#include <QMutexLocker>

mWorkTask *m_WorkTask;

MST_JLTestingData mst_CurTestingDatas;
MStruct_AutoPrintLabel mStruct_AutoPrintLabel;

namespace {
int currentAteqEnable()
{
    return CurWorkPar.ATEQ_Enable;
}
//等待ATEQ数据时间
const int kAteqDataTimeoutMs = 5000;
const int kProductReadyTimeoutMs = 5000;
const int kPreScanResetWaitMs = 500;
const int kPhysicalResetClearWarnMs = 3000;

void setTowerLight(bool yellow, bool green, bool red)
{
    if(m_ModbusRtu == nullptr){
        return;
    }

    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("黄灯"), yellow ? 1 : 0);
    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("绿灯"), green ? 1 : 0);
    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("红灯"), red ? 1 : 0);
}

bool currentChannelValid()
{
    const uint channel = CurWorkPar.channel.toUInt();
    return channel > 0 && channel <= 50;
}

bool currentAteqValid()
{
    const int ateqEnable = currentAteqEnable();
    return ateqEnable == 1 || ateqEnable == 2 || ateqEnable == 3;
}

QByteArray scanTriggerCommand()
{
    QByteArray sendByte;
    sendByte.append(0x16);
    sendByte.append(0x54);
    sendByte.append(0x0D);
    return sendByte;
}

}

void AutoPrintLabel_BeginCountTime()//开始计时
{
    mStruct_AutoPrintLabel.v_rec_timeout_100ms = 0;
    mStruct_AutoPrintLabel.b_rec_count_en = true;
}

void AutoPrintLabel_EndCountTime()//停止计时
{
    mStruct_AutoPrintLabel.b_rec_count_en = false;
    mStruct_AutoPrintLabel.v_rec_timeout_100ms = 0;
}


bool mWorkTask::acceptBarcode(const QString &barcode, const MTestingUiSnapshot &snapshot, QString *rejectReason)
{
    const QString code = barcode.trimmed();
    if(code.isEmpty()){
        if(rejectReason != nullptr){
            *rejectReason = "扫码数据为空";
        }
        return false;
    }

    QMutexLocker locker(&m_barcodeMutex);
    if(!b_gameover || !currentBarcode.isEmpty()){
        if(rejectReason != nullptr){
            *rejectReason = "工位正在测试，忽略本次扫码";
        }
        return false;
    }
    if(B_BTN_EMC_ONE || B_BTN_EMC){
        if(rejectReason != nullptr){
            *rejectReason = "急停状态，忽略本次扫码";
        }
        return false;
    }

    pendingBarcode = code;
    pendingSnapshot = snapshot;
    pendingSnapshot.product_code = code;
    return true;
}

QString mWorkTask::takePendingBarcode(MTestingUiSnapshot *snapshot)
{
    QMutexLocker locker(&m_barcodeMutex);
    if(pendingBarcode.isEmpty()){
        return QString();
    }

    currentBarcode = pendingBarcode;
    currentSnapshot = pendingSnapshot;
    pendingBarcode.clear();
    pendingSnapshot = MTestingUiSnapshot();
    if(snapshot != nullptr){
        *snapshot = currentSnapshot;
    }
    return currentBarcode;
}

void mWorkTask::clearCurrentBarcode()
{
    QMutexLocker locker(&m_barcodeMutex);
    currentBarcode.clear();
    currentSnapshot = MTestingUiSnapshot();
}

void mWorkTask::clearAteqReceiveState()
{
    if(m_COMLeakHunting != nullptr){
        QMetaObject::invokeMethod(m_COMLeakHunting, "clearReceiveState", Qt::QueuedConnection);
    }
    if(m_COMLeakHunting_2 != nullptr){
        QMetaObject::invokeMethod(m_COMLeakHunting_2, "clearReceiveState", Qt::QueuedConnection);
    }
}

void mWorkTask::setDetectionTimerActive(bool enabled)
{
    detectionTimerActive = enabled;
    emit sign_setTimeFlag(enabled);
}

void mWorkTask::resetLeakCycleState()
{
    {
        QMutexLocker locker(&m_leakCycleMutex);
        cycleAteqEnable = currentAteqEnable();
        ateqDataWaitMs = 0;
        plcLeakResultLatched = false;
        plcOverallResultOk = true;
        ateq1DataReceived = false;
        ateq2DataReceived = false;
        ateq1UiCleared = false;
        ateq2UiCleared = false;
        allResetRequested = false;
        leakStartRequested = false;
        productReadyWaitMs = 0;
    }
    clearAteqReceiveState();
}

bool mWorkTask::requiredAteqDataReceived() const
{
    QMutexLocker locker(&m_leakCycleMutex);
    if (cycleAteqEnable == 1) {
        return ateq1DataReceived;
    }
    if (cycleAteqEnable == 2) {
        return ateq2DataReceived;
    }
    if (cycleAteqEnable == 3) {
        return ateq1DataReceived && ateq2DataReceived;
    }
    return true;
}

void mWorkTask::requestReceivedLeakResets()
{
    bool requestReset = false;

    {
        QMutexLocker locker(&m_leakCycleMutex);
        if ((cycleAteqEnable == 1 || cycleAteqEnable == 3)
                && ateq1DataReceived && !ateq1UiCleared) {
            ateq1UiCleared = true;
        }
        if ((cycleAteqEnable == 2 || cycleAteqEnable == 3)
                && ateq2DataReceived && !ateq2UiCleared) {
            ateq2UiCleared = true;
        }

        const bool readyForReset =
                (cycleAteqEnable == 1 && ateq1DataReceived)
                || (cycleAteqEnable == 2 && ateq2DataReceived)
                || (cycleAteqEnable == 3 && ateq1DataReceived && ateq2DataReceived);
        if (readyForReset && !allResetRequested) {
            allResetRequested = true;
            requestReset = true;
        }
    }

    if (requestReset) {
        m_ModbusRtu->requestAllReset();
    }
}

void mWorkTask::finishLeakCycleAfterResult()
{
    v_Step_JL = ENM_STEP::Exhaust;
    v_Step_WorkModel = ENM_STEP_WORK_MODEL::Reset;
    v_Step_JL_Reset = ENM_STEP::Exhaust;
}

void mWorkTask::slot_onAteqDataReceived(int device, const QString &pressure, const QString &leakage)
{
    acceptAteqData(device, pressure, leakage);
}

int mWorkTask::activeAteqEnable() const
{
    QMutexLocker locker(&m_leakCycleMutex);
    if(cycleAteqEnable >= 1 && cycleAteqEnable <= 3){
        return cycleAteqEnable;
    }
    return currentAteqEnable();
}

bool mWorkTask::acceptAteqData(int device, const QString &pressure, const QString &leakage)
{
    Q_UNUSED(pressure);
    Q_UNUSED(leakage);

    const bool validDevice = (device == 1 || device == 2);
    const bool inLeakReceiveWindow =
            v_Step_JL == ENM_STEP::StartJL
            || v_Step_JL == ENM_STEP::Wait_Start
            || v_Step_JL == ENM_STEP::JudgeResult;
    if(!validDevice || b_gameover || !inLeakReceiveWindow){
        qDebug() << "[ATEQ] ignored data"
                 << "device=" << device
                 << "step=" << v_Step_JL
                 << "gameover=" << b_gameover;
        return false;
    }

    int ateqEnableSnapshot = 0;
    {
        QMutexLocker locker(&m_leakCycleMutex);
        if (device == 1) {
            ateq1DataReceived = true;
        } else if (device == 2) {
            ateq2DataReceived = true;
        } else {
            return false;
        }
        ateqEnableSnapshot = cycleAteqEnable;
    }

    qDebug() << "[ATEQ] received data" << device
             << "cycleEnable=" << ateqEnableSnapshot
             << "gameover=" << b_gameover;
    // Keep PLC physical reset latch state after leak result.
    // Do not issue the D1900.4 all-reset pulse automatically on ATEQ data.
    return true;
}

void mWorkTask::requestManualReset()
{
    QMutexLocker locker(&m_manualResetMutex);
    manualResetRequested = true;
}

bool mWorkTask::takeManualResetRequest()
{
    QMutexLocker locker(&m_manualResetMutex);
    const bool requested = manualResetRequested;
    manualResetRequested = false;
    return requested;
}

void mWorkTask::performManualReset()
{
    int resetEnable = 0;
    {
        QMutexLocker locker(&m_leakCycleMutex);
        const bool activeCycle = !b_gameover && cycleAteqEnable >= 1 && cycleAteqEnable <= 3;
        resetEnable = activeCycle
                ? cycleAteqEnable
                : currentAteqEnable();
        cycleAteqEnable = resetEnable;
        ateqDataWaitMs = 0;
        plcLeakResultLatched = false;
        ateq1DataReceived = false;
        ateq2DataReceived = false;
        ateq1UiCleared = false;
        ateq2UiCleared = false;
        allResetRequested = false;
        leakStartRequested = false;
        productReadyWaitMs = 0;
    }

    {
        QMutexLocker locker(&m_barcodeMutex);
        pendingBarcode.clear();
        currentBarcode.clear();
        pendingSnapshot = MTestingUiSnapshot();
        currentSnapshot = MTestingUiSnapshot();
    }

    b_gameover = true;
    v_Step_JL = ENM_STEP::NE;
    v_Step_JL_Reset = ENM_STEP::NE;
    v_Step_WorkModel = ENM_STEP_WORK_MODEL::NE_WORK;
    preResetAction = NoPreResetAction;
    preResetCompletedForPendingBarcode = false;
    preScanResetWaitMs = 0;

    m_ModbusRtu->requestAllReset();
    clearAteqReceiveState();

    AutoPrintLabel_EndCountTime();
    B_Resset_Hand = false;
    B_next_reset = false;
    b_resetBtnDown_FC = false;
    v_resetCount_FC = 0;
    b_onSite = false;
    v_EQ_JL_Error = 0;
    CurWorkPar.Result_Pisitive.clear();
    CurWorkPar.Result_Negative.clear();
    if (MFormJLStation::mutualUi != nullptr) {
        setDetectionTimerActive(false);
        emit sign_init_Display();
        emit sign_applyManualResetUi();
    }

    qDebug() << "[PLC] manual reset requested, ateqEnable=" << resetEnable;
}

mWorkTask::mWorkTask(QObject *parent) : QObject(parent)
{
    pthread = new QThread;
    this->moveToThread(pthread);
}


void mWorkTask::WorkTask()//工作主函数
{
    b_workTask_en = true;

    setTowerLight(false, false, false);
    while(b_workTask_en){

        pthread->msleep(20);

        const bool plcPhysicalReset = m_ModbusRtu->plcPhysicalResetRequested();
        const bool plcPhysicalResetLatch = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 11);
        if(!plcPhysicalResetLatch){
            physicalResetLatchHandled = false;
        }

        const bool physicalResetTrigger =
                plcPhysicalReset && (!lastPlcPhysicalReset || (plcPhysicalResetLatch && !physicalResetLatchHandled));
        bool hasPendingBarcodeForPhysicalReset = false;
        {
            QMutexLocker locker(&m_barcodeMutex);
            hasPendingBarcodeForPhysicalReset = !pendingBarcode.isEmpty();
        }
        const bool physicalResetInScanTransition =
                preResetAction != NoPreResetAction || hasPendingBarcodeForPhysicalReset;
        if(physicalResetTrigger && plcPhysicalResetLatch && physicalResetInScanTransition){
            if(plcPhysicalResetLatch){
                physicalResetLatchHandled = true;
                m_ModbusRtu->clearPhysicalResetLatch();
            }
            qDebug() << "[PLC] physical reset ignored, scan transition"
                     << "preResetAction=" << preResetAction
                     << "hasPendingBarcode=" << hasPendingBarcodeForPhysicalReset
                     << "N10=" << m_ModbusRtu->plc_N10
                     << "D1901=" << m_ModbusRtu->plc_D1901;
        }else if(physicalResetTrigger){
            requestManualReset();
            waitingPhysicalResetClear = plcPhysicalResetLatch;
            physicalResetClearWarned = false;
            physicalResetClearWaitMs = 0;
            if(plcPhysicalResetLatch){
                physicalResetLatchHandled = true;
                m_ModbusRtu->clearPhysicalResetLatch();
            }
            qDebug() << "[PLC] physical reset trigger"
                     << "N10=" << m_ModbusRtu->plc_N10
                     << "D1901=" << m_ModbusRtu->plc_D1901;
        }
        lastPlcPhysicalReset = plcPhysicalReset;

        if(waitingPhysicalResetClear){
            if(!plcPhysicalResetLatch){
                waitingPhysicalResetClear = false;
                physicalResetClearWarned = false;
                physicalResetClearWaitMs = 0;
                qDebug() << "[PLC] physical reset latch cleared by PLC";
            }else{
                physicalResetClearWaitMs += 20;
                if(physicalResetClearWaitMs >= kPhysicalResetClearWarnMs && !physicalResetClearWarned){
                    physicalResetClearWarned = true;
                    qDebug() << "[PLC] physical reset latch still high after reset pulse"
                             << "D1901=" << m_ModbusRtu->plc_D1901;
                }
            }
        }

        if(takeManualResetRequest()){
            performManualReset();
            continue;
        }


        //软件准备完成



        if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("急停")) == 1){

            B_BTN_EMC_ONE = true;
            if(!B_BTN_EMC){
                B_BTN_EMC = true;
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("启动检漏"), 0);
                m_ModbusRtu->requestAllReset();
            }
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸下压"), 0);
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸上升"), 0);

            continue;
        }else if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("急停")) == 0){
            if(B_BTN_EMC){
                b_gameover = true;
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏1复位") , 0);
            }
            B_BTN_EMC = false;
        }

//        if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("到位")) == 1 && !b_onSite){
        const bool plcOverallTesting = m_ModbusRtu->plcOverallTesting();
        if(plcOverallTesting && !lastPlcOverallTesting){
            bool hasBarcode = false;
            {
                QMutexLocker locker(&m_barcodeMutex);
                hasBarcode = !pendingBarcode.isEmpty() || !currentBarcode.isEmpty();
            }

            if(preResetAction != NoPreResetAction){
                qDebug() << "[PLC] start ignored, pre-scan reset pending";
            }else if(!b_gameover || hasBarcode){
                qDebug() << "[PLC] start ignored, active cycle";
            }else if(B_BTN_EMC_ONE || B_BTN_EMC){
                emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                qDebug() << "[PLC] scan trigger ignored, emergency stop";
            }else if(!currentChannelValid()){
                emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                qDebug() << "[PLC] scan trigger ignored, invalid channel" << CurWorkPar.channel;
            }else if(!currentAteqValid()){
                emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                qDebug() << "[PLC] scan trigger ignored, invalid ATEQ enable" << currentAteqEnable();
            }else{
                m_ModbusRtu->requestAllReset();
                preResetAction = TriggerScannerAfterPreReset;
                preResetCompletedForPendingBarcode = false;
                preScanResetWaitMs = 0;
                qDebug() << "[PLC] D1901 bit1 rising edge, pre-scan reset"
                         << "ATEQ=" << currentAteqEnable()
                         << "channel=" << CurWorkPar.channel;
            }
        }
        lastPlcOverallTesting = plcOverallTesting;

        if(preResetAction != NoPreResetAction){
            if(!b_gameover || B_BTN_EMC_ONE || B_BTN_EMC){
                preResetAction = NoPreResetAction;
                preResetCompletedForPendingBarcode = false;
                preScanResetWaitMs = 0;
                qDebug() << "[PLC] pre-scan reset canceled"
                         << "gameover=" << b_gameover
                         << "emergency=" << (B_BTN_EMC_ONE || B_BTN_EMC);
            }else{
                preScanResetWaitMs += 20;
                if(preScanResetWaitMs >= kPreScanResetWaitMs){
                    const ENM_PRE_RESET_ACTION completedAction = preResetAction;
                    preResetAction = NoPreResetAction;
                    preScanResetWaitMs = 0;
                    preResetCompletedForPendingBarcode = true;

                    bool hasPendingBarcode = false;
                    {
                        QMutexLocker locker(&m_barcodeMutex);
                        hasPendingBarcode = !pendingBarcode.isEmpty();
                    }

                    if(completedAction == TriggerScannerAfterPreReset && !hasPendingBarcode){
                        emit sign_init_Display();
                        emit m_Form_ScanCode->sign_WriteDatas(scanTriggerCommand());
                        setDetectionTimerActive(true);
                        detection_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_DetectionTime, m_color::Yellow);
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Yellow);
                        qDebug() << "[PLC] pre-scan reset finished, trigger scan";
                    }else if(completedAction == TriggerScannerAfterPreReset){
                        qDebug() << "[SCAN] pre-reset finished, pending direct barcode will be used";
                    }else{
                        qDebug() << "[SCAN] direct barcode pre-reset finished";
                    }
                }
            }
        }

        MTestingUiSnapshot acceptedSnapshot;
        QString acceptedBarcode;
        bool hasPendingBarcode = false;
        {
            QMutexLocker locker(&m_barcodeMutex);
            hasPendingBarcode = !pendingBarcode.isEmpty();
        }

        if(hasPendingBarcode && b_gameover && !B_BTN_EMC_ONE){
            if(preResetAction == NoPreResetAction && !preResetCompletedForPendingBarcode){
                m_ModbusRtu->requestAllReset();
                preResetAction = ProcessBarcodeAfterPreReset;
                preScanResetWaitMs = 0;
                qDebug() << "[SCAN] direct barcode received, pre-reset before processing";
            }else if(preResetAction == NoPreResetAction){
                acceptedBarcode = takePendingBarcode(&acceptedSnapshot);
                preResetCompletedForPendingBarcode = false;
            }
        }

        if(!acceptedBarcode.isEmpty() && b_gameover && !B_BTN_EMC_ONE){

            Q_UNUSED(acceptedSnapshot);
            b_gameover = false;
            resetLeakCycleState();
            emit sign_init_Display();
            emit Sign_SetlineEdit(MFormJLStation::mutualUi->ui->LE_ProductCode, currentBarcode);
            b_onSite = true;
            v_Step_JL = ENM_STEP::WaitGetCode;
            v_Step_WorkModel = ENM_STEP_WORK_MODEL::Normal;
            B_Testing_Start = false;
            B_next_reset = false;
            CurWorkPar.Result_Pisitive = "";
            CurWorkPar.Result_Negative = "";
            if(!detectionTimerActive){
                setDetectionTimerActive(true);
                detection_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            }
            emit sign_setled(MFormJLStation::mutualUi->ui->led_DetectionTime, m_color::Yellow);
            emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Yellow);

        }/*else if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("到位")) == 0 && b_onSite){

            b_onSite = false;
            emit sign_setled(MFormJLStation::mutualUi->ui->led_Onsite, m_color::White);
            emit sign_init_Display();
        }*/

        if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("防错复位")) != 0 && !b_resetBtnDown_FC){
            b_resetBtnDown_FC = true;
            m_ModbusRtu->requestAllReset();
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 0);
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("红灯"), 0);

        }else if( (m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("防错复位")) == 0 &&  b_resetBtnDown_FC)  || B_Resset_Hand){

            B_BTN_EMC_ONE = false;
            B_next_reset = true;
            B_Resset_Hand = false;


            b_gameover = true;

            if(m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("启动检漏")) == 1){
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("启动检漏"), 0);
            }
            if(m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("检漏1复位")) == 1){
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏1复位") , 0);
            }else{
                b_resetBtnDown_FC = false;
                v_resetCount_FC = 0;
                v_Step_WorkModel = ENM_STEP_WORK_MODEL::Reset;
                v_Step_JL_Reset = ENM_STEP::Exhaust;//从检漏仪排气开始
                b_onSite = false;
                if( CurWorkPar.Result_Pisitive == "" ){
                    CurWorkPar.Result_Pisitive = "NG";
                }
                if( CurWorkPar.Result_Negative == "" ){
                    CurWorkPar.Result_Negative = "NG";
                }
            }
        }

        if(B_BTN_EMC_ONE){
            continue;
        }

        if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("NG料光栅")) != 0 && !B_grating_btn){
            B_grating_btn = true;
        }else if( m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("NG料光栅")) == 0 && B_grating_btn){

            B_grating_btn = false;
            B_need_grating = false;
        }

        if(ENM_STEP_WORK_MODEL::Normal == v_Step_WorkModel){
            Step_JL();
        }else if(ENM_STEP_WORK_MODEL::Reset == v_Step_WorkModel || ENM_STEP_WORK_MODEL::HandReset == v_Step_WorkModel){
            Step_JL_Reset();
        }
    }
}

/**
 * @brief mWorkTask::Step_JL    正常检漏步骤
 */
void mWorkTask::Step_JL()
{
    //判断检漏设备报警
    if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("R端NG1")) == 1 || m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("T端NG1")) == 1
            || m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("报警1")) == 1){
        v_EQ_JL_Error = -1;
    }else if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("R端NG1")) == 0 && m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("T端NG1")) == 0
             && m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("报警1")) == 0){
        v_EQ_JL_Error = 1;
    }

    if(ENM_STEP::NE == v_Step_JL){


    }else if(ENM_STEP::Onsite == v_Step_JL){

        B_next_reset = false;
        setDetectionTimerActive(true);
        clearCurrentBarcode();

        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏排气阀"), 0);
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("启动检漏"), 0);
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏1复位"), 0);
        setTowerLight(false, true, false);
        v_Step_JL = ENM_STEP::GetCode;
        emit sign_setled(MFormJLStation::mutualUi->ui->led_DetectionTime, m_color::Yellow);

    }else if(ENM_STEP::GetCode == v_Step_JL){//触发条码

        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 0);
        QByteArray send_byte;
        send_byte.append(0x16);
        send_byte.append(0x54);
        send_byte.append(0x0D);
        emit m_Form_ScanCode->sign_WriteDatas(send_byte);
        AutoPrintLabel_BeginCountTime();

        v_Step_JL = ENM_STEP::WaitGetCode;
        emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Yellow);
        qDebug()<<"触发条码";
        detection_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    }else if(ENM_STEP::WaitGetCode == v_Step_JL){//获取芯体条码

        if(!currentBarcode.isEmpty()){
            emit Sign_SetlineEdit(MFormJLStation::mutualUi->ui->LE_ProductCode, currentBarcode);
            AutoPrintLabel_EndCountTime();
            qDebug()<<"获取条码"<<currentBarcode;
            CurWorkPar.JL_Data.clear();
            CurWorkPar.JL_Data_1.clear();
            CurWorkPar.JL_Data_2.clear();

            if(lastProcutCode != currentBarcode && lastProductResult != "OK" && B_need_grating){
                //不同产品检测，且上一个是检测NG的
                emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                setDetectionTimerActive(false);
                b_gameover = true;
                clearCurrentBarcode();
            }else{

                if(lastProcutCode == currentBarcode){
                    B_need_grating = false;
                }
                lastProcutCode = currentBarcode;
                //检测产品不一样，且上个产品为不合格
                if(!B_need_grating || !MFormJLStation::mutualUi->needPlaceNgProductChecked()){
                    //不需要放置到光栅
                    int8_t v_error = -1;
                    if(CurWorkPar.list_Codes_set.size() == 0){
                        v_error = 0;
                    }else{
                        if(currentBarcode.contains(CurWorkPar.list_Codes_set.first())){

                            qDebug() << "条码长度,规则" << currentBarcode << currentBarcode.size() << CurWorkPar.list_Codes_set.first() << CurWorkPar.list_Codes_length.first();

                            emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Yellow);
                            if( (currentBarcode.size() == CurWorkPar.list_Codes_length.first() && CurWorkPar.list_Codes_length.first() > 0) || (CurWorkPar.list_Codes_length.first() == 0)){
                                v_error = 0;
                            }else{
                                v_error = -1;
                                qDebug() << "条码长度不匹配" << currentBarcode.size() << CurWorkPar.list_Codes_length.first();
                            }
                        }else{
                            emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                            v_error = -1;
                            qDebug() << "条码规则不匹配" << currentBarcode << CurWorkPar.list_Codes_set.first();
                        }
                    }
                    if(v_error != -1){
                        if(!currentAteqValid()){
                            qDebug() << "[PLC] barcode accepted but ATEQ enable invalid" << currentAteqEnable();
                            b_gameover = true;
                            setDetectionTimerActive(false);
                            emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                            emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Red);
                            v_Step_JL = ENM_STEP::NE;
                            clearCurrentBarcode();
                            return;
                        }
                        if( !CurWorkPar.Check_Pisitive  ){
                            CurWorkPar.Result_Pisitive = "OK";
                        }
                        if( !CurWorkPar.Check_Negative ){
                            CurWorkPar.Result_Negative = "OK";
                        }
                        v_Step_JL_Check = ENM_CHANNEL::Pisitive;
                        const bool productWriteOk = m_ModbusRtu->writeCurrentProductWords();
                        qDebug() << "[PLC] 扫码通过，立即写 D1902/D1903 =" << productWriteOk;
                        {
                            QMutexLocker locker(&m_leakCycleMutex);
                            productReadyWaitMs = 0;
                            leakStartRequested = false;
                        }
                        setTowerLight(true, false, false);
                        v_Step_JL = ENM_STEP::StartJL;
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Green);
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Yellow);
                    }else{
                        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 1);
                        b_gameover = true;
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::Red);
                        v_Step_JL = ENM_STEP::NE;
                        clearCurrentBarcode();
                        //                v_Step_JL_Reset = ENM_STEP::WaitGetCode;    //复位的时候，扫码开始
                    }
                }else{
                    clearCurrentBarcode();
                }
            }
        }
    }else if(ENM_STEP::PressDown == v_Step_JL){//对插下降

        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸上升"), 0);
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸下压"), 1);
        AutoPrintLabel_BeginCountTime();
        v_Step_JL = ENM_STEP::WaitPressDown;
//        emit sign_setled(MFormJLStation::mutualUi->ui->led_LockProduct, m_color::Yellow);
        v_Step_JL_Reset = ENM_STEP::Exhaust;    //复位的时候，从排气开始
        qDebug()<<"对插";

    }else if(ENM_STEP::WaitPressDown == v_Step_JL){//等待气缸下限位

        if(mStruct_AutoPrintLabel.v_rec_timeout_100ms > 30){
//            emit sign_setled(MFormJLStation::mutualUi->ui->led_LockProduct, m_color::Green);
//            v_Step_JL = ENM_STEP::StartJL;
            setTowerLight(true, false, false);
            v_Step_JL = ENM_STEP::StartJL;
//            AutoPrintLabel_BeginCountTime();
        }
    }else if( ENM_STEP::Channels == v_Step_JL ){
            const bool productWriteOk = m_ModbusRtu->writeCurrentProductWords();
            {
                QMutexLocker locker(&m_leakCycleMutex);
                productReadyWaitMs = 0;
                leakStartRequested = false;
            }
            qDebug() << "[PLC] legacy Channels step bypassed, sync D1902/D1903 =" << productWriteOk;
            setTowerLight(true, false, false);
            v_Step_JL = ENM_STEP::StartJL;
            return;
            if( !CurWorkPar.Check_Pisitive  ){
                CurWorkPar.Result_Pisitive = "OK";
            }
            if( !CurWorkPar.Check_Negative ){
                CurWorkPar.Result_Negative = "OK";
            }

            uint8_t channel;
            if( CurWorkPar.Check_Pisitive && CurWorkPar.Result_Pisitive == "" ){
                v_Step_JL_Check = ENM_CHANNEL::Pisitive;
                channel = CurWorkPar.Channel_Pisitive - 1;

            }else if( CurWorkPar.Check_Negative && CurWorkPar.Result_Negative == "" ){
                v_Step_JL_Check = ENM_CHANNEL::Negative;
                channel = CurWorkPar.Chanel_Negative - 1;
            }else{
                v_Step_JL_Check = ENM_CHANNEL::Pisitive;
                channel = 0;
            }
            if( m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("切换程序Bit0")) == static_cast<uint8_t>(MFuntions::checkBit(channel, 0)) &&
                m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("切换程序Bit1")) == static_cast<uint8_t>(MFuntions::checkBit(channel, 1)) &&
                m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("切换程序Bit2")) == static_cast<uint8_t>(MFuntions::checkBit(channel, 2)) &&
                m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("切换程序Bit3")) == static_cast<uint8_t>(MFuntions::checkBit(channel, 3)) &&
                m_ModbusRtu->Wdata.value(mS_BSMIO.IO_XY.value("切换程序Bit4")) == static_cast<uint8_t>(MFuntions::checkBit(channel, 4)))
            {
                qDebug()<<"切换频道成功";
//                v_Step_JL = ENM_STEP::StartJL;
                setTowerLight(true, false, false);
                v_Step_JL = ENM_STEP::StartJL;
                AutoPrintLabel_BeginCountTime();
            }else{
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("切换程序Bit0") , static_cast<uint8_t>(MFuntions::checkBit(channel, 0)));
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("切换程序Bit1") , static_cast<uint8_t>(MFuntions::checkBit(channel, 1)));
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("切换程序Bit2") , static_cast<uint8_t>(MFuntions::checkBit(channel, 2)));
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("切换程序Bit3") , static_cast<uint8_t>(MFuntions::checkBit(channel, 3)));
                m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("切换程序Bit4") , static_cast<uint8_t>(MFuntions::checkBit(channel, 4)));
            }
    }else if ( ENM_STEP::Wait_Start == v_Step_JL ){
        if(!m_ModbusRtu->plcOverallTesting()){
            return;
        }
        setTowerLight(true, false, false);
        v_Step_JL = ENM_STEP::JudgeResult;
        emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Yellow);
        AutoPrintLabel_BeginCountTime();
        qDebug() << "[PLC] confirmed D1901 bit1 testing, wait leak result";
    }else if(ENM_STEP::StartJL == v_Step_JL){
        if(!leakStartRequested){
            qDebug() << "[PLC] skip product channel confirm, start leak"
                     << "softwareChannel=" << m_ModbusRtu->currentProductWord()
                     << "ATEQ=" << currentAteqEnable()
                     << "D90=" << m_ModbusRtu->plc_D90
                     << "D91=" << m_ModbusRtu->plc_D91
                     << "D1902=" << m_ModbusRtu->plc_D1902
                     << "D1903=" << m_ModbusRtu->plc_D1903;

            setTowerLight(true, false, false);
            m_ModbusRtu->requestLeakStart();
            leakStartRequested = true;
            AutoPrintLabel_BeginCountTime();
        }else if(mStruct_AutoPrintLabel.v_rec_timeout_100ms > 20){
            v_Step_JL = ENM_STEP::JudgeResult;
            emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Yellow);
        }
    }else if(ENM_STEP::JudgeResult == v_Step_JL){
            bool needLatchPlcResult = false;
            {
                QMutexLocker locker(&m_leakCycleMutex);
                needLatchPlcResult = !plcLeakResultLatched;
            }
            if(needLatchPlcResult){
                int ateqEnableForResult = 0;
                {
                    QMutexLocker locker(&m_leakCycleMutex);
                    ateqEnableForResult = cycleAteqEnable;
                    if(ateqEnableForResult < 1 || ateqEnableForResult > 3){
                        ateqEnableForResult = currentAteqEnable();
                        cycleAteqEnable = ateqEnableForResult;
                    }
                }
                const bool overallHasResult = m_ModbusRtu->plcOverallHasResult();
                const bool overallResult = m_ModbusRtu->plcOverallResult();
                const bool leak1HasResult = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 6);
                const bool leak1Result = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 7);
                const bool leak2HasResult = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 9);
                const bool leak2Result = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 10);

                const auto displayPlcResult = [this](bool secondItem, bool ok) {
                    QLabel *pressure = secondItem ? MFormJLStation::mutualUi->ui->led_Detection_Pressure_2
                                                  : MFormJLStation::mutualUi->ui->led_Detection_Pressure;
                    QLabel *leakage = secondItem ? MFormJLStation::mutualUi->ui->led_Leakage_value_2
                                                 : MFormJLStation::mutualUi->ui->led_Leakage_value;
                    QLabel *result = secondItem ? MFormJLStation::mutualUi->ui->led_JL_Result_2
                                                : MFormJLStation::mutualUi->ui->led_JL_Result;
                    const int color = ok ? m_color::Green : m_color::Red;

                    emit sign_set_text(result, ok ? "OK" : "NG");
                    emit sign_setled(pressure, color);
                    emit sign_setled(leakage, color);
                    emit sign_setled(result, color);
                };

                bool finalOk = false;
                if(ateqEnableForResult == 1){
                    if(!leak1HasResult){
                        return;
                    }
                    finalOk = leak1Result;
                    CurWorkPar.Result_Pisitive = leak1Result ? "OK" : "NG";
                    CurWorkPar.Result_Negative = "OK";
                    displayPlcResult(false, leak1Result);
                }else if(ateqEnableForResult == 2){
                    if(!leak2HasResult){
                        return;
                    }
                    finalOk = leak2Result;
                    CurWorkPar.Result_Pisitive = leak2Result ? "OK" : "NG";
                    CurWorkPar.Result_Negative = "OK";
                    displayPlcResult(false, leak2Result);
                }else if(ateqEnableForResult == 3){
                    if(!leak1HasResult || !leak2HasResult){
                        return;
                    }
                    finalOk = leak1Result && leak2Result;
                    CurWorkPar.Result_Pisitive = leak1Result ? "OK" : "NG";
                    CurWorkPar.Result_Negative = leak2Result ? "OK" : "NG";
                    displayPlcResult(false, leak1Result);
                    displayPlcResult(true, leak2Result);
                }else{
                    return;
                }

                v_Step_JL_Reset = ENM_STEP::Exhaust;

                qDebug() << "[PLC] selected leak result latched"
                         << "ok=" << finalOk
                         << "ATEQ=" << ateqEnableForResult
                         << "overallHasResult=" << overallHasResult
                         << "overallOk=" << overallResult
                         << "D1901=" << m_ModbusRtu->plc_D1901;

                {
                    QMutexLocker locker(&m_leakCycleMutex);
                    plcLeakResultLatched = true;
                    plcOverallResultOk = finalOk;
                    ateqDataWaitMs = 0;
                }
                setDetectionTimerActive(false);
                emit sign_setled(MFormJLStation::mutualUi->ui->led_Result,
                                 finalOk ? m_color::Green : m_color::Red);
                setTowerLight(false, finalOk, !finalOk);
                if(!finalOk){
                    v_EQ_JL_Error = -1;
                }
            }

            // Keep PLC physical reset latch state after leak result.
            // Do not issue the D1900.4 all-reset pulse automatically on cycle finish.
            if(requiredAteqDataReceived()){
                finishLeakCycleAfterResult();
                return;
            }

            int ateqWaitSnapshot = 0;
            int ateqEnableSnapshot = 0;
            bool ateq1Snapshot = false;
            bool ateq2Snapshot = false;
            {
                QMutexLocker locker(&m_leakCycleMutex);
                ateqDataWaitMs += 20;
                ateqWaitSnapshot = ateqDataWaitMs;
                ateqEnableSnapshot = cycleAteqEnable;
                ateq1Snapshot = ateq1DataReceived;
                ateq2Snapshot = ateq2DataReceived;
            }
            if(ateqWaitSnapshot >= kAteqDataTimeoutMs){
                qDebug() << "[ATEQ] wait data timeout"
                         << "enable=" << ateqEnableSnapshot
                         << "ateq1=" << ateq1Snapshot
                         << "ateq2=" << ateq2Snapshot;
                if(plcOverallResultOk){
                    qDebug() << "[ATEQ] timeout after PLC OK, finish with missing ATEQ data";
                    emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Green);
                    setTowerLight(false, true, false);
                }else{
                    qDebug() << "[ATEQ] timeout after PLC NG, finish with missing ATEQ data";
                    emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Red);
                    setTowerLight(false, false, true);
                    v_EQ_JL_Error = -1;
                }
                finishLeakCycleAfterResult();
                return;
            }
            return;
            if(!m_ModbusRtu->plcSelectedLeakHasResult()){
                return;
            }

            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("启动检漏"), 0);
            v_Step_JL_Reset = ENM_STEP::Exhaust;

            const int ateqEnable = currentAteqEnable();
            const bool leak1Result = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 7);
            const bool leak2Result = mModbusRtu::getBit(m_ModbusRtu->plc_D1901, 10);
            bool finalOk = true;

            const auto displayPlcResult = [this](bool secondItem, bool ok) {
                QLabel *pressure = secondItem ? MFormJLStation::mutualUi->ui->led_Detection_Pressure_2
                                              : MFormJLStation::mutualUi->ui->led_Detection_Pressure;
                QLabel *leakage = secondItem ? MFormJLStation::mutualUi->ui->led_Leakage_value_2
                                             : MFormJLStation::mutualUi->ui->led_Leakage_value;
                QLabel *result = secondItem ? MFormJLStation::mutualUi->ui->led_JL_Result_2
                                            : MFormJLStation::mutualUi->ui->led_JL_Result;
                const int color = ok ? m_color::Green : m_color::Red;

                emit sign_set_text(result, ok ? "OK" : "NG");
                emit sign_setled(pressure, color);
                emit sign_setled(leakage, color);
                emit sign_setled(result, color);
            };

            if(ateqEnable == 1){
                finalOk = leak1Result;
                CurWorkPar.Result_Pisitive = leak1Result ? "OK" : "NG";
                CurWorkPar.Result_Negative = "OK";
                displayPlcResult(false, leak1Result);
            }else if(ateqEnable == 2){
                finalOk = leak2Result;
                CurWorkPar.Result_Pisitive = leak2Result ? "OK" : "NG";
                CurWorkPar.Result_Negative = "OK";
                displayPlcResult(false, leak2Result);
            }else if(ateqEnable == 3){
                finalOk = leak1Result && leak2Result;
                CurWorkPar.Result_Pisitive = leak1Result ? "OK" : "NG";
                CurWorkPar.Result_Negative = leak2Result ? "OK" : "NG";
                displayPlcResult(false, leak1Result);
                displayPlcResult(true, leak2Result);
            }else{
                finalOk = m_ModbusRtu->plcSelectedLeakResult();
                CurWorkPar.Result_Pisitive = finalOk ? "OK" : "NG";
                CurWorkPar.Result_Negative = "OK";
                displayPlcResult(false, finalOk);
            }

            v_Step_JL = ENM_STEP::Exhaust;
            v_Step_WorkModel = ENM_STEP_WORK_MODEL::Reset;
            if(finalOk){
                emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Green);
                setTowerLight(false, true, false);
            }else{
                v_EQ_JL_Error = -1;
                emit sign_setled(MFormJLStation::mutualUi->ui->led_Result, m_color::Red);
                setTowerLight(false, false, true);
            }
    }
}
/**
 * @brief mWorkTask::Step_JL_Reset  复位机构
 */
void mWorkTask::Step_JL_Reset()
{
    if(ENM_STEP::NE == v_Step_JL_Reset){

    }else if(ENM_STEP::WaitGetCode == v_Step_JL_Reset){

        emit sign_setled(MFormJLStation::mutualUi->ui->led_GetCodeOK, m_color::White);
        emit Sign_SetlineEdit(MFormJLStation::mutualUi->ui->LE_ProductCode, "");
        v_Step_JL_Reset = ENM_STEP::NE;

    }else if(ENM_STEP::Exhaust == v_Step_JL_Reset){//检漏仪排气
        qDebug()<<"开始排气";
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏排气阀"), 1);
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("启动检漏"), 0);
        AutoPrintLabel_BeginCountTime();
//        emit sign_setled(MFormJLStation::mutualUi->ui->led_Exhaust, m_color::Yellow);
        v_Step_JL_Reset = ENM_STEP::WaitExhaust;
    }else if(ENM_STEP::WaitExhaust == v_Step_JL_Reset){//等待排气完成

        if(mStruct_AutoPrintLabel.v_rec_timeout_100ms > 30){
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("检漏排气阀"), 0);
            AutoPrintLabel_EndCountTime();

//            emit sign_setled(MFormJLStation::mutualUi->ui->led_Exhaust, m_color::Green);
            bool plcNgLatched = false;
            {
                QMutexLocker locker(&m_leakCycleMutex);
                plcNgLatched = plcLeakResultLatched && !plcOverallResultOk;
            }
            const bool resultReady = (CurWorkPar.Result_Pisitive != "" && CurWorkPar.Result_Negative != "")
                    || plcNgLatched;
            if(resultReady){
                b_mainStationFin = true;

                if(B_next_reset){

                }else{
                    if(!plcNgLatched && CurWorkPar.Result_Pisitive == "OK" && CurWorkPar.Result_Negative == "OK"){
                        setTowerLight(false, true, false);
                        qDebug() << "打印OK标签";
                        QString error_code;                        
                        emit sign_Printe_Label_OK(currentSnapshot.channel);
                        lastProcutCode = "";
                        lastProductResult = "OK";
                        emit sign_setled(MFormJLStation::mutualUi->ui->led_DetectionTime, m_color::Green);

                        SaveMysqlDatas(error_code);

                    }else{
                        QString error_code;
                        if(MFormJLStation::mutualUi->needPlaceNgProductChecked()){
                            B_need_grating = true;
                        }
                        if(plcNgLatched || CurWorkPar.Result_Pisitive == "NG" || CurWorkPar.Result_Negative == "NG"){
                            setTowerLight(false, false, true);
                            qDebug() << "打印NG标签";
                            lastProductResult = "NG";
                            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 1);
                            emit sign_Printe_Label_NG(currentSnapshot.channel, error_code);
                        }
                        SaveMysqlDatas(error_code);
                    }
                }

                v_Step_JL_Reset = ENM_STEP::NE;
                v_Step_WorkModel = ENM_STEP_WORK_MODEL::NE_WORK;
                b_onSite = false;
                setDetectionTimerActive(false);
                mStruct_AutoPrintLabel.v_rec_timeout_100ms = 0;
                b_gameover = true;
                clearCurrentBarcode();

            }else{
                qDebug() << "[PLC] reset finish without complete result, abort legacy Channels retry";
                v_EQ_JL_Error = -1;
                v_Step_JL = ENM_STEP::NE;
                v_Step_JL_Reset = ENM_STEP::NE;
                v_Step_WorkModel = ENM_STEP_WORK_MODEL::NE_WORK;
                b_gameover = true;
                clearCurrentBarcode();
            }
        }

    }else if(ENM_STEP::Loosen == v_Step_JL_Reset){//气缸上升
        //对插上升
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸下压"), 0);
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("气缸上升"), 1);
        AutoPrintLabel_BeginCountTime();
//        emit sign_setled(MFormJLStation::mutualUi->ui->led_Loosen, m_color::Yellow);
        v_Step_JL_Reset = ENM_STEP::WaitLoosen;

    }else if(ENM_STEP::WaitLoosen == v_Step_JL_Reset){//等待气缸上限位
        //等待气缸上升信号
        if(mStruct_AutoPrintLabel.v_rec_timeout_100ms > 20){
//            qDebug() << "气缸上升超时";
//            AutoPrintLabel_EndCountTime();
//            emit sign_setled(MFormJLStation::mutualUi->ui->led_Loosen, m_color::Red);

//        }else if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("气缸上限位")) == 1 && m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("气缸下限位")) == 0){

            AutoPrintLabel_EndCountTime();
            v_Step_JL_Reset = ENM_STEP::NE;
//            emit sign_setled(MFormJLStation::mutualUi->ui->led_Loosen, m_color::Green);
            b_onSite = false;
            setDetectionTimerActive(false);
            mStruct_AutoPrintLabel.v_rec_timeout_100ms = 0;
            mStruct_AutoPrintLabel.b_naijiu = true;

            b_gameover = true;
            clearCurrentBarcode();
        }

    }else{

    }
}
/**
 * @brief mWorkTask::SaveMysqlDatas 数据库
 */
void mWorkTask::SaveMysqlDatas(QString& errorInfo)
{
    qDebug() << "排布数据";
    MST_MYSQL_Datas mst_mysqlDatas;
    mst_mysqlDatas.batch = currentSnapshot.batch;
    mst_mysqlDatas.channel = currentSnapshot.channel;
    mst_mysqlDatas.eq_number = currentSnapshot.eq_number;
    mst_mysqlDatas.operator_id = currentSnapshot.operator_id;
    mst_mysqlDatas.product_code = currentSnapshot.product_code;
    mst_mysqlDatas.product_number = currentSnapshot.product_number;

    mst_mysqlDatas.testing_start_time = detection_time;
    mst_mysqlDatas.testing_finished_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString testingTime;
    QString testingResult;
    QString testingPressure;
    QString testingLeakage;
    QString testingResult2;
    QString testingPressure2;
    QString testingLeakage2;
    QString productCodePrint = currentSnapshot.product_code_print;

    if(MFormJLStation::mutualUi != nullptr){
        QMetaObject::invokeMethod(MFormJLStation::mutualUi, [&]() {
            testingTime = MFormJLStation::mutualUi->ui->led_DetectionTime->text();
            testingResult = MFormJLStation::mutualUi->ui->led_JL_Result->text();
            testingPressure = MFormJLStation::mutualUi->ui->led_Detection_Pressure->text();
            testingLeakage = MFormJLStation::mutualUi->ui->led_Leakage_value->text();
            testingResult2 = MFormJLStation::mutualUi->ui->led_JL_Result_2->text();
            testingPressure2 = MFormJLStation::mutualUi->ui->led_Detection_Pressure_2->text();
            testingLeakage2 = MFormJLStation::mutualUi->ui->led_Leakage_value_2->text();
            productCodePrint = MFormJLStation::mutualUi->ui->LE_ProductCode_Print->text();
        }, Qt::BlockingQueuedConnection);
    }

    mst_mysqlDatas.testing_time = testingTime;
    mst_mysqlDatas.testing_result = testingResult;
    mst_mysqlDatas.testing_pressuse = testingPressure;
    mst_mysqlDatas.testing_leackage_value = testingLeakage;
    mst_mysqlDatas.testing_result_2 = testingResult2;
    mst_mysqlDatas.testing_pressuse_2 = testingPressure2;
    mst_mysqlDatas.testing_leackage_value_2 = testingLeakage2;

    qDebug()<<"获取界面条码："<<productCodePrint;
    mst_mysqlDatas.product_code_print = productCodePrint;

    //项目1 正
    if(!CurWorkPar.Check_Pisitive){

    }else{
        if(CurWorkPar.Result_Pisitive != "OK"){
            errorInfo = tr("No1：[%1、%2]").arg(mst_mysqlDatas.testing_pressuse, mst_mysqlDatas.testing_leackage_value);
        }
    }
    //项目2 负
    if(!CurWorkPar.Check_Negative){

    }else{
        if(CurWorkPar.Result_Negative != "OK"){
            errorInfo = errorInfo + tr("No2：[%1、%2]").arg(mst_mysqlDatas.testing_pressuse_2, mst_mysqlDatas.testing_leackage_value_2);
        }
    }
    emit m_FormMysql->sign_update_JLDatas(mst_mysqlDatas);
    qDebug() << "开始保存数据库"<<mst_mysqlDatas.product_code_print;
}
void mWorkTask::WorkMain()//生产模式
{
//    CurStepItem = CurStepNames.at(WorkCur_step -1); //获取当前流程步骤

//    if( m_WorkTask->uc_Beep_EN[0] == 1 && uc_Beep_EN[1] == 4){
//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器"), 0);
//        m_WorkTask->uc_Beep_EN[0] = 0;
//        m_WorkTask->uc_Beep_EN[1] = 0;
//    }

//    if((CurStepItem == "") && b_workEn && !b_mainStationFin){

//        if(CurWorkPar.rfid_number == ""){
//            //无RFID时候等待
//            CurStepTips = "当前工位已完成操作，等待RFID保存数据";
//            return;
//        }
//        //操作完成判断
//        b_mainStationFin = true;
//        Bool_CT_Count = false;
//        b_saveFin = false;

//        SaveFile();

//        emit sign_setled_Frame(MFormJLStation::mutualUi->ui->led_stationOk, m_color::Green);

//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("绿灯"), 1);
//        uc_Beep_EN[0] = 1;
//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("防误OK"), 1);
//        emit Sign_TipsN( "完成生产模式");
//    }
}

void mWorkTask::SaveFile()//保存完成数据
{
//    CurWorkPar.us_screws[0] = 0;
//    CurWorkPar.us_screws[1] = 0;
//    for(int i=0; i<20; i++){
//        if(CurStepNames.at(i).contains("电批1")){
//            CurWorkPar.us_screws[0] += FinCount[i];
//        }else if(CurStepNames.at(i).contains("电批2")){
//            CurWorkPar.us_screws[1] += FinCount[i];
//        }else if(CurStepNames.at(i) == "")
//            break;
//    }
//    QStringList FinNum;
//    for(int i=0; i<20; i++)
//        FinNum << QString::number(FinCount[i]);

//    //获取组装状态
//    uchar uc_staion_state = 1;
//    if(CurWorkPar.B_Manual_NG){
//        uc_staion_state = 0;
//    }else{
//        uc_staion_state = (int)b_mainStationFin;
//    }

//    //备注
//    QString Mysql_tips = "";
//    //保存到数据库
//    QStringList list_MYSQL_Datas;

//    QString EndData = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//    MFormJLStation::mutualUi->ui->led_Time_Finish->setText(EndData);

//    list_MYSQL_Datas
//            << CurWorkPar.rfid_number
//            << CurWorkPar.channel
//            << CurWorkPar.product_name
//            << result_id_name.at(uc_staion_state)
//            << BeginData
//            << EndData
//            << ""
//            << QString::number(CurWorkPar.us_screws[0])
//            << QString::number(CurWorkPar.us_screws[1])
//            << CurWorkPar.IV_hostoryResult.join("、")
//            << CurWorkPar.uplineCode
//            << CurWorkPar.list_QRCode.at(0)
//            << CurWorkPar.list_QRCode.at(1)
//            << CurWorkPar.list_QRCode.at(2)
//            << CurWorkPar.list_QRCode.at(3)
//            << CurWorkPar.list_QRCode.at(4)
//            << CurWorkPar.list_QRCode.at(5);

//    emit sign_RecordDatas(list_MYSQL_Datas);    //记录数据

//    b_saveFin = true;
//    qDebug() << "保存操作数据[" << CurWorkPar.rfid_number << "]";

}
//  ************************************************************************************************    工装到位

void mWorkTask::Onsite()
{
    setTowerLight(false, true, false);

    b_empty = false;
    b_saveFin = false;
    b_onSite = true;
    b_workEn = true;
    b_work_FC = true;
    b_mainStationFin = false;
//    led_Jump_Count = 0;

//    m_S_RFID_Datas.uc_again_get_RFID_A = 4;//首次执行获取RFID
//    m_S_RFID_Datas.B_need_Rfid_A = true;
//    m_S_RFID_Datas.uc_creatRFID_A = 1;//生成一次RFID

//    BeginData = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//    for(int i=0; i<CurWorkPar.list_QRCode.count(); i++){
//        CurWorkPar.list_QRCode[i] = "";
//    }
//    Bool_CT_Count = true;//CT计数使能
//    emit Sign_TipsN( "工装到位稳定");

//    emit sign_setled_cicular(MFormJLStation::mutualUi->ui->led_InPlace, m_color::Green);
//    emit sign_setled_Frame(MFormJLStation::mutualUi->ui->led_stationOk, m_color::Yellow);

//    WorkCur_step = 1;

//    if(CurStepNames.at(0) != ""){
//        emit sign_led_step(WorkCur_step -1, m_color::Yellow, "0", "");
//    }
//    emit sign_SetScandCode_Foucs();//到位置位光标到扫码区域

//    CurRepair.beginDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//    MFormJLStation::mutualUi->ui->led_Time_Begin->setText(BeginData);

}
//  ************************************************************************************************    到位信号消失
void mWorkTask::Offsite()
{
//    m_S_RFID_Datas.B_need_Rfid_A = false;

//    for(uint i=0; i<m_ModbusRtu->Wdata.valueCount(); i++){
//        m_ModbusRtu->Wdata.setValue(i, 0);
//    }

//    for(int i=0; i<20; i++)
//        FinCount[i] = 0;

//    led_Jump_Count = 0;
//    led_Jump_POS_Y = 0;
//    WorkCur_step = 1;
//    CurWorkPar.IV_hostoryResult.clear();
//    b_error_FC = false;
//    b_mainStationFin = false;
//    b_workEn = false;
//    b_work_FC = false;
//    b_onSite = false;
//    Bool_SaoMa_Fin = false;

//    for(int i=0; i<CurWorkPar.list_QRCode.count(); i++){
//        CurWorkPar.list_QRCode[i] = "";
//    }
//    Bool_CT_Count = false;

//    CurWorkPar.B_Manual_NG = false;//清除手动NG变量
//    CurWorkPar.kilews_value.clear();

//    CurRepair.uc_Need_Repair = 0;

////    if(CurWorkPar.rfid_number == ""){
////        emit Sign_TipsN("流水号空，不拷贝数据到总表");
////    }else{
////        emit sign_MYSQL_CopyDatas_OP(CurWorkPar.rfid_number);
////    }

//    emit sign_Init_NoBord();

//    b_QG_Locked = false;
//    CurStepItem = "";
//    CurStepTips = "";

//    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("黄灯"), 1);
//    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("绿灯"), 0);
//    m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("红灯"), 0);
//    emit Sign_TipsN("工装离开");
}

void mWorkTask::ResetKind(const int num)                                                        //复位
{
//    if(m_ModbusRtu == nullptr){
//        return;
//    }

//    if(num < 30){// 单工序复位
//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("红灯"), 0);
//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器"), 0);

//    }else if(num >=30){// 全工序复位,只留黄灯
//        emit sign_Clear_MainW();
//        for(uint i=0; i<m_ModbusRtu->Wdata.valueCount(); i++){
//            m_ModbusRtu->Wdata.setValue(i, 0);
//        }

//        for(int i=0; i<20; i++)
//            FinCount[i] = 0;

//        WorkCur_step = 1;
//        led_Jump_Count = 0;
//        led_Jump_POS_Y = 0;
//        CurWorkPar.IV_hostoryResult.clear();
//        CurWorkPar.FYW_Count = 0;

//        if(b_onSite){
//            emit sign_setled_Frame(MFormJLStation::mutualUi->ui->led_stationOk, m_color::Yellow);
//        }
//    }
//    if(b_workEn){
//        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("绿灯"), 1);
//    }
//    Bool_SaoMa_Fin = false;
//    b_mainStationFin = false;
//    emit sign_led_step(WorkCur_step-1, m_color::Yellow, "0", "");

}

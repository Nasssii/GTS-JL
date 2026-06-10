#include "MFormJLStation.h"
#include "ui_MFormJLStation.h"
#include <QEvent>


QString lastProcutCode;
QString lastProductResult = "OK";
bool B_Testing_Start = false;//软起动
QString Language = "CN";
MFormJLStation *MFormJLStation::mutualUi = nullptr;

namespace {
const int kPlcLogicalStationNumber = 1;

void InitPlcActUtlType(QWidget *parent)
{
    if(Act_Type_PLC_1 != nullptr){
        return;
    }

    Act_Type_PLC_1 = new ActUtlTypeLib::ActUtlType(parent);
    if(Act_Type_PLC_1->isNull()){
        qDebug() << "[PLC] ActUtlType control init failed";
        delete Act_Type_PLC_1;
        Act_Type_PLC_1 = nullptr;
        return;
    }

    Act_Type_PLC_1->SetActLogicalStationNumber(kPlcLogicalStationNumber);
    int ret = Act_Type_PLC_1->Open();
    qDebug() << "[PLC] Open ret =" << ret
             << "station =" << kPlcLogicalStationNumber;

    if(ret != 0){
        Act_Type_PLC_1->Close();
        delete Act_Type_PLC_1;
        Act_Type_PLC_1 = nullptr;
    }
}
}

MFormJLStation::MFormJLStation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MFormJLStation)
{
    ui->setupUi(this);
    mutualUi = this;

    setWindowTitle("V20260320");
    ui->BTN_IO->setEnabled(false);
    ui->BTN_ScanCode->setEnabled(false);
    ui->BTN_MFormLabel->setEnabled(false);
    ui->BTN_ATEQ->setEnabled(false);
    ui->BTN_MFormMYSQL->setEnabled(false);

    showMaximized();

    m_FormLogin = new MFormLogin(this);

    load_File_INI();

    m_Form_ProductTips = new MForm_ProductTips();

    connect(ptimer, &QTimer::timeout, this, &MFormJLStation::slot_ClockTimeout);
    m_Form_PrintSetting = new MForm_PrintSetting();

    m_MFormWorkStep = new MFormWorkStep();
    m_MFormWorkStep->ui->horizontalLayout_3->addWidget(m_Form_PrintSetting);

    m_Form_ScanCode = new MForm_ScanCode();

    m_WorkTask = new mWorkTask();
    connect(m_Form_ScanCode, &MForm_ScanCode::sign_barcodeReceived,
            this, &MFormJLStation::slot_onBarcodeReceived);
    connect(m_Form_ScanCode, &MForm_ScanCode::sign_scanWriteFailed,
            this, &MFormJLStation::slot_onScanWriteFailed);
    connect(m_WorkTask,&mWorkTask::sign_init_Display,this,&MFormJLStation::slot_init_Display);
    connect(m_WorkTask,&mWorkTask::sign_applyManualResetUi,this,&MFormJLStation::applyManualResetUi);
    connect(m_WorkTask, &mWorkTask::sign_setled, this, &MFormJLStation::slot_setled);
    connect(m_WorkTask, &mWorkTask::sign_setled_cicular, this, &MFormJLStation::slot_setled_cicular);
    connect(m_WorkTask, &mWorkTask::sign_set_text, this, &MFormJLStation::slot_set_text);
    connect(m_WorkTask, &mWorkTask::Sign_SetlineEdit, this, &MFormJLStation::slot_set_lineEdit);
    connect(m_WorkTask, &mWorkTask::sign_setTimeFlag, this, &MFormJLStation::slot_setTimeFlag);
    connect(m_WorkTask, &mWorkTask::sign_clearDisplayData, this, &MFormJLStation::slot_ClearDisplayData);
    connect(m_WorkTask, &mWorkTask::sign_set_leakvalue, m_Form_PrintSetting, &MForm_PrintSetting::slot_set_leakvalue);
    connect(m_WorkTask, &mWorkTask::sign_Printe_Label_OK, m_Form_PrintSetting, &MForm_PrintSetting::slot_Printe_Label_OK,Qt::BlockingQueuedConnection);
    connect(m_WorkTask, &mWorkTask::sign_Printe_Label_NG, m_Form_PrintSetting, &MForm_PrintSetting::slot_Printe_Label_NG);
    connect(m_WorkTask->pthread,&QThread::started,m_WorkTask,&mWorkTask::WorkTask);

    InitPlcActUtlType(this);
    m_Form_ModeBusRtu = new  MForm_ModeBusRtu();
    m_FormATEQ = new MFormATEQ();
    connect(m_COMLeakHunting, &COMLeakHunting::sign_ATEQ_Display,
            this, &MFormJLStation::slot_updateAteqDisplay);
    connect(m_COMLeakHunting_2, &COMLeakHunting_2::sign_ATEQ_Display,
            this, &MFormJLStation::slot_updateAteqDisplay);

    m_FormMysql = new MFormMysql();
    ptimer->start(100);
    m_WorkTask->pthread->start();

    if(Language == "CN"){
        ui->CBT_Language->setCurrentText("中文");
    }else if(Language == "EN"){
        ui->CBT_Language->setCurrentText("English");
    }
    ui->CBT_Channel->setCurrentText(_channel);
    ui->LB_productnumber->installEventFilter(this);
    ui->LE_Product_Number->installEventFilter(this);
    ui->label_7->hide();
    ui->logo->hide();
    ui->LE_ProductCode_Print->hide();
    ui->led_Loosen->hide();
    ui->led_Exhaust->hide();
    ui->led_LockProduct->hide();
    ui->BTN_Start->hide();
    ui->BTN_Reset->show();
    ui->LB_EMC_Stop->hide();
    ui->led_EMC_Stop->hide();
    ui->groupBox_2->hide();
     ui->BTN_IO->hide();
    m_needPlaceNgProductChecked.store(ui->BTN_NeedPlaceNGProduct->isChecked());
}

MFormJLStation::~MFormJLStation()
{
    delete ui;
}

bool MFormJLStation::eventFilter(QObject *watched, QEvent *event)
{
    if((watched == ui->LB_productnumber || watched == ui->LE_Product_Number)
            && event->type() == QEvent::MouseButtonDblClick){
        if(m_Form_ModeBusRtu != nullptr){
            m_Form_ModeBusRtu->show();
            m_Form_ModeBusRtu->raise();
            m_Form_ModeBusRtu->activateWindow();
            qDebug() << "[PLC] hidden monitor opened";
        }
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}
/**
 * @brief MFormJLStation::slot_ClockTimeout 定时器
 */

int time_num = 0;

void MFormJLStation::slot_ClockTimeout()
{
    if(mStruct_AutoPrintLabel.b_rec_count_en){
        if(mStruct_AutoPrintLabel.v_rec_timeout_100ms < 1200){
            mStruct_AutoPrintLabel.v_rec_timeout_100ms ++;
        }
    }
//    else if( mStruct_AutoPrintLabel.b_naijiu ){
//        mStruct_AutoPrintLabel.v_rec_timeout_100ms ++;
//        if( mStruct_AutoPrintLabel.v_rec_timeout_100ms > 100 ){
//            mStruct_AutoPrintLabel.v_rec_timeout_100ms = 0;
//            mStruct_AutoPrintLabel.b_naijiu = false;
//            ui->BTN_Start->click();
//        }
//    }
    if( time_flag ){
        time_num++;
        if( time_num > 10 ){
            int num = time_num/10;
            if( QString::number(num) != ui->led_DetectionTime->text()){
                ui->led_DetectionTime->setText(QString::number(num));
            }
        }
    }else{
        time_num = 0;
    }

    if(m_MFormWorkStep != nullptr && m_MFormWorkStep->ui != nullptr){
        ui->groupBox_2->setVisible(m_MFormWorkStep->ui->Cbt_ATEQ_Enable->currentIndex() == 3);
    }

    if(m_WorkTask->B_BTN_EMC){
        time_flag = false;
        m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 1);
    }
    //NG料车
    if(m_WorkTask->B_need_grating){
        if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("光栅")) == 0){
            B_BTN_grating = false;
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("蜂鸣器") , 0);
            m_ModbusRtu->Wdata.setValue(mS_BSMIO.IO_XY.value("红灯") , 0);
        }else if(m_ModbusRtu->recDatasDi.value(mS_BSMIO.IO_XY.value("光栅")) == 1 && !B_BTN_grating){
            B_BTN_grating = true;
            m_WorkTask->B_need_grating = false;
        }
        m_Form_ProductTips->show();
    }else{
        m_Form_ProductTips->hide();
    }
}

/**
 * @brief MFormJLStation::on_BTN_IO_clicked
 */
void MFormJLStation::on_BTN_IO_clicked()
{
    m_Form_ModeBusRtu->show();
}

/**
 * @brief MFormJLStation::on_BTN_ATEQ_clicked
 */
void MFormJLStation::on_BTN_ATEQ_clicked()
{
    m_FormATEQ->show();
}
/**
 * @brief MainWindow::slot_setled
 * @param label
 * @param color
 */
void MFormJLStation::slot_setled(QLabel *label, const int color)
{
    if(label == nullptr || color < 0 || color >= mColorName.size()){
        return;
    }
    QString sheet = mColorName.at(color);
    label->setStyleSheet(sheet);
}
/**
 * @brief MainWindow::slot_setled_cicular
 * @param label
 * @param color
 */
void MFormJLStation::slot_setled_cicular(QLabel *label, const int color)
{
    if(label == nullptr || color < 0 || color >= mColorName.size()){
        return;
    }
    QString sheet = mColorName.at(color);
    sheet += QString("border-radius: %1px;").arg(label->width() / 2);
    sheet += "border: 1px solid black;";
    label->setStyleSheet(sheet);
}

void MFormJLStation::slot_set_text(QLabel *label, const QString text)
{
    if(label == nullptr){
        return;
    }
    label->setText(text);
}

bool MFormJLStation::needPlaceNgProductChecked() const
{
    return m_needPlaceNgProductChecked.load();
}

void MFormJLStation::slot_updateAteqDisplay(int device, const QString &pressure, const QString &leakage)
{
    if(m_WorkTask == nullptr){
        return;
    }

    const int ateqEnable = (m_MFormWorkStep != nullptr && m_MFormWorkStep->ui != nullptr)
            ? m_MFormWorkStep->ui->Cbt_ATEQ_Enable->currentIndex()
            : 0;

    bool secondItem = false;
    bool shouldDisplay = false;

    if(ateqEnable == 1 && device == 1){
        shouldDisplay = true;
    }else if(ateqEnable == 2 && device == 2){
        shouldDisplay = true;
    }else if(ateqEnable == 3){
        shouldDisplay = (device == 1 || device == 2);
        secondItem = (device == 2);
    }

    if(!shouldDisplay){
        return;
    }

    if(!m_WorkTask->acceptAteqData(device, pressure, leakage)){
        return;
    }

    QLabel *pressureLabel = secondItem ? ui->led_Detection_Pressure_2 : ui->led_Detection_Pressure;
    QLabel *leakageLabel = secondItem ? ui->led_Leakage_value_2 : ui->led_Leakage_value;

    pressureLabel->setText(pressure);
    leakageLabel->setText(leakage);

    if(!secondItem && m_Form_PrintSetting != nullptr){
        m_Form_PrintSetting->slot_set_leakvalue(leakage);
    }
}

/**
 * @brief MFormJLStation::slot_ClearDisplayData  清除显示数据
 */
void MFormJLStation::slot_ClearDisplayData()
{
    ui->led_Leakage_value->setText("0.0");
    ui->led_DetectionTime->setText("0.0");
    ui->led_Detection_Pressure->setText("0.0");
    ui->led_JL_Result->setText("#");
}
/**
 * @brief MFormJLStation::on_BTN_MFormLabel_clicked 标签界面
 */
void MFormJLStation::on_BTN_MFormLabel_clicked()
{
//    m_Form_PrintSetting->show();
    m_MFormWorkStep->show();
}
/**
 * @brief MFormJLStation::on_BTN_Start_clicked  启动
 */
void MFormJLStation::on_BTN_Start_clicked()
{
    if(m_WorkTask != nullptr && !m_WorkTask->b_gameover){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] start ignored, station busy";
        return;
    }

    if(!isChannelValid()){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] start ignored, channel empty";
        return;
    }

    slot_setled(ui->led_GetCodeOK, m_color::Yellow);
    triggerScanCode();
    qDebug() << "[SCAN] start button trigger scan";
}
/**
 * @brief MFormJLStation::on_BTN_Reset_clicked 复位
 */
void MFormJLStation::on_BTN_Reset_clicked()
{
    if(m_WorkTask == nullptr || m_ModbusRtu == nullptr){
        qDebug() << "[PLC] manual reset ignored, object null";
        return;
    }

    m_WorkTask->requestManualReset();
    applyManualResetUi();
    qDebug() << "[PLC] manual reset button clicked";
}
/**
 * @brief MFormJLStation::on_CBT_Channel_currentTextChanged 8421切换检漏程序
 * @param arg1
 */
void MFormJLStation::applyManualResetUi()
{
    time_flag = false;
    slot_init_Display();
    slot_setled(ui->led_GetCodeOK, m_color::White);
    slot_setled(ui->led_Result, m_color::White);
}

void MFormJLStation::on_CBT_Channel_currentTextChanged(const QString &arg1)
{
    if( arg1 == "" ){
        ui->frame->setEnabled(false);
        return;
    }
    on_BTN_Save_clicked();
    ui->frame->setEnabled(true);
    m_MFormWorkStep->ui->Channel->setCurrentText(arg1);
    int v_load = m_MFormWorkStep->Load_Work_ChannelPars(arg1);
    qDebug() << "加载成功标志：" << v_load;
    m_Form_PrintSetting->ui->CBT_Channel->setCurrentText(arg1);
    ui->LE_Product_Number->setText(CurWorkPar.project_name);
    CurWorkPar.channel = arg1;
    if(v_load > 0 && m_ModbusRtu != nullptr){
        const bool productWriteOk = m_ModbusRtu->writeCurrentProductWords();
        qDebug() << "[PLC] channel changed, sync product words =" << productWriteOk;
    }
}
/**
 * @brief MFormJLStation::init_Display
 */
void MFormJLStation::slot_init_Display()
{
    ui->led_GetCodeOK->setStyleSheet("");
    ui->led_LockProduct->setStyleSheet("");
    ui->led_Result->setStyleSheet("");
    ui->led_Exhaust->setStyleSheet("");
    ui->led_Loosen->setStyleSheet("");
    ui->LE_ProductCode->setText("");
    ui->led_Detection_Pressure->setStyleSheet("");
    ui->led_Detection_Pressure->setText("");
    ui->led_Leakage_value->setStyleSheet("");
    ui->led_Leakage_value->setText("");
    ui->led_JL_Result->setStyleSheet("");
    ui->led_JL_Result->setText("");
    ui->led_Detection_Pressure_2->setStyleSheet("");
    ui->led_Detection_Pressure_2->setText("");
    ui->led_Leakage_value_2->setStyleSheet("");
    ui->led_Leakage_value_2->setText("");
    ui->led_JL_Result_2->setStyleSheet("");
    ui->led_JL_Result_2->setText("");
    ui->led_DetectionTime->setStyleSheet("");
    ui->led_DetectionTime->setText("");
    ui->LE_ProductCode_Print->setText("");
}

bool MFormJLStation::isChannelValid() const
{
    const uint channel = ui->CBT_Channel->currentText().toUInt();
    return channel > 0 && channel <= 50;
}

bool MFormJLStation::triggerScanCode()
{
    QByteArray send_byte;
    send_byte.append(0x16);
    send_byte.append(0x54);
    send_byte.append(0x0D);
    emit m_Form_ScanCode->sign_WriteDatas(send_byte);
    return true;
}

MTestingUiSnapshot MFormJLStation::makeTestingSnapshot(const QString &barcode) const
{
    MTestingUiSnapshot snapshot;
    snapshot.product_code = barcode;
    snapshot.product_number = ui->LE_Product_Number->text();
    snapshot.eq_number = ui->LE_EQ_Number->text();
    snapshot.channel = ui->CBT_Channel->currentText();
    snapshot.batch = ui->LE_Batch->text();
    snapshot.operator_id = ui->LE_Operator_Code->text();
    snapshot.product_code_print = ui->LE_ProductCode_Print->text();
    return snapshot;
}

void MFormJLStation::slot_onBarcodeReceived(const QString &barcode)
{
    const QString code = barcode.trimmed();
    if(code.isEmpty()){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] ignored empty barcode";
        return;
    }

    ui->LE_ProductCode->setText(code);
    if(!isChannelValid()){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] barcode ignored, channel invalid" << code;
        return;
    }
    if(m_WorkTask == nullptr){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] barcode ignored, work task null" << code;
        return;
    }

    QString rejectReason;
    if(!m_WorkTask->acceptBarcode(code, makeTestingSnapshot(code), &rejectReason)){
        slot_setled(ui->led_GetCodeOK, m_color::Red);
        qDebug() << "[SCAN] barcode rejected:" << rejectReason << code;
        return;
    }

    slot_setled(ui->led_GetCodeOK, m_color::Yellow);
    qDebug() << "[SCAN] barcode accepted" << code;
}

void MFormJLStation::slot_onScanWriteFailed(const QString &reason)
{
    slot_setled(ui->led_GetCodeOK, m_color::Red);
    qDebug() << "[SCAN] trigger failed:" << reason;
}

void MFormJLStation::slot_set_lineEdit(QLineEdit *lineEdit, const QString text)
{
    if(lineEdit == nullptr){
        return;
    }
    lineEdit->setText(text);
}

void MFormJLStation::slot_setTimeFlag(bool enabled)
{
    time_flag = enabled;
}

void MFormJLStation::on_BTN_ScanCode_clicked()
{
    m_Form_ScanCode->show();
}

void MFormJLStation::on_BTN_MFormMYSQL_clicked()
{
    m_FormMysql->show();
}
/**
 * @brief MFormJLStation::getQPushButton    获取按钮对象名字和显示文本
 */
void MFormJLStation::download_Objects(const QString &arg1)
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + tr("/Language/%1_%2.ini").arg(objectName(), arg1), QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("QPushButton");
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    for(int i=0; i<buttons.size(); i++){
        INI_File->setValue(buttons.at(i)->objectName(), buttons.at(i)->text());
    }
    INI_File->endGroup();

    INI_File->beginGroup("QLabel");
    QList<QLabel*> labels = this->findChildren<QLabel*>();
    for(int i=0; i<labels.size(); i++){
        INI_File->setValue(labels.at(i)->objectName(), labels.at(i)->text());
    }
    INI_File->endGroup();

    INI_File->beginGroup("QGroupBox");
    QList<QGroupBox*> groupBox = this->findChildren<QGroupBox*>();
    for(int i=0; i<groupBox.size(); i++){
        INI_File->setValue(groupBox.at(i)->objectName(), groupBox.at(i)->title());
    }
    INI_File->endGroup();

    INI_File->destroyed();
}

/**
 * @brief MForm_ScanCode::getObject
 * @param arg1
 */
void MFormJLStation::upload_Objects(const QString &arg1)
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + tr("/Language/%1_%2.ini").arg(objectName(), arg1), QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    QStringList list_childkeys;

    INI_File->beginGroup("QPushButton");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QPushButton *object = this->findChild<QPushButton*>(name);
        if(object){
            object->setText(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->beginGroup("QLabel");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QLabel *object = this->findChild<QLabel*>(name);
        if(object){
            object->setText(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->beginGroup("QGroupBox");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QGroupBox *object = this->findChild<QGroupBox*>(name);
        if(object){
            object->setTitle(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->destroyed();
}

void MFormJLStation::on_BTN_Get_Object_clicked()
{
    download_Objects(Language);
    m_FormATEQ->download_Objects(Language);
    m_Form_ScanCode->download_Objects(Language);
    m_FormMysql->download_Objects(Language);
    m_Form_PrintSetting->download_Objects(Language);
    m_Form_ModeBusRtu->download_Objects(Language);
    m_MFormWorkStep->download_Objects(Language);
    m_Form_ProductTips->download_Objects(Language);
    m_FormLogin->download_Objects(Language);

}
/**
 * @brief MFormJLStation::on_CBT_Language_currentTextChanged    切换语言
 * @param arg1
 */
void MFormJLStation::on_CBT_Language_currentTextChanged(const QString &arg1)
{
    if("中文" == arg1){
        Language = "CN";

    }else if("English" == arg1){
        Language = "EN";
    }

    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->setValue("language", Language);
    INI_File->destroyed();

    upload_Objects(Language);
    m_FormATEQ->upload_Objects(Language);
    m_Form_ScanCode->upload_Objects(Language);
    m_FormMysql->upload_Objects(Language);
    m_Form_PrintSetting->upload_Objects(Language);
    m_Form_ModeBusRtu->upload_Objects(Language);
    m_MFormWorkStep->upload_Objects(Language);
    m_MFormWorkStep->upload_Objects(Language);
    m_Form_ProductTips->upload_Objects(Language);
    m_FormLogin->upload_Objects(Language);
}
/**
 * @brief MFormJLStation::load_File_INI
 */
void MFormJLStation::load_File_INI()
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    Language = INI_File->value("language", "CN").toString();

    ui->LE_Batch->setText(INI_File->value("LE_Batch").toString());
    ui->LE_EQ_Number->setText(INI_File->value("LE_EQ_Number").toString());
    ui->LE_Operator_Code->setText(INI_File->value("LE_Operator_Code").toString());

    _channel = INI_File->value("CBT_Channel").toString();
    CurWorkPar.channel = _channel;

    INI_File->destroyed();

}
/**
 * @brief MFormJLStation::on_BTN_Login_clicked  登录
 */
void MFormJLStation::on_BTN_Login_clicked()
{
    m_FormLogin->show();
}
void MFormJLStation::on_BTN_Save_clicked()
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->setValue("LE_EQ_Number", ui->LE_EQ_Number->text());
    INI_File->setValue("LE_Batch", ui->LE_Batch->text());
    INI_File->setValue("LE_Operator_Code", ui->LE_Operator_Code->text());
    INI_File->setValue("CBT_Channel", ui->CBT_Channel->currentText());

    INI_File->destroyed();
}
/**
 * @brief MFormJLStation::objectEnable
 * @param enable
 */
void MFormJLStation::objectEnable(bool enable)
{
    ui->BTN_IO->setEnabled(enable);
    ui->BTN_ScanCode->setEnabled(enable);
    ui->BTN_MFormLabel->setEnabled(enable);
    ui->BTN_ATEQ->setEnabled(enable);
    ui->BTN_MFormMYSQL->setEnabled(enable);

    if(!enable){
        m_Form_ModeBusRtu->close();
        m_Form_ScanCode->close();
        m_MFormWorkStep->close();
        m_FormATEQ->close();
        m_FormMysql->close();
        ui->LD_admin->setStyleSheet("background-color:white;");
    }else{
        ui->LD_admin->setStyleSheet("background-color:rgb(0,255,0)");
    }
}

void MFormJLStation::on_BTN_Logout_clicked()
{
    objectEnable(false);
    m_FormLogin->ui->BTN_changePassword->setEnabled(false);
    m_FormLogin->ui->LE_Password->clear();
}
/**
 * @brief MFormJLStation::on_BTN_NeedPlaceNGProduct_toggled
 * @param checked
 */
void MFormJLStation::on_BTN_NeedPlaceNGProduct_toggled(bool checked)
{
    m_needPlaceNgProductChecked.store(checked);

    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->setValue("BTN_NeedPlaceNGProduct", checked);

    INI_File->destroyed();

    if(m_WorkTask->B_need_grating && !checked){
        m_WorkTask->B_need_grating = false;
    }
}

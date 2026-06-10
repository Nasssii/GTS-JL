#ifndef MWORKTASK_H
#define MWORKTASK_H

#include <QObject>
#include <QLabel>
#include <QFrame>
#include <QAbstractButton>
#include <QLineEdit>
#include <QMutex>
#include "MFormJLStation.h"
#include "ui_MFormJLStation.h"
#include "MFuntions.h"
#include "Honeywell/MForm_ScanCode.h"
#include "MMYSQL/MFormMysql.h"
#include "PLC/actutltypelib.h"

struct MStruct_AutoPrintLabel{

    char v_autoPrint_start = 0;
    char v_autoPrint_trimark = 0;
    char v_autoPrint_stop = 0;
    char v_autoPrint_getCode = 0;

    ushort v_rec_timeout_100ms = 0;
    bool b_rec_count_en = false;
    bool b_naijiu = false;//耐久测试
};
extern MStruct_AutoPrintLabel mStruct_AutoPrintLabel;

struct MST_JLTestingData{
    QString Testing_Time;
    QString Finished_Time;
    uint v_Testing_Time = 0;
    QString Testing_Pressure;
    QString Testing_LeackageValue;
};
extern MST_JLTestingData mst_CurTestingDatas;


enum ENM_STEP_WORK_MODEL{
    NE_WORK,
    Normal,
    Reset,
    HandReset,
};

enum ENM_STEP{
    NE,
    Onsite,
    GetCode,
    WaitGetCode,
    PressDown,
    WaitPressDown,
    Loosen,
    WaitLoosen,
    Exhaust,
    WaitExhaust,
    Channels,//切换channel
    StartJL,
    Wait_Start,
    JudgeResult,
    NG_Grating,

};
enum ENM_CHANNEL{
    NE_check,
    Pisitive,
    Negative,
};

enum ENM_PRE_RESET_ACTION{
    NoPreResetAction,
    TriggerScannerAfterPreReset,
    ProcessBarcodeAfterPreReset,
};

#ifndef MTESTINGUISNAPSHOT_DEFINED
#define MTESTINGUISNAPSHOT_DEFINED
struct MTestingUiSnapshot{
    QString product_code;
    QString product_number;
    QString eq_number;
    QString channel;
    QString batch;
    QString operator_id;
    QString product_code_print;
};
#endif

class mWorkTask : public QObject
{
    Q_OBJECT
public:
    explicit mWorkTask(QObject *parent = nullptr);

    QThread *pthread;
    bool B_next_reset = false;
    bool B_Resset_Hand = false;
    bool B_need_grating = false;
    bool B_grating_btn = false;
    bool B_BTN_EMC = false;
    bool B_BTN_EMC_ONE = false;

    uint8_t v_Step_WorkModel = ENM_STEP_WORK_MODEL::NE_WORK;
    uint8_t v_Step_JL = 0;
    uint8_t v_Step_JL_Reset = 0;
    uint8_t v_Step_JL_Check = ENM_CHANNEL::NE_check;

    QString detection_time;

    int8_t v_EQ_JL_Error = 0;

    uchar uc_Beep_EN[2] = {0,0};
    //RFID 读数据块
    uchar B_Read_RFID_DBs[64] = {0};

    bool b_workTask_en = false;
    bool b_onSite = false;
    bool b_onSite_B = false;
    bool b_empty = false;
    bool b_emptyCount_En = false;
    int v_Empty_Count = 0;
    bool b_workEn = false;
    bool b_resetBtnDown_FC = false;
    bool b_resetting_FC = false;
    int v_resetCount_FC = 0;
    bool b_error_FC = false;
    bool b_work_FC = false;
    bool b_mainStationFin = true;

    bool b_gameover = true;

    bool b_plusNum_En = false;
    bool b_saveFin = false;
    bool b_DpPlusRun = false;
    bool b_DpMinusNum = false;
    bool b_TY_En = false;
    uchar uc_Led_Kind = 0;//三色灯状态 0:黄 1：绿 2：红
    bool b_Beep_EN = false;//蜂鸣器报警使能

#if 0
    bool b_JL_OK = false;
    bool b_JL_recResult_en = false; //检漏接收结果使能
#endif

#if 0
    int v_blower_step = 0;//鼓风机检测流程
    bool b_blower_count_en = false;//计数使能
    int v_blower_count = 0;//计数大小
#endif

    QString CurStepItem = "";
    QString CurStepTips;//当前工序提示信息

#if 0
    uint KILEWS_Step = 0;
    bool b_KILEWS_EN = false;
    uint KILEWS_En_Step = 0;
#endif

    QStringList result_id_name = {"未完成", "OK"};
    //米勒电批
    bool Mine_DP_En = false;
    bool Mine_DP_add = false;
//    uchar Mine_DP_last_state = 0;
    bool Mine_DP_Setting_Channel = false;

    bool b_Rfid_Got = false;
    bool b_Rfid_Getting = false;

    uchar uc_Press_down = 0;

    ushort Delvo_Count_En[2] = {0, 1};//日东电批

    bool b_QG_Locked = false;
    bool B_QG_onsite = false;
    uchar uc_QG_Lock_DelayMS = 0;
    //视觉
    ushort step_iv_1 = 0;
    char B_IV2_Result[2] = {0, 0};
    //扫码
    char c_duplication_code = 0;//重码标志 -1:NG  0:等待  1：OK
    char c_duplication_code_repair = 0;//重码标志 -1:NG  0:等待  1：OK

    void WorkMain();
    void Judge_Main();
    void Judge_Aux();
    void ResetKind(const int num);
    void Onsite();
    void Offsite();
    void SaveFile();

    void Step_JL();
    void Step_JL_Reset();
    void SaveMysqlDatas(QString& errorInfo);
    bool acceptBarcode(const QString &barcode, const MTestingUiSnapshot &snapshot, QString *rejectReason = nullptr);
    bool acceptAteqData(int device, const QString &pressure, const QString &leakage);
    void requestManualReset();
public slots:
    void WorkTask();
    void slot_onAteqDataReceived(int device, const QString &pressure, const QString &leakage);

signals:
    void sign_init_Display();
    void sign_applyManualResetUi();

    void sign_Init_NoBord();
    void sign_setled(QLabel *label, const int color);
    void sign_setled_Frame(QFrame *label, const int color);
    void sign_setled_cicular(QLabel *label, const int color); 
    void sign_set_text(QLabel *label, const QString text);

    void sign_updateDatas(QStringList datas);
    void sign_led_step(int curStep, int color, QString number, QString mesg);
    void sign_Clear_MainW();//清除界面状态
    void sign_SetScandCode_Foucs();//设置扫码区域光标位置
    void sign_clearDisplayData();

    //*******
    void Sign_Control_Ys(int);

    void sign_BSM_RD_IO(char*, int);
    void sign_BSM_WR_DO(const char*);

    void Sign_Control_allOut(const char*);
    void Sign_Error();
    void Sign_AddNum();

    void Sign_BeepRunTime();
    void Sign_Setled(QLabel*, int, int);

    void Sign_non_InPlace();

    void Sign_TimerReset();
    void Sign_StationFin();

    void Sign_TipsN(const QString mes);

    void Sign_resClockOn(const int p_time);
    void Sign_resClockOff();

    void Sign_SetBtnSheet(QAbstractButton *btn, const QString text, const QString sheet);

    void Sign_ClientWrite(QString mes);
    void Sign_ClearGetCode();
    void Sign_SetlineEdit(QLineEdit*, QString);
    void sign_setTimeFlag(bool enabled);

    void sign_WriteCom_PWM(QByteArray byte);
    void sign_show_id_dialog(bool arg1 = true);

    void sign_SaveDatas_JL();
    void sign_RecordDatas(QStringList strlist);

    void sign_KILEWS_Protocol(int t_protocol);//发送奇力速协议（使能，不使能）

    void sign_IV2_Funtion(const ushort id, const ushort funtion_code, const ushort channel);//IV2协议
    void sign_IV2_Display_Init();//清除视觉图片显示

    void sign_Check_Code_PoSun_ShangLiao(const QString channel, const QString poSun_shangLiao_Code);//查询条码是否经过破损和上料
    void sign_Check_Code_PoSun_ShangLiao_Repair(const QString channel, const QString poSun_shangLiao_Code);//查询条码是否经过破损和上料

    void sign_Check_Line_AllResult(const QString line_id, const QString poSun_shangLiao_Code, const QString workStation);//查询合装产品总结果
    void sign_Check_Line_AllResult_Repair(const QString line_id, const QString poSun_shangLiao_Code, const QString workStation);//查询合装产品总结果

    void sign_Find_Duplicate_Code(const QString t_station, const QString t_channel, const QString keycode);//发送MYSQL查找重码
    void sign_Replace_ScanCode_Repair(const QString t_station, const QString t_rfid_number, const QString code_num, const QString t_ScanCode);//返修条码
    void sign_Manual_NG(bool show, QString mesg, uchar timer_count);    //手动NG
    void sign_Record_Release_time(const QString t_station, bool t_repair, const QString rfid);//放行时间
    void sign_Get_Stations_Finished_Flag(const QString rfid);
    void sign_Printe_Label_OK(QString channel);    //OK标签
    void sign_Printe_Label_NG(QString channel, QString leackage_value);    //NG标签
    void sign_MYSQL_CopyDatas_OP(const QString rfid);//复制工位数据

    void sign_set_leakvalue(const QString text);// 更新打印检漏数据
private:
    mutable QMutex m_barcodeMutex;
    mutable QMutex m_leakCycleMutex;
    QString pendingBarcode;
    QString currentBarcode;
    MTestingUiSnapshot pendingSnapshot;
    MTestingUiSnapshot currentSnapshot;
    int cycleAteqEnable = 0;
    int ateqDataWaitMs = 0;
    bool plcLeakResultLatched = false;
    bool ateq1DataReceived = false;
    bool ateq2DataReceived = false;
    bool ateq1UiCleared = false;
    bool ateq2UiCleared = false;
    bool allResetRequested = false;
    bool leakStartRequested = false;
    int productReadyWaitMs = 0;
    bool lastPlcOverallTesting = false;
    bool lastPlcPhysicalReset = false;
    bool physicalResetLatchHandled = false;
    bool waitingPhysicalResetClear = false;
    bool physicalResetClearWarned = false;
    int physicalResetClearWaitMs = 0;
    ENM_PRE_RESET_ACTION preResetAction = NoPreResetAction;
    bool preResetCompletedForPendingBarcode = false;
    int preScanResetWaitMs = 0;
    mutable QMutex m_manualResetMutex;
    bool manualResetRequested = false;
    bool detectionTimerActive = false;

    QString takePendingBarcode(MTestingUiSnapshot *snapshot);
    void clearCurrentBarcode();
    void clearAteqReceiveState();
    void setDetectionTimerActive(bool enabled);
    void resetLeakCycleState();
    bool requiredAteqDataReceived() const;
    void requestReceivedLeakResets();
    void finishLeakCycleAfterResult();
    bool takeManualResetRequest();
    void performManualReset();
};

extern mWorkTask *m_WorkTask;

#endif // MWORKTASK_H

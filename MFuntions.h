#ifndef MFUNTIONS_H
#define MFUNTIONS_H

#include <QString>
#include <QDir>
#include <QStandardItemModel>
#include <QSettings>
#include <QTextCodec>
#include "mWorkTask.h"

/* 1：灰色
 * 2：红色
 * 3：绿色
 * 4：黄色
 * 5：透明白*/

enum Em_WorkTask{
    Main,
    OutSide,
    JL,
};

enum m_color{
    Gray,
    Red,
    Green,
    Yellow,
    White,
    black,
};

class MFuntions
{

public:
    MFuntions();

    static QString mKMutiDir(const QString path);
    static void write_CSV(const QString &fileName, const QStringList listDatas);
    static void write_INI(const QString &fileName, const QString group, QVariant data);
    static void setBit(uint16_t &data, uint16_t pos);
    static void toggleBit(uint16_t &data, uint16_t pos);
    static bool checkBit(uint16_t data, uint16_t pos);
    static void clearBit(uint16_t &data, uint16_t pos);
    static QString uint8ToBinaryStringStd(uint16_t value);
    static uint16_t compareBits(uint16_t a, uint16_t b);
    static uint16_t specialBitCompare(uint16_t a, uint16_t b);
    static double getProcessCpuUsage();
    static bool readCsvByStream(const QString &filePath, QList<QString> &data);
    static QString createHtmlTableFromStringList(const QList<QStringList> &data);
    static void write_TXT(const QString &filepath, const QList<QString> &list_txt);
    static void append_TXT(const QString &filepath, const QList<QString> &list_txt);
    static void printVectorToPrinter(const QVector<QString> &vec);

public slots:
};


class MDataBean
{

public:

    MDataBean();



    QMap<QString, QString> map_detection_code_result;


    uint8_t v_WorkTaskEn = 1;   //工作使能
    uint8_t v_WorkTaskFinished = 0; //工作完成标志
    uint8_t v_WorkTaskDeal = 0; //相同为1，不同为0

    bool B_load_channel_OK = false;

    uchar v_CurStepItem_Idx = 1;   //当前工作到的流程索引
    uchar v_CurStepItem_Count = 0; //当前工作到的流程次数

    QStringList CurStepNames;   //当前需要工作的流程名称
    QStringList CurStep_GDJ_Number; //当前电批流程顺序
    QStringList CurStep_GDJ; //当前供钉机流程顺序

    QString beginTime;
    QString endTime;

    QStringList list_StepItems_NameIdx; //当前工作流程列表名字的索引
    QStringList list_StepItems_Number;  //当前工作流程列表总次数
    QStringList fyw;

    uchar v_JL_Kind = 0;    //气密性检测类型索引

    QString channel = "";
    QString project_name;
    QString product_name;
    bool B_FYW_1 = false;
    bool B_FYW_2 = false;
    uchar FYW_Count = 0;
    QString rfid_number;
    QString step_name;
    int TY_S1 = 0;    //涂油1设置时间
    int TY_S2 = 0;    //涂油2设置时间


    QStringList list_FixCodeName = {"", "", "", "", "", ""};    //6个条码名称
    QStringList list_FixCode = {"", "", "", "", "", ""};    //6个条码固定段
    QStringList list_Codes = {"", "", "", "", "", ""};  //6个条码识别记录

    int screws = 0;

    ushort ready_time = 0;
    ushort check_time = 0;
    bool B_count = false;
    bool B_outside_Finished = false;
    int v_ct = 0;

    ushort FinCount[20] = {0};
};

extern MDataBean Databean;

struct MS_Datas{

    QString BeginDate;

    QString EndDate;

    int Work_CT = 0;

    bool B_load_channel_OK = false; //加载品番成功

    QString labelModelName = "";//标签

    QString rfid_number;

    QString channel = "";
    QString project_name;
    QString product_name;

    bool B_count = false;

    bool B_outside_Finished = true;

    int v_ct = 0;

    QStringList SCodeFuntions;//扫码枪功能设置

    QStringList list_keycode = {"", "", "", "", "", ""};
    QStringList list_Codes_set = {"", "", "", "", "", ""};
    QList<int> list_Codes_length = {0,0,0,0,0,0};//条码长度
    QList<int> list_Codes_Repeat = {0,0,0,0,0,0};//重码判断

    bool Check_Pisitive = false;//正压检测使能
    bool Check_Negative = false;//负压检测使能

    int Channel_Pisitive = 1;//正压检测频道
    int Chanel_Negative = 1;//负压检测频道

    QString Result_Pisitive = "";//正压结果
    QString Result_Negative = "";//负压结果

    int ATEQ_Enable;
    int plcProductAteq1 = 1; // D1902 target product/channel; falls back to channel when invalid.
    int plcProductAteq2 = 1; // D1903 target product/channel; falls back to channel when invalid.

    QStringList JL_Data;
    QStringList JL_Data_1;
    QStringList JL_Data_2;

};
extern MS_Datas CurWorkPar;


struct MS_anGui{
    float v_JueYuan[2] = {0.0};
    float v_NaiYa_1[2] = {0.0};
    float v_NaiYa_2[2] = {0.0};
    float v_JieDiDianZu[2] = {0.0};
    float v_XieLou[2] = {0.0};
};
extern MS_anGui ms_anGuiDatas;

struct MS_JiaZhuJi{
    float v_dosageTarget[2] = {0.0};
    float v_dosageReal[2] = {0.0};
    float v_dosagPressure[2] = {0.0};
    float v_dosagVacuum[2] = {0.0};
    float v_dosagTime[2] = {0.0};

    int8_t v_dosageError = 0;//内部报警 16BCD
    QString doasgeErrorInfo;//报警信息
    int8_t v_dosageFinished = 0;//加注完成  16BCD
    QString dosageModeName;   //判断A枪或B枪
};
extern MS_JiaZhuJi ms_JiaZhuJiDatas;

//此结构体用于各种类信息交互
struct MStruct_PublicVar{

    uchar uc_again_get_RFID = 0;
    bool B_need_Rfid = false;//用于判断是否需要获取Rfid操作
};
extern MStruct_PublicVar m_Struct_PublicVar;


extern QString generateSimpleTable(const QString &title, const QVector<QStringList> &data, const QStringList &headers);
extern void createSimpleTableExample();
#endif // MFUNTIONS_H

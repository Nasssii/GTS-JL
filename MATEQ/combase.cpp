#include "combase.h"
#include "ui_MFormATEQ.h"

namespace {
QStringList parseAteqData(const QString &text)
{
    QStringList parts = text.split(":");
    int resultIndex = -1;
    for (int i = 0; i < parts.size(); ++i) {
        const QString token = parts.at(i).trimmed();
        if (token.contains("OK", Qt::CaseInsensitive)
                || token.contains("NG", Qt::CaseInsensitive)) {
            resultIndex = i;
            break;
        }
    }

    if (resultIndex <= 0 || resultIndex + 1 >= parts.size()) {
        return QStringList();
    }

    QString result = parts.value(resultIndex).trimmed();
    if (result.startsWith("(") && result.endsWith(")") && result.size() >= 2) {
        result = result.mid(1, result.size() - 2).trimmed();
    }

    return QStringList()
            << parts.value(resultIndex - 1).trimmed()
            << result
            << parts.value(resultIndex + 1).trimmed();
}

bool ateqDataReady(const QStringList &data)
{
    return data.size() >= 3;
}
}

mComThread *m_ComThread;

COMLeakHunting *m_COMLeakHunting;
COMLeakHunting_2 *m_COMLeakHunting_2;

//串口线程
mComThread::mComThread(QObject *parent)
{
    Q_UNUSED(parent);
    pthread = new QThread();
    this->moveToThread(pthread);
    connect(pthread, &QThread::started, this, &mComThread::init_Com);
}

mComThread::~mComThread()
{
}

void mComThread::init_Com()
{
    m_COMLeakHunting->Init_Port_1();
    m_COMLeakHunting_2->Init_Port_2();
}

COMLeakHunting::COMLeakHunting(QObject *parent) : QObject(parent)
  ,a_rfid(CurWorkPar.rfid_number)
{
    C_timer_1 = new QTimer;
    C_timer_1->setSingleShot(true);
    this->moveToThread(m_ComThread->pthread);
    C_timer_1->moveToThread(m_ComThread->pthread);
    connect(C_timer_1, &QTimer::timeout, this, &COMLeakHunting::ReadFinish_1);
}

COMLeakHunting::~COMLeakHunting()
{
}

//检漏串口1 初始化
void COMLeakHunting::Init_Port_1()
{
    if(!B_open){
        COM_1 = new QSerialPort(this);
        COM_1->setPortName(ms_MFormATEQ.Port_1);
        COM_1->setBaudRate(ms_MFormATEQ.Buad_1.toUInt());
        COM_1->setDataBits(QSerialPort::Data8);
        COM_1->setStopBits(QSerialPort::OneStop);
        COM_1->setParity(QSerialPort::NoParity);

        if(!COM_1->open(QIODevice::ReadWrite)){
            delete COM_1;
            COM_1 = nullptr;
            return;
        }
        B_open = true;

        emit sign_tips("ATEQ 1 Port:" + ms_MFormATEQ.Port_1, m_color::Green);
        emit Sign_COMStyleSheet("ATEQ 1", true);
        connect(COM_1, &QSerialPort::readyRead, this, &COMLeakHunting::ReadData_1, Qt::QueuedConnection);
    }else{

        B_open = false;
        emit Sign_COMStyleSheet("ATEQ 1", false);
        clearReceiveState();
        if(COM_1 != nullptr){
            disconnect(COM_1, &QSerialPort::readyRead, this, &COMLeakHunting::ReadData_1);
            COM_1->close();
            delete COM_1;
            COM_1 = nullptr;
        }
    }
}
//  ************************************************************************************************
void COMLeakHunting::ReadData_1()
{
    if(COM_1 == nullptr || !COM_1->isOpen()){
        return;
    }

    QByteArray bytedata = COM_1->readAll();

    if(Data_1.size() == 0){
        C_timer_1->start(50);
    }
    Data_1 += bytedata;
}
//  ************************************************************************************************
void COMLeakHunting::ReadFinish_1()
{
    Bool_JL_RecData_1 = true;
    JL_last_rec_data = Data_1;

    QString ateq1_res = QString::fromLatin1(JL_last_rec_data);
    ateq1_res = ateq1_res.trimmed();
    v_ATEQ_Enable = CurWorkPar.ATEQ_Enable;
    if(v_ATEQ_Enable == 1 || v_ATEQ_Enable == 3){
        emit sign_MYSQL_Update_JL(a_rfid, "使能", ateq1_res);
        qDebug() << "发送";
    }
//    CurWorkPar.JL_Data.clear();
    qDebug() << "ATEQ 1 Datas：" << a_rfid << ateq1_res;
    CurWorkPar.JL_Data = ateq1_res.split(":");
    CurWorkPar.JL_Data_1 = parseAteqData(ateq1_res);
    if (ateqDataReady(CurWorkPar.JL_Data_1)) {
        emit sign_ATEQ_Display(1, CurWorkPar.JL_Data_1.at(0), CurWorkPar.JL_Data_1.at(2));
    } else {
        qDebug() << "[ATEQ] parse failed device=1 raw=" << ateq1_res;
    }
    emit sign_tips("Item1:" + ateq1_res, m_color::Green);
    ms_MFormATEQ.ATEQ_Datas_1 = ateq1_res;
    if(ateq1_res.contains("OK")){
        ms_MFormATEQ.B_ATEQ1_Finished = true;
    }else{
        ms_MFormATEQ.B_ATEQ1_Finished = false;
    }
    emit sign_ATEQ_RawDisplay(1, ateq1_res, ateq1_res.contains("OK"));
    Data_1.clear();
}

void COMLeakHunting::clearReceiveState()
{
    if(C_timer_1 != nullptr){
        C_timer_1->stop();
    }
    Data_1.clear();
    JL_last_rec_data.clear();
    Bool_JL_RecData_1 = false;
    ms_MFormATEQ.ATEQ_Datas_1.clear();
    ms_MFormATEQ.B_ATEQ1_Finished = false;
}

COMLeakHunting_2::COMLeakHunting_2(QObject *parent) : QObject(parent)
  ,a_rfid(CurWorkPar.rfid_number)
{
    C_timer_2 = new QTimer;
    C_timer_2->setSingleShot(true);
    this->moveToThread(m_ComThread->pthread);
    C_timer_2->moveToThread(m_ComThread->pthread);
    connect(C_timer_2, &QTimer::timeout, this, &COMLeakHunting_2::ReadFinish_2);
}

COMLeakHunting_2::~COMLeakHunting_2()
{
}
//检漏串口初始化2
void COMLeakHunting_2::Init_Port_2()
{
    if(!B_open){
        COM_1 = new QSerialPort(this);
        COM_1->setPortName(ms_MFormATEQ.Port_2);
        COM_1->setBaudRate(ms_MFormATEQ.Buad_2.toUInt());
        COM_1->setDataBits(QSerialPort::Data8);
        COM_1->setStopBits(QSerialPort::OneStop);
        COM_1->setParity(QSerialPort::NoParity);

        if(!COM_1->open(QIODevice::ReadWrite)){
            delete COM_1;
            COM_1 = nullptr;
            return;
        }
        B_open = true;
        emit sign_tips("ATEQ 2 Port:" + ms_MFormATEQ.Port_2, m_color::Green);
        emit Sign_COMStyleSheet("ATEQ 2", true);
        connect(COM_1, &QSerialPort::readyRead, this, &COMLeakHunting_2::ReadData_2, Qt::QueuedConnection);
    }else{

        B_open = false;
        emit Sign_COMStyleSheet("ATEQ 2", false);
        clearReceiveState();
        if(COM_1 != nullptr){
            disconnect(COM_1, &QSerialPort::readyRead, this, &COMLeakHunting_2::ReadData_2);
            COM_1->close();
            delete COM_1;
            COM_1 = nullptr;
        }
    }
}

void COMLeakHunting_2::ReadData_2()
{
    if(COM_1 == nullptr || !COM_1->isOpen()){
        return;
    }

    QByteArray bytedata = COM_1->readAll();

    if(Data_2.size() == 0){
        C_timer_2->start(50);
    }
    Data_2 += bytedata;
}

void COMLeakHunting_2::ReadFinish_2()
{
    Bool_JL_RecData_2 = true;
    JL_last_rec_data = Data_2;

    Data_2.clear();
    QString ateq1_res = QString::fromLatin1(JL_last_rec_data);
    ateq1_res = ateq1_res.trimmed();

    v_ATEQ_Enable = CurWorkPar.ATEQ_Enable;
    if(v_ATEQ_Enable == 2 || v_ATEQ_Enable == 3){
        emit sign_MYSQL_Update_JL(a_rfid, "使能", ateq1_res);
    }
    qDebug() << "ATEQ 2 Datas:" << a_rfid << ateq1_res;
    CurWorkPar.JL_Data_2 = parseAteqData(ateq1_res);
    if (ateqDataReady(CurWorkPar.JL_Data_2)) {
        emit sign_ATEQ_Display(2, CurWorkPar.JL_Data_2.at(0), CurWorkPar.JL_Data_2.at(2));
    } else {
        qDebug() << "[ATEQ] parse failed device=2 raw=" << ateq1_res;
    }

    emit sign_tips("Item2:" + ateq1_res, m_color::Green);

    if(ateq1_res.contains("OK")){
        ms_MFormATEQ.B_ATEQ2_Finished = true;
    }else{
        ms_MFormATEQ.B_ATEQ2_Finished = false;
    }
    emit sign_ATEQ_RawDisplay(2, ateq1_res, ateq1_res.contains("OK"));
}

void COMLeakHunting_2::clearReceiveState()
{
    if(C_timer_2 != nullptr){
        C_timer_2->stop();
    }
    Data_2.clear();
    JL_last_rec_data.clear();
    Bool_JL_RecData_2 = false;
    ms_MFormATEQ.ATEQ_Datas_2.clear();
    ms_MFormATEQ.B_ATEQ2_Finished = false;
}




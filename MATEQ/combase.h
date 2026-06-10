#ifndef COM_BASE_H
#define COM_BASE_H

#include <QObject>
#include "MFormJLStation.h"
#include "ui_MFormJLStation.h"
#include "MFuntions.h"


struct S_4{

    QString Com;
    uint Baud = 115200;
    int error_count = 0;
    bool B_Open = false;
    QString Get_RW = "ReadAD";
    QByteArray byte_data;
    QByteArray rec_read;
    bool B_Recv = false;
};


class mComThread : public QObject
{
    Q_OBJECT
public:
    explicit mComThread(QObject *parent = nullptr);
    ~mComThread();

    QThread *pthread;
    void init_Com();


public slots:

signals:


private:

};



class COMLeakHunting : public QObject
{
    Q_OBJECT

public:
    explicit COMLeakHunting(QObject *parent = nullptr);
    ~COMLeakHunting();

    uchar v_ATEQ_Enable = 0;

    QString& a_rfid;
    QString ATEQ_Datas = "";
    QString ATEQ_Result = "";

    bool B_open = false;

    QByteArray Data_1;
    char *rec_data_1;
    QTimer *C_timer_1;
    QThread *C_thread;
    QSerialPort *COM_1 = nullptr;

    int JL_Result_1 = 0;
    bool Bool_JL_RecData_1 = false;
    QByteArray JL_last_rec_data;


signals:
    void Sign_Setled(QLabel *label, const int color);
    void sign_setled_cicular(QLabel *label, const int color);
    void sign_tips(const QString &mesg, const uchar colorid);
    void Sign_COMStyleSheet(const QString &name, bool b_value);
    void sign_MYSQL_Update_JL(const QString p_rfid, const QString p_en, const QString p_datas);
    void sign_ATEQ_Display(int device, const QString &pressure, const QString &leakage);
    void sign_ATEQ_RawDisplay(int device, const QString &raw, bool ok);

public slots:

    void Init_Port_1();
    void ReadData_1();
    void ReadFinish_1();
    void clearReceiveState();

};

class COMLeakHunting_2 : public QObject
{
    Q_OBJECT

public:
    explicit COMLeakHunting_2(QObject *parent = nullptr);
    ~COMLeakHunting_2();


    uchar v_ATEQ_Enable = 0;
    QString ATEQ_Datas = "";
    QString ATEQ_Result = "";

    QString& a_rfid;

    bool B_open = false;
    QByteArray Data_2;
    char *rec_data_2;

    QTimer *C_timer_2;
    QThread *C_thread;
    QSerialPort *COM_1 = nullptr;
    int JL_Result_2 = 0;
    bool Bool_JL_RecData_2 = false;
    QByteArray JL_last_rec_data;

signals:
    void Sign_Setled(QLabel *label, const int color);
    void sign_setled_cicular(QLabel *label, const int color);
    void sign_tips(const QString &mesg, const uchar colorid);
    void Sign_COMStyleSheet(const QString &name, bool b_value);
    void sign_MYSQL_Update_JL(const QString p_rfid, const QString p_en, const QString p_datas);
    void sign_ATEQ_Display(int device, const QString &pressure, const QString &leakage);
    void sign_ATEQ_RawDisplay(int device, const QString &raw, bool ok);

public slots:

    void Init_Port_2();
    void ReadData_2();
    void ReadFinish_2();
    void clearReceiveState();

};


extern mComThread *m_ComThread;

extern COMLeakHunting *m_COMLeakHunting;
extern COMLeakHunting_2 *m_COMLeakHunting_2;

extern bool BSM_T_EN;
extern uint BSM_MS_Count;

extern uint32_t BSM_RW_Count1;
extern uint32_t BSM_RW_Count2;


#endif // COM_BASE_H

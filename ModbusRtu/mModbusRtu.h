#ifndef MMODBUSRTU_H
#define MMODBUSRTU_H

#include <QObject>
#include <QTimer>
#include <QModbusDataUnit>
#include <QMutex>
#include <QLabel>
#include <QThread>
#include <QDebug>
#include "MForm_ModeBusRtu.h"

class mModbusRtu : public QObject
{
    Q_OBJECT

public:
    explicit mModbusRtu(QObject *parent = nullptr);


    QString tips;

    QTimer *pTimer;
    bool b_modbus_port_en = false;
    int v_response_timeout_count = 0;
    bool b_reConnecting = false;
    uint v_reConnect_Count = 0;

    QThread *pthread;

    QModbusDataUnit Wdata;
    QModbusDataUnit RD_data;
    QVector<quint16> recDatasCo = QVector<quint16> (32);
    QVector<quint16> recDatasDi = QVector<quint16> (32);
//    bool b_recDatasDi_update = false; //判断是否刷新数据
//    QVector<quint16> recDatasDi_stateChange = QVector<quint16> (32);    //判断是否状态变化

    bool B_Rec_Finished = false;

    QString _COM_Name = "COM10";
    uint _BaudRate = 19200;
    uint _Parity = 0;
    uint _DataBits = 8;
    uint _StopBits = 1;
    uint _timeout = 3000;

    bool _rec_OK = true;

    // Keep state/error strings so existing UI code remains compatible.
    QStringList _list_state = {"UnconnectedState", "ConnectingState", "ConnectedState", "ClosingState"};
    QStringList _list_error = {"NoError", "ReadError", "WriteError", "ConnectionError", "ConfigurationError", "TimeoutError", "ProtocolError", "ReplyAbortedError", "UnknownError"};
    QString errorCode_Connect = "UnconnectedState";
    QString errorCode_Occur = "UnconnectedState";
    QString errorCode_Sec = "NoError";

    // PLC word mirror.
    quint16 plc_D90 = 0;
    quint16 plc_D91 = 0;
    quint16 plc_D1900 = 0;
    quint16 plc_D1901 = 0;
    quint16 plc_D1902 = 0;
    quint16 plc_D1903 = 0;
    quint16 plc_N10 = 0;
    uint plc_heartbeat_tick = 0;
    uint plc_test_tick = 0;
    bool plc_test_enable = false;
    int all_reset_ticks = 0;
    int leak_start_ticks = 0;

public:

    void creatModbusD(QString com, uint baudBit, uint dataBit, uint stopBits, uint parityBit);
    void disconnectDevice();

    void reconnectModbus();
    void syncOutputsToPlcWords();
    void syncPlcWordsToInputs();
    bool writeCurrentProductWords();
    bool plcOverallHasResult() const;
    bool plcOverallResult() const;
    bool plcOverallTesting() const;
    bool plcSelectedLeakHasResult() const;
    bool plcSelectedLeakResult() const;
    bool plcSelectedLeakIdle() const;
    bool plcSelectedProductReady() const;
    bool plcPhysicalResetRequested() const;
    bool clearPhysicalResetLatch();
    quint16 currentProductWord() const;
    quint16 targetProductWordForLeak1() const;
    quint16 targetProductWordForLeak2() const;
    void requestLeakStart();
    void requestAllReset();

    static bool getBit(quint16 word, int bit);
    static void setBit(quint16 &word, int bit, bool on);
public slots:

    void slot_ReadDiscreteInputs();
    void slot_ReadCoils();
    void slot_WriteCoils();
    void reConnectDevice();
    void slot_OpCl_Device(QString com, uint baudBit, uint dataBit, uint stopBits, uint parityBit);

    void slot_ReadInputRegisters();
private:
    bool writeSelectedProductWordsLocked();
    QMutex mutex;
    QTimer *ptimer = new QTimer(this);

private slots:
    void _WR_OnReadReady();
    void _RD_OnReadReady();

signals:
    void sign_setled(QLabel*, int, int);
    void sign_setled_cicular(QLabel *label, const int color);
    void Sign_COMStyleSheet(const QString &name, bool b_value);
};

extern mModbusRtu *m_ModbusRtu;


#endif // MMODBUSRTU_H

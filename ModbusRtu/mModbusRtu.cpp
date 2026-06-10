#include "mModbusRtu.h"
#include "PLC/actutltypelib.h"
#include "MFormWorkStep.h"
#include "ui_MFormWorkStep.h"
#include "MFuntions.h"

mModbusRtu *m_ModbusRtu;

namespace {
const QString kDeviceName = "PLC";
const int kHeartbeatTicks = 10; // slot_WriteCoils is called every 100ms.

bool plcWriteWord(const QString &device, quint16 value)
{
    if (Act_Type_PLC_1 == nullptr) {
        return false;
    }

    if (QThread::currentThread() == Act_Type_PLC_1->thread()) {
        return Act_Type_PLC_1->SetDevice(device, static_cast<int>(value)) == 0;
    }

    bool ok = false;
    const bool invoked = QMetaObject::invokeMethod(Act_Type_PLC_1, [&]() {
        ok = Act_Type_PLC_1->SetDevice(device, static_cast<int>(value)) == 0;
    }, Qt::BlockingQueuedConnection);
    return invoked && ok;
}

bool plcWriteBit(const QString &device, bool value)
{
    if (Act_Type_PLC_1 == nullptr) {
        return false;
    }

    if (QThread::currentThread() == Act_Type_PLC_1->thread()) {
        return Act_Type_PLC_1->SetDevice(device, value ? 1 : 0) == 0;
    }

    bool ok = false;
    const bool invoked = QMetaObject::invokeMethod(Act_Type_PLC_1, [&]() {
        ok = Act_Type_PLC_1->SetDevice(device, value ? 1 : 0) == 0;
    }, Qt::BlockingQueuedConnection);
    return invoked && ok;
}

bool plcReadWord(const QString &device, quint16 &value)
{
    if (Act_Type_PLC_1 == nullptr) {
        return false;
    }

    int readValue = 0;
    bool ok = false;
    if (QThread::currentThread() == Act_Type_PLC_1->thread()) {
        ok = Act_Type_PLC_1->GetDevice(device, readValue) == 0;
    } else {
        const bool invoked = QMetaObject::invokeMethod(Act_Type_PLC_1, [&]() {
            ok = Act_Type_PLC_1->GetDevice(device, readValue) == 0;
        }, Qt::BlockingQueuedConnection);
        ok = invoked && ok;
    }

    if (!ok) {
        return false;
    }

    value = static_cast<quint16>(readValue);
    return true;
}

void setInputValue(QVector<quint16> &inputs, const QString &name, bool value)
{
    if (!mS_BSMIO.IO_XY.contains(name)) {
        return;
    }

    const int index = mS_BSMIO.IO_XY.value(name);
    if (index < 0 || index >= inputs.size()) {
        return;
    }

    inputs[index] = value ? 1 : 0;
}

void clearOutputBitByName(QModbusDataUnit &outputs, const QString &name)
{
    if (!mS_BSMIO.IO_XY.contains(name)) {
        return;
    }

    const int index = mS_BSMIO.IO_XY.value(name);
    if (index < 0 || index >= static_cast<int>(outputs.valueCount())) {
        return;
    }

    outputs.setValue(index, 0);
}

void clearLegacyProgramSwitchBits(QModbusDataUnit &outputs)
{
    clearOutputBitByName(outputs, "切换程序Bit0");
    clearOutputBitByName(outputs, "切换程序Bit1");
    clearOutputBitByName(outputs, "切换程序Bit2");
    clearOutputBitByName(outputs, "切换程序Bit3");
    clearOutputBitByName(outputs, "切换程序Bit4");
}

quint16 fallbackProductWord()
{
    return static_cast<quint16>(CurWorkPar.channel.toUInt());
}

quint16 configuredProductWordForLeak1()
{
    if (CurWorkPar.plcProductAteq1 > 0) {
        return static_cast<quint16>(CurWorkPar.plcProductAteq1);
    }
    return fallbackProductWord();
}

quint16 configuredProductWordForLeak2()
{
    if (CurWorkPar.plcProductAteq2 > 0) {
        return static_cast<quint16>(CurWorkPar.plcProductAteq2);
    }
    return fallbackProductWord();
}

int currentAteqEnable()
{
    return CurWorkPar.ATEQ_Enable;
}

quint16 selectedProductForLeak1()
{
    return configuredProductWordForLeak1();
}

quint16 selectedProductForLeak2()
{
    return configuredProductWordForLeak2();
}
}

mModbusRtu::mModbusRtu(QObject *parent) : QObject(parent)
{
    pthread = new QThread;
    Wdata = QModbusDataUnit(QModbusDataUnit::Coils, 0, 32);
    this->moveToThread(pthread);
    connect(pthread, &QThread::started, this, [=]() {
        creatModbusD(mS_BSMIO.BSM_PORT, mS_BSMIO.BSM_BUAD.toUInt(), 8, 1, 0);
    });
}

bool mModbusRtu::getBit(quint16 word, int bit)
{
    return ((word >> bit) & 0x01u) != 0;
}

void mModbusRtu::setBit(quint16 &word, int bit, bool on)
{
    if (on) {
        word |= static_cast<quint16>(1u << bit);
    } else {
        word &= static_cast<quint16>(~(1u << bit));
    }
}

void mModbusRtu::creatModbusD(QString com, uint baudBit, uint dataBit, uint stopBits, uint parityBit)
{
    _COM_Name = com;
    _BaudRate = baudBit;
    _DataBits = dataBit;
    _StopBits = stopBits;
    _Parity = parityBit;

    b_modbus_port_en = (Act_Type_PLC_1 != nullptr);
    errorCode_Connect = b_modbus_port_en ? "ConnectedState" : "UnconnectedState";
    errorCode_Occur = b_modbus_port_en ? "NoError" : "ConnectionError";
    errorCode_Sec = b_modbus_port_en ? "NoError" : "PLC object is null";
    emit Sign_COMStyleSheet(kDeviceName, b_modbus_port_en);
}

void mModbusRtu::disconnectDevice()
{
    b_modbus_port_en = false;
    errorCode_Connect = "UnconnectedState";
    emit Sign_COMStyleSheet(kDeviceName, false);
}

void mModbusRtu::reconnectModbus()
{
    if (!b_modbus_port_en) {
        creatModbusD(_COM_Name, _BaudRate, _DataBits, _StopBits, _Parity);
    }
}

void mModbusRtu::slot_OpCl_Device(QString com, uint baudBit, uint dataBit, uint stopBits, uint parityBit)
{
    if (b_modbus_port_en) {
        disconnectDevice();
    } else {
        creatModbusD(com, baudBit, dataBit, stopBits, parityBit);
    }
}

void mModbusRtu::reConnectDevice()
{
    v_reConnect_Count++;
    reconnectModbus();
}

bool mModbusRtu::writeCurrentProductWords()
{
    QMutexLocker locker(&mutex);
    return writeSelectedProductWordsLocked();
}

bool mModbusRtu::writeSelectedProductWordsLocked()
{
    const int ateqEnable = currentAteqEnable();
    bool writeOk = true;
    plc_D1902 = selectedProductForLeak1();
    plc_D1903 = selectedProductForLeak2();
    writeOk = plcWriteWord("D1902", plc_D1902) && writeOk;
    writeOk = plcWriteWord("D1903", plc_D1903) && writeOk;

    qDebug() << "[PLC] write product words"
             << "softwareProduct=" << CurWorkPar.channel
             << "ATEQ=" << ateqEnable
             << "writeD1902=" << true
             << "D1902=" << plc_D1902
             << "writeD1903=" << true
             << "D1903=" << plc_D1903;

    errorCode_Sec = writeOk ? "NoError" : "PLC WriteError";
    return writeOk;
}

bool mModbusRtu::plcOverallHasResult() const
{
    return getBit(plc_D1901, 2);
}

bool mModbusRtu::plcOverallResult() const
{
    return getBit(plc_D1901, 3);
}

bool mModbusRtu::plcOverallTesting() const
{
    return getBit(plc_D1901, 1);
}

bool mModbusRtu::plcSelectedLeakHasResult() const
{
    const int ateqEnable = currentAteqEnable();
    const bool leak1HasResult = getBit(plc_D1901, 6);
    const bool leak2HasResult = getBit(plc_D1901, 9);

    if (ateqEnable == 1) {
        return leak1HasResult;
    }
    if (ateqEnable == 2) {
        return leak2HasResult;
    }
    if (ateqEnable == 3) {
        return leak1HasResult && leak2HasResult;
    }

    return false;
}

bool mModbusRtu::plcSelectedLeakResult() const
{
    const int ateqEnable = currentAteqEnable();
    const bool leak1Result = getBit(plc_D1901, 7);
    const bool leak2Result = getBit(plc_D1901, 10);

    if (ateqEnable == 1) {
        return leak1Result;
    }
    if (ateqEnable == 2) {
        return leak2Result;
    }
    if (ateqEnable == 3) {
        return leak1Result && leak2Result;
    }

    return false;
}

bool mModbusRtu::plcSelectedLeakIdle() const
{
    const int ateqEnable = currentAteqEnable();
    const bool overallTesting = getBit(plc_D1901, 1);
    const bool leak1Testing = getBit(plc_D1901, 5);
    const bool leak1HasResult = getBit(plc_D1901, 6);
    const bool leak2Testing = getBit(plc_D1901, 8);
    const bool leak2HasResult = getBit(plc_D1901, 9);

    if (overallTesting) {
        return false;
    }
    if (ateqEnable == 1) {
        return !leak1Testing && !leak1HasResult;
    }
    if (ateqEnable == 2) {
        return !leak2Testing && !leak2HasResult;
    }
    if (ateqEnable == 3) {
        return !leak1Testing && !leak1HasResult
                && !leak2Testing && !leak2HasResult;
    }

    return true;
}

quint16 mModbusRtu::currentProductWord() const
{
    return static_cast<quint16>(CurWorkPar.channel.toUInt());
}

quint16 mModbusRtu::targetProductWordForLeak1() const
{
    return configuredProductWordForLeak1();
}

quint16 mModbusRtu::targetProductWordForLeak2() const
{
    return configuredProductWordForLeak2();
}

bool mModbusRtu::plcSelectedProductReady() const
{
    const int ateqEnable = currentAteqEnable();
    const quint16 targetProduct1 = targetProductWordForLeak1();
    const quint16 targetProduct2 = targetProductWordForLeak2();
    if (ateqEnable == 1) {
        return targetProduct1 > 0 && plc_D90 == targetProduct1;
    }
    if (ateqEnable == 2) {
        return targetProduct2 > 0 && plc_D91 == targetProduct2;
    }
    if (ateqEnable == 3) {
        return targetProduct1 > 0 && targetProduct2 > 0
                && plc_D90 == targetProduct1 && plc_D91 == targetProduct2;
    }

    return false;
}

bool mModbusRtu::plcPhysicalResetRequested() const
{
    return plc_N10 != 0 || getBit(plc_D1901, 11);
}

bool mModbusRtu::clearPhysicalResetLatch()
{
    const bool ok = plcWriteBit("D1901.B", false);
    if (ok) {
        QMutexLocker locker(&mutex);
        setBit(plc_D1901, 11, false);
    }
    qDebug() << "[PLC] clear physical reset latch D1901.B" << (ok ? "ok" : "failed");
    return ok;
}

void mModbusRtu::requestAllReset()
{
    QMutexLocker locker(&mutex);
    leak_start_ticks = 0;
    all_reset_ticks = 3;
    qDebug() << "[PLC] request all reset pulse D1900 bit4";
}

void mModbusRtu::requestLeakStart()
{
    QMutexLocker locker(&mutex);
    if (all_reset_ticks > 0) {
        qDebug() << "[PLC] leak start ignored during reset pulse";
        return;
    }
    leak_start_ticks = 3;
    qDebug() << "[PLC] request leak start pulse D1900 bit5";
}

void mModbusRtu::syncOutputsToPlcWords()
{
    clearLegacyProgramSwitchBits(Wdata);

    // D1900 status word managed by software.
    plc_heartbeat_tick++;
    if (plc_heartbeat_tick >= kHeartbeatTicks) {
        plc_heartbeat_tick = 0;
        setBit(plc_D1900, 0, !getBit(plc_D1900, 0)); // heartbeat toggle
    }
    setBit(plc_D1900, 1, true);                      // software ready

    const int ateqEnable = currentAteqEnable();
    setBit(plc_D1900, 3, ateqEnable == 1 || ateqEnable == 3);
    setBit(plc_D1900, 9, ateqEnable == 2 || ateqEnable == 3);

    setBit(plc_D1900, 4, all_reset_ticks > 0);
    setBit(plc_D1900, 5, leak_start_ticks > 0 && all_reset_ticks == 0);
    setBit(plc_D1900, 10, false);
    if (all_reset_ticks > 0) {
        --all_reset_ticks;
    }
    if (leak_start_ticks > 0) {
        --leak_start_ticks;
    }
    // Stage bridge: keep high-level output mirror for display/debug.
    for (int i = 0; i < recDatasCo.size(); ++i) {
        recDatasCo[i] = Wdata.value(i);
    }

    const bool d1900WriteOk = plcWriteWord("D1900", plc_D1900);
    errorCode_Sec = d1900WriteOk ? "NoError" : "PLC WriteError";

}

void mModbusRtu::syncPlcWordsToInputs()
{
    const bool fixtureReady = getBit(plc_D1901, 0);
    const bool overallTesting = getBit(plc_D1901, 1);
    const bool overallHasResult = getBit(plc_D1901, 2);
    const bool overallResult = getBit(plc_D1901, 3);
    const bool leak1HasResult = getBit(plc_D1901, 6);
    const bool leak1Result = getBit(plc_D1901, 7);
    const bool leak2HasResult = getBit(plc_D1901, 9);
    const bool leak2Result = getBit(plc_D1901, 10);

    setInputValue(recDatasDi, "到位", fixtureReady);
    setInputValue(recDatasDi, "启动", overallTesting);

    if (leak1HasResult) {
        setInputValue(recDatasDi, "合格1", leak1Result);
        setInputValue(recDatasDi, "R端NG1", !leak1Result);
        setInputValue(recDatasDi, "T端NG1", !leak1Result);
        setInputValue(recDatasDi, "报警1", false);
    } else {
        setInputValue(recDatasDi, "合格1", false);
        setInputValue(recDatasDi, "R端NG1", false);
        setInputValue(recDatasDi, "T端NG1", false);
        setInputValue(recDatasDi, "报警1", false);
    }

//    static quint16 lastD1901 = 0xffff;
//    if (plc_D1901 != lastD1901) {
//        lastD1901 = plc_D1901;
//        qDebug() << "[PLC]"
//                 << "D1901=" << plc_D1901
//                 << "工装到位=" << fixtureReady
//                 << "整体有结果=" << overallHasResult
//                 << "整体结果=" << overallResult
//                 << "检漏1有结果=" << leak1HasResult
//                 << "检漏1结果=" << leak1Result
//                 << "检漏2有结果=" << leak2HasResult
//                 << "检漏2结果=" << leak2Result
//                 << "D90=" << plc_D90
//                 << "D91=" << plc_D91;
//    }
    static quint16 lastD1901 = 0xffff;
    static quint16 lastD90 = 0xffff;
    static quint16 lastD91 = 0xffff;
    static quint16 lastD1902 = 0xffff;
    static quint16 lastD1903 = 0xffff;
    static quint16 lastN10 = 0xffff;
    static QString lastSoftwareChannel;
    static int lastAteqEnable = -1;

    const QString softwareChannel = CurWorkPar.channel;
    const int ateqEnable = CurWorkPar.ATEQ_Enable;

    const bool changed =
            plc_D1901 != lastD1901 ||
            plc_D90 != lastD90 ||
            plc_D91 != lastD91 ||
            plc_D1902 != lastD1902 ||
            plc_D1903 != lastD1903 ||
            plc_N10 != lastN10 ||
            softwareChannel != lastSoftwareChannel ||
            ateqEnable != lastAteqEnable;

    if (changed) {
        lastD1901 = plc_D1901;
        lastD90 = plc_D90;
        lastD91 = plc_D91;
        lastD1902 = plc_D1902;
        lastD1903 = plc_D1903;
        lastN10 = plc_N10;
        lastSoftwareChannel = softwareChannel;
        lastAteqEnable = ateqEnable;

        qDebug() << "[PLC_CHANNEL]"
                 << "softwareChannel=" << softwareChannel
                 << "ATEQ=" << ateqEnable
                 << "targetD1902=" << targetProductWordForLeak1()
                 << "targetD1903=" << targetProductWordForLeak2()
                 << "writeD1902=" << plc_D1902
                 << "writeD1903=" << plc_D1903
                 << "feedbackD90=" << plc_D90
                 << "feedbackD91=" << plc_D91
                 << "N10=" << plc_N10
                 << "D1901=" << plc_D1901;
    }
}

void mModbusRtu::slot_ReadDiscreteInputs()
{
    if (!b_modbus_port_en) {
        return;
    }
    QMutexLocker locker(&mutex);
    const bool readOk = plcReadWord("D1901", plc_D1901)
            && plcReadWord("D90", plc_D90)
            && plcReadWord("D91", plc_D91);
    quint16 n10Value = 0;
    if (plcReadWord("N10", n10Value)) {
        plc_N10 = n10Value;
    } else {
        plc_N10 = 0;
    }
    errorCode_Sec = readOk ? "NoError" : "PLC ReadError";
    syncPlcWordsToInputs();
    B_Rec_Finished = true;
}

void mModbusRtu::slot_ReadInputRegisters()
{
    if (!b_modbus_port_en) {
        return;
    }
    QMutexLocker locker(&mutex);
    const bool readOk = plcReadWord("D1901", plc_D1901)
            && plcReadWord("D90", plc_D90)
            && plcReadWord("D91", plc_D91);
    quint16 n10Value = 0;
    if (plcReadWord("N10", n10Value)) {
        plc_N10 = n10Value;
    } else {
        plc_N10 = 0;
    }
    errorCode_Sec = readOk ? "NoError" : "PLC ReadError";
    syncPlcWordsToInputs();
    B_Rec_Finished = true;
}

void mModbusRtu::slot_ReadCoils()
{
    if (!b_modbus_port_en) {
        return;
    }
    for (int i = 0; i < recDatasCo.size(); ++i) {
        recDatasCo[i] = Wdata.value(i);
    }
}

void mModbusRtu::slot_WriteCoils()
{
    if (!b_modbus_port_en) {
        return;
    }
    QMutexLocker locker(&mutex);
    syncOutputsToPlcWords();
    plc_test_tick++;
    if (plc_test_enable && plc_test_tick >= 50) { // around 5s at 100ms polling
        plc_test_tick = 0;
        qDebug() << "[PLC_TEST]"
                 << "D1900=" << plc_D1900
                 << "D1901=" << plc_D1901
                 << "D1902=" << plc_D1902
                 << "D1903=" << plc_D1903
                 << "D90=" << plc_D90
                 << "D91=" << plc_D91
                 << "N10=" << plc_N10;
    }
    B_Rec_Finished = true;
}

void mModbusRtu::_RD_OnReadReady()
{
    // Reserved for real PLC protocol callback implementation.
}

void mModbusRtu::_WR_OnReadReady()
{
    // Reserved for real PLC protocol callback implementation.
}

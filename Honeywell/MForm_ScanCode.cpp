#include "MForm_ScanCode.h"
#include "ui_MForm_ScanCode.h"
#include <QSettings>
#include <QTextCodec>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <ui_MForm_ScanCode.h>

bool b_SaoMa_Fin = false;

QString BarCode;
MForm_ScanCode *m_Form_ScanCode;
MForm_ScanCode::MForm_ScanCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MForm_ScanCode)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    load_File_INI();

    ptimer = new QTimer(this);
    ptimer->setSingleShot(true);
    connect(ptimer, &QTimer::timeout, this, &MForm_ScanCode::slot_readAll);

    ptimer_2 = new QTimer(this);
    ptimer_2->setSingleShot(true);
    connect(ptimer_2, &QTimer::timeout, this, &MForm_ScanCode::slot_readAll_2);
    connect(this, &MForm_ScanCode::sign_WriteDatas, this, &MForm_ScanCode::slot_WriteDatas);

    ui->groupBox_2->hide();
}

MForm_ScanCode::~MForm_ScanCode()
{
    if(m_serialPort != nullptr){
        m_serialPort->close();
    }
    if(m_serialPort_2 != nullptr){
        m_serialPort_2->close();
    }
    delete ui;
}
/**
 * @brief MForm_ScanCode::load_File_INI 加载扫码枪串口参数
 */
void MForm_ScanCode::load_File_INI()
{
    QString filepath = QApplication::applicationDirPath() + "/System/System.ini";
   QSettings *INI_File = new QSettings(filepath, QSettings::IniFormat);
   INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

   INI_File->beginGroup("Serial_ScanCode");
   port = INI_File->value("Port").toString();
   baud = INI_File->value("Baud").toString();
   port_2 = INI_File->value("Port_2").toString();
   baud_2 = INI_File->value("Baud_2").toString();
   INI_File->endGroup();

   INI_File->destroyed();

   QList<QSerialPortInfo> coms = QSerialPortInfo::availablePorts();
   ui->Cbt_Port->addItem("");
   ui->Cbt_Port_2->addItem("");
   for(int i=0 ;i<coms.count(); i++){
       ui->Cbt_Port->addItem(coms.at(i).portName());
       ui->Cbt_Port_2->addItem(coms.at(i).portName());
   }
   ui->Cbt_Port->setCurrentText(port);
   ui->Cbt_Buad->setCurrentText(baud);
   ui->Cbt_Port_2->setCurrentText(port_2);
   ui->Cbt_Buad_2->setCurrentText(baud_2);
//    slot_Tips(1, "导出扫码枪串口参数");
//    slot_Tips(2, "导出扫码枪串口参数");
    slot_Tips(1, "Barcode scanner serial port opened");
    slot_Tips(2, " Export barcode scanner serial port parameters");
   ui->Btn_OpenClose->clicked();
   ui->Btn_OpenClose_2->clicked();
}

void MForm_ScanCode::on_Btn_Save_clicked()
{

    QString filepath = QApplication::applicationDirPath() + "/System/System.ini";

    QSettings *INI_File = new QSettings(filepath, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("Serial_ScanCode");

    INI_File->setValue("Port", ui->Cbt_Port->currentText());
    INI_File->setValue("Baud", ui->Cbt_Buad->currentText());

    INI_File->setValue("Port_2", ui->Cbt_Port_2->currentText());
    INI_File->setValue("Baud_2", ui->Cbt_Buad_2->currentText());

    INI_File->endGroup();
    INI_File->destroyed();
}

void MForm_ScanCode::on_Btn_OpenClose_clicked()
{
    port = ui->Cbt_Port->currentText();
    baud = ui->Cbt_Buad->currentText();

    if(!b_open){
        if(m_serialPort != nullptr){
            m_serialPort->deleteLater();
            m_serialPort = nullptr;
        }
        m_serialPort = new QSerialPort(this);
        m_serialPort->setPortName(port);
        m_serialPort->setBaudRate(baud.toInt());
        m_serialPort->setDataBits(QSerialPort::Data8);
        m_serialPort->setParity(QSerialPort::NoParity);
        m_serialPort->setStopBits(QSerialPort::OneStop);

        if(m_serialPort->open(QIODevice::ReadWrite)){
            b_open = true;
            m_serialPort->flush();
            slot_Tips(1, "Barcode scanner serial port opened");
            connect(m_serialPort, &QSerialPort::readyRead, this, &MForm_ScanCode::slot_readRead);
            ui->Btn_Update->setEnabled(false);
            ui->Cbt_Port->setEnabled(false);
            ui->Cbt_Buad->setEnabled(false);
        }else{
            slot_Tips(1, "Failed to open scanner serial port: " + m_serialPort->errorString());
            m_serialPort->deleteLater();
            m_serialPort = nullptr;
        }
    }else{

        b_open = false;
        slot_Tips(1, "Close scanner serial port");
        if(m_serialPort != nullptr){
            disconnect(m_serialPort, &QSerialPort::readyRead, this, &MForm_ScanCode::slot_readRead);
            m_serialPort->close();
            m_serialPort->deleteLater();
            m_serialPort = nullptr;
        }

        ui->Btn_Update->setEnabled(true);
        ui->Cbt_Port->setEnabled(true);
        ui->Cbt_Buad->setEnabled(true);
    }
}
void MForm_ScanCode::on_Btn_OpenClose_2_clicked()
{
    port_2 = ui->Cbt_Port_2->currentText();
    baud_2 = ui->Cbt_Buad_2->currentText();

    if(!b_open_2){
        if(m_serialPort_2 != nullptr){
            m_serialPort_2->deleteLater();
            m_serialPort_2 = nullptr;
        }
        m_serialPort_2 = new QSerialPort(this);
        m_serialPort_2->setPortName(port_2);
        m_serialPort_2->setBaudRate(baud_2.toInt());
        m_serialPort_2->setDataBits(QSerialPort::Data8);
        m_serialPort_2->setParity(QSerialPort::NoParity);
        m_serialPort_2->setStopBits(QSerialPort::OneStop);

        if(m_serialPort_2->open(QIODevice::ReadOnly)){
            b_open_2 = true;
            m_serialPort_2->flush();
            slot_Tips(2, "Scanner serial port opened successfully");
            connect(m_serialPort_2, &QSerialPort::readyRead, this, &MForm_ScanCode::slot_readRead_2);
            ui->Btn_Update_2->setEnabled(false);
            ui->Cbt_Port_2->setEnabled(false);
            ui->Cbt_Buad_2->setEnabled(false);
        }else{
            slot_Tips(2, "Failed to open scanner serial port: " + m_serialPort_2->errorString());
            m_serialPort_2->deleteLater();
            m_serialPort_2 = nullptr;
        }
    }else{

        b_open_2 = false;
        slot_Tips(2, "Close scanner serial port");
        if(m_serialPort_2 != nullptr){
            disconnect(m_serialPort_2, &QSerialPort::readyRead, this, &MForm_ScanCode::slot_readRead_2);
            m_serialPort_2->close();
            m_serialPort_2->deleteLater();
            m_serialPort_2 = nullptr;
        }

        ui->Btn_Update_2->setEnabled(true);
        ui->Cbt_Port_2->setEnabled(true);
        ui->Cbt_Buad_2->setEnabled(true);
    }
}

void MForm_ScanCode::on_Btn_Update_clicked()
{
    ui->Cbt_Port->clear();
    QList<QSerialPortInfo> coms = QSerialPortInfo::availablePorts();
    ui->Cbt_Port->addItem("");
    for(int i=0 ;i<coms.count(); i++){
        ui->Cbt_Port->addItem(coms.at(i).portName());
    }
}

void MForm_ScanCode::on_Btn_Update_2_clicked()
{
    ui->Cbt_Port_2->clear();
    QList<QSerialPortInfo> coms = QSerialPortInfo::availablePorts();
    ui->Cbt_Port_2->addItem("");
    for(int i=0 ;i<coms.count(); i++){
        ui->Cbt_Port_2->addItem(coms.at(i).portName());
    }
}

void MForm_ScanCode::slot_Tips(int id, QString mesg)
{
    if(id == 1){
        ui->textBrowser->append(QTime::currentTime().toString() + "：" + mesg);
    }else if(id == 2){
        ui->textBrowser_2->append(QTime::currentTime().toString() + "：" + mesg);
    }
}
/**
 * @brief MForm_ScanCode::slot_readRead 拼接数据
 */
void MForm_ScanCode::slot_readRead()
{
    if(m_serialPort == nullptr || !m_serialPort->isOpen()){
        return;
    }
    QByteArray mbyteArray = m_serialPort->readAll();
    if(ptimer->isActive()){
        _byteArray += mbyteArray;
    }else{
        _byteArray = mbyteArray;
        ptimer->start(50);
    }
}

/**
 * @brief MForm_ScanCode::slot_readAll 接收完所有数据
 */
void MForm_ScanCode::slot_readAll()
{
    qDebug() << s_codeType << " Barcode scanner Info：" << _byteArray;
    slot_Tips(1, s_codeType + " Barcode scanner Info：" + _byteArray);

    BarCode = QString::fromLocal8Bit(_byteArray).trimmed();
    if(!BarCode.isEmpty()){
        emit sign_barcodeReceived(BarCode);
    }else{
        slot_Tips(1, "Barcode scanner Info");
    }
    _byteArray.clear();
}
/**
 * @brief MForm_ScanCode::slot_WriteDatas   写数据
 * @param send_byte
 */
void MForm_ScanCode::slot_WriteDatas(QByteArray send_byte)
{
    if(m_serialPort == nullptr || !b_open || !m_serialPort->isOpen() || !m_serialPort->isWritable()){
        const QString reason = "Scanner trigger command write failed";
        slot_Tips(1, reason);
        emit sign_scanWriteFailed(reason);
        return;
    }

    const qint64 written = m_serialPort->write(send_byte);
    if(written != send_byte.size()){
        const QString reason = "Scanner trigger command write failed";
        slot_Tips(1, reason + ": " + m_serialPort->errorString());
        emit sign_scanWriteFailed(reason);
        return;
    }
    slot_Tips(1, QString::fromLocal8Bit(send_byte));
}

/**
 * @brief MForm_ScanCode::slot_readRead 拼接数据
 */
void MForm_ScanCode::slot_readRead_2()
{
    if(m_serialPort_2 == nullptr || !m_serialPort_2->isOpen()){
        return;
    }
    QByteArray mbyteArray = m_serialPort_2->readAll();
    if(ptimer_2->isActive()){
        _byteArray_2 += mbyteArray;
    }else{
        _byteArray_2 = mbyteArray;
        ptimer_2->start(30);
    }
}
/**
 * @brief MForm_ScanCode::slot_readAll 接收完所有数据
 */
void MForm_ScanCode::slot_readAll_2()
{
    qDebug() << s_codeType << " Barcode scanner Info：" << _byteArray_2;
    slot_Tips(2, s_codeType + " Barcode scanner Info：" + _byteArray_2);
    if(s_codeType == "Part scanning"){
        slot_Tips(2, "Part scanning：" + _byteArray_2);
//        BarCode = QString::fromLocal8Bit(_byteArray);
//        MainWindow::mutualUi->judgeCode(BarCode);

    }else if(s_codeType == "Rework scanning"){
        slot_Tips(2, "Rework scanning：" + _byteArray_2);
    }
    _byteArray_2.clear();
}
void MForm_ScanCode::download_Objects(const QString &arg1)
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + tr("/Language/%1_%2.ini").arg(objectName(), arg1), QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("QPushButton");
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for(int i=0; i<buttons.size(); i++){
        INI_File->setValue(buttons.at(i)->objectName(), buttons.at(i)->text());
    }
    INI_File->endGroup();

    INI_File->beginGroup("QLabel");
    QList<QLabel*> labels = findChildren<QLabel*>();
    for(int i=0; i<labels.size(); i++){
        INI_File->setValue(labels.at(i)->objectName(), labels.at(i)->text());
    }
    INI_File->endGroup();
    INI_File->destroyed();
}

/**
 * @brief MForm_ScanCode::getObject
 * @param arg1
 */
void MForm_ScanCode::upload_Objects(const QString &arg1)
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + tr("/Language/%1_%2.ini").arg(objectName(), arg1), QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    QStringList list_childkeys;

    INI_File->beginGroup("QPushButton");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QPushButton *object = findChild<QPushButton*>(name);
        if(object){
            object->setText(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->beginGroup("QLabel");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QLabel *object = findChild<QLabel*>(name);
        if(object){
            object->setText(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();
    INI_File->destroyed();
}

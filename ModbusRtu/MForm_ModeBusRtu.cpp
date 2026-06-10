#include "MForm_ModeBusRtu.h"
#include "ui_MForm_ModeBusRtu.h"
A1_MForm_ModeBusRtu mS_BSMIO;
MForm_ModeBusRtu *m_Form_ModeBusRtu;

static QStringList GetUarts()//获取串口资源
{
    //获取当前计算机所有串口设备
    QList<QSerialPortInfo> coms = QSerialPortInfo::availablePorts();
    QStringList list_ports;
    for(int i=0; i<coms.size(); i++){
        list_ports.append(coms[i].portName());
    }
    return list_ports;
}

MForm_ModeBusRtu::MForm_ModeBusRtu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MForm_ModeBusRtu)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);

    ui->led_tips->hide();
    m_Dialog485 = new QDialog(MFormJLStation::mutualUi);
    m_Dialog485->setWindowTitle("Question?");
    m_Dialog485->setWindowFlags(Qt::Dialog);
    m_Dialog485->setMinimumSize(QSize(300, 60));
    QHBoxLayout *hLayout = new QHBoxLayout();
    label485 = new QLabel();
    m_Dialog485->setStyleSheet("background-color: red;");
    hLayout->addWidget(label485);
    m_Dialog485->setLayout(hLayout);

    Init_TableWidget();
    loadFile();

    ui->RS485Com->addItems(GetUarts());
    load_File_INI();
    m_ModbusRtu = new mModbusRtu();
//    connect(m_ModbusRtu, &mModbusRtu::sign_setled_cicular, MFormJLStation::mutualUi, &MFormJLStation::slot_setled_cicular);
    connect(m_ModbusRtu, &mModbusRtu::Sign_COMStyleSheet,  this, &MForm_ModeBusRtu::Slot_COMStyleSheet);
    connect(this, &MForm_ModeBusRtu::sign_OpenComBSM, m_ModbusRtu, &mModbusRtu::slot_OpCl_Device);
    connect(this, &MForm_ModeBusRtu::sign_ReadDiscreteInputs, m_ModbusRtu, &mModbusRtu::slot_ReadDiscreteInputs);
    connect(this, &MForm_ModeBusRtu::sign_reConnect_Rtu, m_ModbusRtu, &mModbusRtu::reConnectDevice);
    connect(this, &MForm_ModeBusRtu::sign_ReadCoils, m_ModbusRtu, &mModbusRtu::slot_ReadCoils);
    connect(this, &MForm_ModeBusRtu::sign_WriteCoils, m_ModbusRtu, &mModbusRtu::slot_WriteCoils);
    m_ModbusRtu->pthread->start();

    connect(ptimer, &QTimer::timeout, this, &MForm_ModeBusRtu::slot_Timeout);
    ptimer->start(100);
}

MForm_ModeBusRtu::~MForm_ModeBusRtu()
{
    delete ui;
}
/**
 * @brief MForm_ModeBusRtu::slot_Timeout    定时任务
 */
void MForm_ModeBusRtu::slot_Timeout()
{
    if(isVisible()){
        m_Form_ModeBusRtu->RealUpdate_BSM_Display();
    }

    if(m_ModbusRtu != nullptr){
        if(m_ModbusRtu->b_modbus_port_en){
            emit sign_WriteCoils();
            emit sign_ReadDiscreteInputs();
        }
    }

    if(m_ModbusRtu->errorCode_Sec == "NoError" && m_ModbusRtu->errorCode_Occur == "NoError"){
        m_Dialog485->hide();
    }else if(m_ModbusRtu->errorCode_Occur != "NoError"){
        label485->setText("Is the serial port of the device lost?");
        m_Dialog485->show();
    }else if(m_ModbusRtu->errorCode_Sec != "NoError" || m_ModbusRtu->errorCode_Occur == "NoError"){
        label485->setText(m_ModbusRtu->errorCode_Sec);
        m_Dialog485->show();
    }

    ui->led_tips->setText(m_ModbusRtu->errorCode_Connect + "/" + m_ModbusRtu->errorCode_Occur + "/" + m_ModbusRtu->errorCode_Sec);
}
/**
 * @brief MForm_ModeBusRtu::Slot_COMStyleSheet
 * @param name
 * @param b_value
 */
void MForm_ModeBusRtu::Slot_COMStyleSheet(const QString &name, bool b_value)
{
    if(name == "PLC"){
        if(b_value){
            slot_setled_cicular(ui->led_485, _m_color::Green);
            slot_setled_cicular(MFormJLStation::mutualUi->ui->led_485, _m_color::Green);
        }else{
            slot_setled_cicular(ui->led_485, _m_color::Red);
            slot_setled_cicular(MFormJLStation::mutualUi->ui->led_485, _m_color::Red);
        }
        ui->RS485Com->setEnabled(!b_value);
        ui->Btn_Updata_Com->setEnabled(!b_value);
        ui->Cbt_Baud_RS485->setEnabled(!b_value);
    }
}
/**
 * @brief MFormJLStation::slot_setled_cicular   改变样式表为圆形
 * @param label
 * @param color
 */
void MForm_ModeBusRtu::slot_setled_cicular(QLabel *label, const int color)
{
    if(label == nullptr || color < 0 || color >= _mColorName.size()){
        return;
    }
    QString sheet = _mColorName.at(color);
    sheet += QString("border-radius: %1px;").arg(label->width() / 2);
    sheet += "border: 1px solid black;";
    label->setStyleSheet(sheet);
}
/**
 * @brief MForm_ModeBusRtu::Init_TableWidget   初始化配置表格
 */
void MForm_ModeBusRtu::Init_TableWidget()
{
    QStringList hlabels;
    hlabels << "Di-Input" << "No." << "Co-Output" << "Open/Close";
    ui->led_BSM_1->setColumnCount(6);
    ui->led_BSM_1->setRowCount(16);
    ui->led_BSM_1->setHorizontalHeaderLabels(hlabels);

    ui->led_BSM_2->setColumnCount(6);
    ui->led_BSM_2->setRowCount(16);
    ui->led_BSM_2->setHorizontalHeaderLabels(hlabels);

    ui->led_BSM_1->setColumnHidden(4, true);
    ui->led_BSM_1->setColumnHidden(5, true);
    ui->led_BSM_2->setColumnHidden(4, true);
    ui->led_BSM_2->setColumnHidden(5, true);

    for(int i=0; i<16; i++){
        ui->led_BSM_1->setItem(i, 0, new QTableWidgetItem);
        ui->led_BSM_1->setItem(i, 1, new QTableWidgetItem(QString::number(i+1)));
        ui->led_BSM_1->setItem(i, 2, new QTableWidgetItem);
        ui->led_BSM_1->setItem(i, 3, new QTableWidgetItem);
        ui->led_BSM_1->setItem(i, 4, new QTableWidgetItem);
        ui->led_BSM_1->setItem(i, 5, new QTableWidgetItem);

        ui->led_BSM_2->setItem(i, 0, new QTableWidgetItem);
        ui->led_BSM_2->setItem(i, 1, new QTableWidgetItem(QString::number(i+1)));
        ui->led_BSM_2->setItem(i, 2, new QTableWidgetItem);
        ui->led_BSM_2->setItem(i, 3, new QTableWidgetItem);
        ui->led_BSM_2->setItem(i, 4, new QTableWidgetItem);
        ui->led_BSM_2->setItem(i, 5, new QTableWidgetItem);
    }
    //基板
    ui->led_BSM_1->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->led_BSM_1->setColumnWidth(1, 60);
    ui->led_BSM_1->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->led_BSM_1->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->led_BSM_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //扩展板
    ui->led_BSM_2->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->led_BSM_2->setColumnWidth(1, 60);
    ui->led_BSM_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->led_BSM_2->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->led_BSM_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    BtnGroup = new QButtonGroup(this);
    for(int i=0; i<16; i++){
        QPushButton *btn = new QPushButton("On/Off");
        BtnGroup->addButton(btn, i+1);
        ui->led_BSM_1->setCellWidget(i, 3, btn);
    }
    for(int i=0; i<16; i++){
        QPushButton *btn = new QPushButton("On/Off");
        BtnGroup->addButton(btn, i+17);
        ui->led_BSM_2->setCellWidget(i, 3, btn);
    }
    connect(BtnGroup, SIGNAL(buttonClicked(int)), this, SLOT(Slot_AddBtnID(int)));
}
/**
 * @brief MForm_ModeBusRtu::loadFile    下载配置文件
 */
void MForm_ModeBusRtu::loadFile()
{
    if(!QFile::exists(QApplication::applicationDirPath() + "/System/BSM_language.ini")){
        return;
    }
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/BSM_language.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    mS_BSMIO.IO_XY.clear();
    for(int i=0; i<32; ++i){
        INI_File->beginGroup("IO_" + QString::number(i));
        QString itemDi = INI_File->value("language_ch_Di").toString();
        QString itemCo = INI_File->value("language_ch_Co").toString();
        mS_BSMIO.IO_XY.insert(itemDi, i);
        mS_BSMIO.IO_XY.insert(itemCo, i);

        QString itemLB_Di_0, itemLB_Co_0;
        if(Language == "CN"){

            itemLB_Di_0 = itemDi;
            itemLB_Co_0 = itemCo;

        }else if(Language == "EN"){

            itemLB_Di_0 = INI_File->value("language_en_Di").toString();
            itemLB_Co_0 = INI_File->value("language_en_Co").toString();

        }else if(Language == "RU"){

            itemLB_Di_0 = INI_File->value("language_ru_Di").toString();
            itemLB_Co_0 = INI_File->value("language_ru_Co").toString();
        }

        if(i<16){
            ui->led_BSM_1->item(i, 0)->setText(itemLB_Di_0);
            ui->led_BSM_1->item(i, 2)->setText(itemLB_Co_0);
            ui->led_BSM_1->item(i, 4)->setText(itemDi);
            ui->led_BSM_1->item(i, 5)->setText(itemCo);
        }else{
            ui->led_BSM_2->item(i-16, 0)->setText(itemLB_Di_0);
            ui->led_BSM_2->item(i-16, 2)->setText(itemLB_Co_0);
            ui->led_BSM_2->item(i-16, 4)->setText(itemDi);
            ui->led_BSM_2->item(i-16, 5)->setText(itemCo);
        }

        INI_File->endGroup();
    }
    INI_File->destroyed();
}

void MForm_ModeBusRtu::on_Btn_RS485_clicked()//打开/关闭 BSM
{
    mS_BSMIO.BSM_PORT = ui->RS485Com->currentText();
    mS_BSMIO.BSM_BUAD = ui->Cbt_Baud_RS485->currentText();
    emit sign_OpenComBSM(mS_BSMIO.BSM_PORT, mS_BSMIO.BSM_BUAD.toUInt(), 8, 1, 0);
}


//  ************************************************************************************************    获取按键
void MForm_ModeBusRtu::Slot_AddBtnID(int id)
{
    if(m_ModbusRtu->Wdata.value(id - 1) == 1){
        m_ModbusRtu->Wdata.setValue(id - 1, 0);
    }else if(m_ModbusRtu->Wdata.value(id - 1) == 0){
        m_ModbusRtu->Wdata.setValue(id - 1, 1);
    }
}

void MForm_ModeBusRtu::load_File_INI()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    mS_BSMIO.BSM_PORT = INI_File->value("ModbusRtu/BSM_PORT", "COM1").toString();
    mS_BSMIO.BSM_BUAD = INI_File->value("ModbusRtu/BSM_BUAD", "19200").toString();

    INI_File->destroyed();

    ui->RS485Com->setCurrentText(mS_BSMIO.BSM_PORT);
    ui->Cbt_Baud_RS485->setCurrentText(mS_BSMIO.BSM_BUAD);
}

void MForm_ModeBusRtu::on_Btn_Save_clicked()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    //串口通讯
    mS_BSMIO.BSM_PORT = ui->RS485Com->currentText();
    INI_File->setValue("ModbusRtu/BSM_PORT", ui->RS485Com->currentText());
    mS_BSMIO.BSM_BUAD = ui->Cbt_Baud_RS485->currentText();
    INI_File->setValue("ModbusRtu/BSM_BUAD", ui->Cbt_Baud_RS485->currentText());

    INI_File->destroyed();
}

void MForm_ModeBusRtu::on_Btn_Updata_Com_clicked()
{
    if(ui->RS485Com->isEnabled()){
        ui->RS485Com->clear();
        ui->RS485Com->addItem("");
        ui->RS485Com->addItems(GetUarts());
    }
}

void MForm_ModeBusRtu::RealUpdate_BSM_Display()//实时刷新输入输出点
{
    for(int i=0; i<32; i++){
        if(i<16){
            //BSM1.0
            if(m_ModbusRtu->recDatasDi.value(i) == 1){
                ui->led_BSM_1->item(i, 0)->setBackground(QBrush(QColor(0, 255, 0)));
            }else{
                ui->led_BSM_1->item(i, 0)->setBackground(QBrush(QColor(255, 255, 255)));
            }
            if(m_ModbusRtu->recDatasCo.value(i) == 1){
                ui->led_BSM_1->item(i, 2)->setBackground(QBrush(QColor(0, 255, 0)));
            }else{
                ui->led_BSM_1->item(i, 2)->setBackground(QBrush(QColor(255, 255, 255)));
            }

        }else{
            //BSM1.1
            if(m_ModbusRtu->recDatasDi.value(i) == 1){
                ui->led_BSM_2->item(i-16, 0)->setBackground(QBrush(QColor(0, 255, 0)));
            }else{
                ui->led_BSM_2->item(i-16, 0)->setBackground(QBrush(QColor(255, 255, 255)));
            }
            if(m_ModbusRtu->recDatasCo.value(i) == 1){
                ui->led_BSM_2->item(i-16, 2)->setBackground(QBrush(QColor(0, 255, 0)));
            }else{
                ui->led_BSM_2->item(i-16, 2)->setBackground(QBrush(QColor(255, 255, 255)));
            }

        }

    }
}
/**
 * @brief MForm_ModeBusRtu::on_Btn_loadfile_clicked 刷新配置文件
 */
void MForm_ModeBusRtu::on_Btn_loadfile_clicked()
{
    loadFile();
}

void MForm_ModeBusRtu::on_Btn_board_1_toggled(bool checked)
{
    ui->led_BSM_1->setColumnHidden(4, !checked);
    ui->led_BSM_1->setColumnHidden(5, !checked);
}

void MForm_ModeBusRtu::on_Btn_board_2_toggled(bool checked)
{
    ui->led_BSM_2->setColumnHidden(4, !checked);
    ui->led_BSM_2->setColumnHidden(5, !checked);
}


/**
 * @brief MFormMysql::download_Objects  下载
 * @param arg1
 */
void MForm_ModeBusRtu::download_Objects(const QString &arg1)
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
 * @brief MForm_ScanCode::getObject 上传
 * @param arg1
 */
void MForm_ModeBusRtu::upload_Objects(const QString &arg1)
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

#include "MFormATEQ.h"
#include "ui_MFormATEQ.h"

MFormATEQ *m_FormATEQ;
MS_MFormATEQ ms_MFormATEQ;

static QStringList list_ColorNames = {"gray", "red", "green", "yellow", "white", "black", "#ffaa00"};
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

static void setComboTextOrDefault(QComboBox *combo, const QString &value, const QString &fallback)
{
    const QString target = value.isEmpty() ? fallback : value;
    if(combo->findText(target) < 0){
        combo->addItem(target);
    }
    combo->setCurrentText(target);
}

MFormATEQ::MFormATEQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MFormATEQ)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    setWindowTitle("ATEQ Serial Port Setting");

    ui->CBB_COM_JL_1->addItems(GetUarts());
    ui->CBB_COM_JL_2->addItems(GetUarts());

    loadFileINI();

    m_ComThread = new mComThread();//多串口线程

    m_COMLeakHunting = new COMLeakHunting();
    connect(this, &MFormATEQ::sign_OpenCom_JL_1, m_COMLeakHunting, &COMLeakHunting::Init_Port_1);
    connect(m_COMLeakHunting, &COMLeakHunting::sign_tips, this, &MFormATEQ::slot_Tips);
    connect(m_COMLeakHunting, &COMLeakHunting::sign_ATEQ_RawDisplay,
            this, &MFormATEQ::slot_updateAteqRawDisplay);
//    connect(m_COMLeakHunting, &COMLeakHunting::Sign_COMStyleSheet, MainWindow::mutualUi, &MainWindow::Slot_COMStyleSheet);
//    connect(m_COMLeakHunting, &COMLeakHunting::Sign_Setled, MainWindow::mutualUi, &MainWindow::slot_setled);

    m_COMLeakHunting_2 = new COMLeakHunting_2();
    connect(this, &MFormATEQ::sign_OpenCom_JL_2, m_COMLeakHunting_2, &COMLeakHunting_2::Init_Port_2);
    connect(m_COMLeakHunting_2, &COMLeakHunting_2::sign_tips, this, &MFormATEQ::slot_Tips);
    connect(m_COMLeakHunting_2, &COMLeakHunting_2::sign_ATEQ_RawDisplay,
            this, &MFormATEQ::slot_updateAteqRawDisplay);
//    connect(m_COMLeakHunting_2, &COMLeakHunting_2::Sign_COMStyleSheet, MainWindow::mutualUi, &MainWindow::Slot_COMStyleSheet);
//    connect(m_COMLeakHunting_2, &COMLeakHunting_2::Sign_Setled, MainWindow::mutualUi, &MainWindow::slot_setled);

    m_ComThread->pthread->start();

    ui->frame_ATEQ->hide();
    ui->frame_ATEQ_2->hide();

    // ATEQ2 is COM2 on site, keep the second port controls visible.
}

MFormATEQ::~MFormATEQ()
{
    delete ui;
}
/**
 * @brief MFormATEQ::slot_Tips  日志记录
 * @param mesg
 * @param color_id
 */
//void MFormATEQ::slot_Tips(const QString mesg, int color_id)//日志记录
//{
//    QString tips = QTime::currentTime().toString("hh:mm:ss.zzz") + " | " + mesg;
//    ui->textBrowser->append(tr("<p style='color:%1;'>").arg(list_ColorNames.at(color_id)) + tips + "</p>");
//}

void MFormATEQ::slot_Tips(const QString &mesg, int color_id) {
    QString tips = QTime::currentTime().toString("hh:mm:ss.zzz") + " | " + mesg;
    QString html = tr("<span style='color:%1;'>%2</span>")
                   .arg(list_ColorNames.at(color_id))
                   .arg(tips.toHtmlEscaped());

    // 移动到文档末尾
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);

    // 插入HTML并换行
    cursor.insertHtml(html);
    cursor.insertText("\n");

//    // 自动滚动到底部
//    ui->textBrowser->setTextCursor(cursor);
//    ui->textBrowser->ensureCursorVisible();
}

void MFormATEQ::slot_updateAteqRawDisplay(int device, const QString &raw, bool ok)
{
    QLabel *label = nullptr;
    if(device == 1){
        label = ui->led_ATEQ_Res_1;
    }else if(device == 2){
        label = ui->led_ATEQ_Res_2;
    }

    if(label == nullptr){
        return;
    }

    const int colorIndex = ok ? m_color::Green : m_color::Red;
    label->setText(raw);
    label->setStyleSheet(QString("background-color:%1;").arg(list_ColorNames.at(colorIndex)));
}

/**
 * @brief MFormATEQ::loadFileINI    加载INI文件
 */
void MFormATEQ::loadFileINI()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("JL");
    setComboTextOrDefault(ui->CBB_COM_JL_1, INI_File->value("Port_1").toString(), "COM4");
    setComboTextOrDefault(ui->CBB_COM_JL_2, INI_File->value("Port_2").toString(), "COM2");
    ui->CBB_Buad_JL_1->setCurrentText(INI_File->value("Buad_1").toString());
    ui->CBB_Buad_JL_2->setCurrentText(INI_File->value("Buad_2").toString());
    INI_File->endGroup();
    INI_File->destroyed();

    ms_MFormATEQ.Port_1 = ui->CBB_COM_JL_1->currentText();
    ms_MFormATEQ.Port_2 = ui->CBB_COM_JL_2->currentText();
    ms_MFormATEQ.Buad_1 = ui->CBB_Buad_JL_1->currentText();
    ms_MFormATEQ.Buad_2 = ui->CBB_Buad_JL_2->currentText();

}

void MFormATEQ::on_BTN_Save_clicked()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("JL");
    //串口通讯
    INI_File->setValue("Port_1", ui->CBB_COM_JL_1->currentText());
    INI_File->setValue("Buad_1", ui->CBB_Buad_JL_1->currentText());

    INI_File->setValue("Port_2", ui->CBB_COM_JL_2->currentText());
    INI_File->setValue("Buad_2", ui->CBB_Buad_JL_2->currentText());

    INI_File->endGroup();

    INI_File->destroyed();

    ms_MFormATEQ.Port_1 = ui->CBB_COM_JL_1->currentText();
    ms_MFormATEQ.Buad_1 = ui->CBB_Buad_JL_1->currentText();
    ms_MFormATEQ.Port_2 = ui->CBB_COM_JL_2->currentText();
    ms_MFormATEQ.Buad_2 = ui->CBB_Buad_JL_2->currentText();
}

void MFormATEQ::on_Btn_JL_1_clicked()    //打开检漏1串口
{
    ms_MFormATEQ.Port_1 = ui->CBB_COM_JL_1->currentText();
    emit sign_OpenCom_JL_1();
}

void MFormATEQ::on_Btn_JL_2_clicked()    //打开检漏2串口
{
    ms_MFormATEQ.Port_2 = ui->CBB_COM_JL_2->currentText();
    emit sign_OpenCom_JL_2();
}

void MFormATEQ::download_Objects(const QString &arg1)
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
 * @brief MFormJLStation::getObject
 * @param arg1
 */
void MFormATEQ::upload_Objects(const QString &arg1)
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

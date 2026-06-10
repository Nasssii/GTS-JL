#include "MForm_PrintSetting.h"
#include "ui_MForm_PrintSetting.h"


MForm_PrintSetting *m_Form_PrintSetting;

MForm_PrintSetting::MForm_PrintSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MForm_PrintSetting)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_QuitOnClose, false);
    m_btApp = new QAxObject(this);
    m_btApp->setControl("BarTender.Application");//连接BarTender控件

    QList<QPrinterInfo> value = QPrinterInfo::availablePrinters();

    ui->cbt_print_drive->blockSignals(true);
    ui->cbt_print_drive_ng->blockSignals(true);
    ui->cbt_print_drive->addItem("");
    ui->cbt_print_drive_ng->addItem("");
    for(QPrinterInfo &name:value){
        ui->cbt_print_drive->addItem(name.printerName());
        ui->cbt_print_drive_ng->addItem(name.printerName());
    }
    ui->LE_Number->setText("000000");
    ui->LE_HandNumber->setText("999999");

    ui->LE_Date->hide();
    load_FileINI();

    slot_ClearSerialNumber();

    ui->cbt_print_drive->blockSignals(false);
    ui->cbt_print_drive_ng->blockSignals(false);
}

MForm_PrintSetting::~MForm_PrintSetting()
{
    delete ui;
}

int MForm_PrintSetting::days_of_year()
{
    QDate date = QDate::currentDate();
    int dayofyear = date.dayOfYear();
    return dayofyear;
}

/**
 * @brief MForm_PrintSetting::slot_ClearSerialNumber 清楚所有标签流水号
 */
void MForm_PrintSetting::slot_ClearSerialNumber()
{
    QString path = QApplication::applicationDirPath() + tr("/setting/%1.ini").arg(objectName());
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    QString date = QDate::currentDate().toString("YYYY_MM_dd");
    bool b_clear = false;
    for(int i=0; i<50; i++){

        INI_File->beginGroup(QString::number(i));
        if(INI_File->value("clear_date") == date){
            b_clear = false;
        }else{
            b_clear = true;
            INI_File->setValue("clear_date", date);
        }
        if(b_clear){
            //确定需要清楚
            INI_File->setValue("label_number", "000000");
        }
        INI_File->endGroup();
    }
    INI_File->destroyed();
}

/**
 * @brief MForm_PrintSetting::load_FileINI
 */
void MForm_PrintSetting::load_FileINI()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("Printer");

    printer_driver_ok = INI_File->value("cbt_print_drive").toString();
    printer_driver_ng = INI_File->value("cbt_print_drive_ng").toString();
    ui->cbt_print_drive->setCurrentText(printer_driver_ok);
    ui->cbt_print_drive_ng->setCurrentText(printer_driver_ng);

    INI_File->endGroup();
    INI_File->destroyed();

    qDebug() << "打印机名称：" << printer_driver_ng << printer_driver_ok;

}

void MForm_PrintSetting::on_BTN_Save_clicked()
{
    QString path = QApplication::applicationDirPath() + tr("/setting/%1.ini").arg(objectName());
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));
/*
    INI_File->beginGroup("Printer");
    INI_File->setValue("cbt_print_drive", ui->cbt_print_drive->currentText());
    INI_File->setValue("cbt_print_drive_ng", ui->cbt_print_drive_ng->currentText());

    INI_File->endGroup();

    printer_driver_ok = ui->cbt_print_drive->currentText();
    printer_driver_ng = ui->cbt_print_drive_ng->currentText();
*/
    QString channel = ui->CBT_Channel->currentText();

    if(channel.toUInt() > 0){
        INI_File->beginGroup(channel);
        INI_File->setValue("LE_TitleNumber", ui->LE_TitleNumber->text());
        INI_File->setValue("LE_TitleName", ui->LE_TitleName->text());
        INI_File->setValue("LE_Date", ui->LE_Date->text());
        INI_File->setValue("sbox_year",ui->sbox_year->value());
        INI_File->setValue("sbox_days",ui->sbox_days->value());
        INI_File->setValue("label_number", ui->LE_Number->text());

        INI_File->setValue("cbx_location",ui->CBX_Location->currentIndex());
        INI_File->setValue("cbx_mode",ui->CBX_Mode->currentIndex());

        INI_File->endGroup();
    }
    INI_File->destroyed();
}
/**
 * @brief MForm_PrintLabel::autoPrinte  自动打印
 */
void MForm_PrintSetting::autoPrintlabel(const QString &number)
{
    qDebug() << "autoprintlabel";
    QString filepath_txt = QApplication::applicationDirPath() + "/label/YeLengLabel.txt";
    QList<QString> list;
    list.append(CurWorkPar.channel.rightJustified(2, '0') + "," + number);
    MFuntions::write_TXT(filepath_txt, list);

    slot_printer(QApplication::applicationDirPath() + "/label/YeLengLabel.btw", printer_driver_ok);
}
/**
 * @brief BartenderDialog::slot_printer 打印标签
 * @param path
 * @param printer_name
 */
void MForm_PrintSetting::slot_printer(const QString &path, const QString &printer_name)
{
    QByteArray ba = path.toUtf8();

    m_format = m_btApp->querySubObject("Formats")->querySubObject("Open(char *, bool, char *)", ba.data(), true, "");

    m_printSetup = m_format->querySubObject("PrintSetup");

    if(m_printSetup){
        m_printSetup->dynamicCall("Printer", printer_name.toUtf8().data());
    }

    if(m_btApp && m_printSetup){
        m_printSetup->dynamicCall("IdenticalCopiesOfLabel",1);//设置同序列打印的份数
        m_printSetup->dynamicCall("NumberSerializedLabels",1);//设置需要打印的序列数
        m_format->dynamicCall("PrintOut(bool, bool)",false, false);

        qDebug() << "开始打印";
    }

//    MainWindow::mutualUi->slot_tips("Print label." + path + printer_name);
    //    delete m_format;
    //    delete m_printSetup;
}
/**
 * @brief MForm_PrintSetting::on_BTN_HandPrinte_clicked 手动打印序列号
 */
void MForm_PrintSetting::on_BTN_HandPrinte_clicked()
{
//    autoPrintlabel("C" + CurWorkPar.channel.rightJustified(2, '0') + "_" + QDate::currentDate().toString("yyyyMMdd") + ui->LE_HandNumber->text());
}
/**
 * @brief MForm_PrintSetting::slot_Printe_Label_NG  打印NG标签
 * @param leackage_value
 */
void MForm_PrintSetting::slot_Printe_Label_NG(QString channel, QString leackage_value)
{

    on_CBT_Channel_currentTextChanged(channel);


    QList<QString> list_printe_label;
    qDebug() << "自动打印不合格标签";

    QStringList list;
    list.append(ui->LE_TitleNumber->text());
    list.append(ui->LE_TitleName->text());
//    list.append(ui->LE_Date->text());
    list.append(QString::number(ui->sbox_year->value()));
    list.append( QString("%1").arg(ui->sbox_days->value(), 3, 10, QChar('0')) );
    list.append(leackage_value);
    list.append(ui->LE_Leak_value->text());
    list.append(ui->CBX_Location->currentText());
    list.append(ui->CBX_Mode->currentText());
    list_printe_label.append(list.join(","));
    QCoreApplication::processEvents();

    QString filepath_txt = QApplication::applicationDirPath() + "/label/NG.txt";
    MFuntions::write_TXT(filepath_txt, list_printe_label);

    QString filepath = QApplication::applicationDirPath() + tr("/label/NG.btw").arg(channel);
    if(QFile::exists(filepath)){
        slot_printer(filepath, printer_driver_ng);
    }else{
        qDebug() << "文件不存在";
    }
}


/**
 * @brief MForm_PrintSetting::slot_Printe_Label_OK  打印OK标签
 */
void MForm_PrintSetting::slot_Printe_Label_OK(QString channel)
{
    qDebug() << "自动打印合格标签";

    on_CBT_Channel_currentTextChanged(channel);

    int v_number = ui->LE_Number->text().toUInt();
    QList<QString> list_printe_label;
    QStringList list;
    v_number++;
    list.append(ui->LE_TitleNumber->text());
    list.append(ui->LE_TitleName->text());
//    list.append(ui->LE_Date->text());
    list.append(QString::number(ui->sbox_year->value()));
    list.append( QString("%1").arg(ui->sbox_days->value(), 3, 10, QChar('0')) );
    ui->LE_Number->setText(QString("%1").arg(v_number, 6, 10, QLatin1Char('0')));
    list.append(ui->LE_Number->text());
    list.append(ui->LE_Leak_value->text());
    list.append(ui->CBX_Location->currentText());
    list.append(ui->CBX_Mode->currentText());
    list_printe_label.append(list.join(","));

    MFormJLStation::mutualUi->ui->LE_ProductCode_Print->setText(list.at(0) + ":" + list.at(1) +list.at(2) +list.at(3) + list.at(4));

    list.clear();


#if 0
   QString path = QApplication::applicationDirPath() + "/System/System.ini";
   QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
   INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

   INI_File->beginGroup("Printer");
   INI_File->setValue("label_number", ui->LE_Number->text());
   INI_File->endGroup();

   INI_File->destroyed();

#elif 1

    QString path = QApplication::applicationDirPath() + tr("/setting/%1.ini").arg(objectName());
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup(ui->CBT_Channel->currentText());
    INI_File->setValue("label_number", ui->LE_Number->text());
    INI_File->endGroup();

    INI_File->destroyed();

#endif

   QCoreApplication::processEvents();

   QString filepath_txt = QApplication::applicationDirPath() + tr("/label/channel_%1.txt").arg(channel);
   MFuntions::write_TXT(filepath_txt, list_printe_label);

   QString filepath = QApplication::applicationDirPath() + tr("/label/channel_%1.btw").arg(channel);
   if(QFile::exists(filepath)){
       slot_printer(filepath, printer_driver_ok);
   }else{
       qDebug() << "文件不存在";
   }
}
/**
 * @brief MForm_PrintSetting::on_BTN_autoPrint_clicked
 */
void MForm_PrintSetting::on_BTN_autoPrint_clicked()
{

    int v_number = ui->LE_Number->text().toUInt();
    int v_printe_count = ui->SPB_PrinteCount->value();
    QList<QString> list_printe_label;
    QStringList list;

    QString channel = ui->CBT_Channel->currentText();

    for(int i=0; i<v_printe_count; i++){
        list.append(ui->LE_TitleNumber->text());
        list.append(ui->LE_TitleName->text());
//        list.append(ui->LE_Date->text());
        list.append(QString::number(ui->sbox_year->value()));
        list.append( QString("%1").arg(ui->sbox_days->value(), 3, 10, QChar('0')) );
        v_number++;
        ui->LE_Number->setText(QString("%1").arg(v_number, 6, 10, QLatin1Char('0')));
        list.append(ui->LE_Number->text());
        list.append(ui->LE_Leak_value->text());
        list.append(ui->CBX_Location->currentText());
        list.append(ui->CBX_Mode->currentText());
        list_printe_label.append(list.join(","));
        list.clear();
    }

 #if 0
   QString path = QApplication::applicationDirPath() + "/System/System.ini";
   QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
   INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

   INI_File->beginGroup("Printer");
   INI_File->setValue("label_number", ui->LE_Number->text());
   INI_File->endGroup();

   INI_File->destroyed();

#elif 1

    QString path = QApplication::applicationDirPath() + tr("/setting/%1.ini").arg(objectName());
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup(channel);
    INI_File->setValue("label_number", ui->LE_Number->text());
    INI_File->endGroup();

    INI_File->destroyed();

#endif

   qDebug() << "手动打印";

   QCoreApplication::processEvents();

   QString filepath_txt = QApplication::applicationDirPath() + tr("/label/channel_%1.txt").arg(channel);
   MFuntions::write_TXT(filepath_txt, list_printe_label);

   QString filepath = QApplication::applicationDirPath() + tr("/label/channel_%1.btw").arg(channel);
   if(QFile::exists(filepath)){
       slot_printer(filepath, printer_driver_ok);
   }else{
       qDebug() << "文件不存在";
   }
}
/**
 * @brief MForm_PrintSetting::on_CBT_Channel_currentTextChanged 打印切品番
 * @param arg1
 */
void MForm_PrintSetting::on_CBT_Channel_currentTextChanged(const QString &arg1)
{
    if(arg1 == ""){
        return;
    }
    QString path = QApplication::applicationDirPath() + tr("/setting/%1.ini").arg(objectName());
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    QString channel = ui->CBT_Channel->currentText();

    INI_File->beginGroup(arg1);
    ui->LE_TitleNumber->setText(INI_File->value("LE_TitleNumber").toString());
    ui->LE_TitleName->setText(INI_File->value("LE_TitleName").toString());

    ui->LE_Date->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->sbox_year->setValue(QDate::currentDate().toString("yy").toInt());
    ui->sbox_days->setValue(QDate::currentDate().dayOfYear());
    ui->LE_Number->setText(QString("%1").arg(INI_File->value("label_number").toInt(), 6, 10, QLatin1Char('0')));

    ui->CBX_Location->setCurrentIndex(INI_File->value("cbx_location").toInt());
    ui->CBX_Mode->setCurrentIndex(INI_File->value("cbx_mode").toInt());

    INI_File->endGroup();

    INI_File->setValue("ReadMe", "系统配置");

    INI_File->destroyed();
}
/**
 * @brief MForm_PrintSetting::on_cbt_print_drive_ng_currentTextChanged  ng打印机
 * @param arg1
 */
void MForm_PrintSetting::on_cbt_print_drive_ng_currentTextChanged(const QString &arg1)
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("Printer");
    INI_File->setValue("cbt_print_drive_ng", arg1);

    INI_File->endGroup();

    INI_File->destroyed();

    qDebug() << "保存：" << arg1;
    printer_driver_ng = arg1;
}
/**
 * @brief MForm_PrintSetting::on_cbt_print_drive_currentTextChanged ok打印机
 * @param arg1
 */
void MForm_PrintSetting::on_cbt_print_drive_currentTextChanged(const QString &arg1)
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings *INI_File = new QSettings(path, QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("Printer");
    INI_File->setValue("cbt_print_drive", arg1);

    INI_File->endGroup();
    INI_File->destroyed();

    qDebug() << "保存：" << arg1;
    printer_driver_ok = arg1;
}

/**
 * @brief MFormMysql::download_Objects  下载
 * @param arg1
 */
void MForm_PrintSetting::download_Objects(const QString &arg1)
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
void MForm_PrintSetting::upload_Objects(const QString &arg1)
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


void MForm_PrintSetting::slot_set_leakvalue(const QString text)
{
    ui->LE_Leak_value->setText(text);
}

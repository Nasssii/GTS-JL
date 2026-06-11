
#include "MFormWorkStep.h"
#include "ui_MFormWorkStep.h"
#include <QMetaObject>
#include <QSignalBlocker>
MFormWorkStep *m_MFormWorkStep;

MFormWorkStep::MFormWorkStep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MFormWorkStep)
{
    ui->setupUi(this);

    ui->label_25->hide();
    ui->Btn_Copy_Channel_Sure->hide();
    ui->Copy_Channel->hide();
    ui->CBX_Positive->hide();
    ui->Channel_Positive->hide();
    ui->CBX_Negative->hide();
    ui->Channel_Negative->hide();
}

MFormWorkStep::~MFormWorkStep()
{
    delete ui;
}

short MFormWorkStep::Load_Work_ChannelPars(QString channel)
{
    if(channel.toUInt() == 0 || channel.toUInt() > 50){
        ui->Tip_SavePars->setText(QTime::currentTime().toString() + "：请选择正确频道");
        return -1;
    }

    QSettings INI_File(QApplication::applicationDirPath() + "/setting/channel.ini", QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));

    if(!INI_File.childGroups().contains(channel)){
        //QMessageBox::information(this, "频道提示", tr("载入频道失败，工位未搜索到[频道：%1]").arg(channel));
        return -1;
    }

    CurWorkPar.channel = channel;

    INI_File.beginGroup(channel);

    CurWorkPar.product_name = INI_File.value("project_name").toString();
    CurWorkPar.project_name = INI_File.value("product_name").toString();
    CurWorkPar.v_ct = INI_File.value("ct").toUInt();

    CurWorkPar.list_Codes_set[0] = INI_File.value("code1").toString();
    CurWorkPar.list_Codes_length[0] = INI_File.value("CodeLength_1").toInt();
    CurWorkPar.list_Codes_Repeat[0] = INI_File.value("CodeStation_1").toInt();

    CurWorkPar.ATEQ_Enable = INI_File.value("cbt_ateq").toInt();
    CurWorkPar.Check_Pisitive = CurWorkPar.ATEQ_Enable == 1 || CurWorkPar.ATEQ_Enable == 3;
    CurWorkPar.Check_Negative = CurWorkPar.ATEQ_Enable == 2 || CurWorkPar.ATEQ_Enable == 3;
    CurWorkPar.Channel_Pisitive = channel.toInt();
    CurWorkPar.Chanel_Negative = channel.toInt();
    CurWorkPar.plcProductAteq1 = INI_File.value("plc_product_ateq1", channel.toInt()).toInt();
    CurWorkPar.plcProductAteq2 = INI_File.value("plc_product_ateq2", channel.toInt()).toInt();
    if(CurWorkPar.plcProductAteq1 <= 0){
        CurWorkPar.plcProductAteq1 = channel.toInt();
    }
    if(CurWorkPar.plcProductAteq2 <= 0){
        CurWorkPar.plcProductAteq2 = channel.toInt();
    }

    INI_File.endGroup();

   // ui->Tip_SavePars->setText(QTime::currentTime().toString() + tr("：载入频道成功 [频道：%1，产品型号：%2]").arg(channel, ui->SettingProductName->text()));
    return 1;
}

/**
 * @brief MFormWorkStep::save_File_INI  保存品番
 */
void MFormWorkStep::save_File_INI(const QString channel)
{
    QString path = QApplication::applicationDirPath() + "/setting/channel.ini";
    QSettings INI_File(path, QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File.beginGroup(channel);

    INI_File.setValue("product_name", ui->SettingProductName->text());

    INI_File.setValue("cbt_ateq", ui->Cbt_ATEQ_Enable->currentIndex());

    INI_File.setValue("code1", ui->SetKeyCode_1->text());
    INI_File.setValue("CodeLength_1", ui->SPB_code_length_1->value());
    INI_File.setValue("CodeStation_1", ui->SPB_CodeStation_1->value());

    INI_File.setValue("CBX_Positive", ui->Cbt_ATEQ_Enable->currentIndex() == 1 || ui->Cbt_ATEQ_Enable->currentIndex() == 3);
    INI_File.setValue("CBX_Negative", ui->Cbt_ATEQ_Enable->currentIndex() == 2 || ui->Cbt_ATEQ_Enable->currentIndex() == 3);
    INI_File.setValue("Channel_Positive", channel.toInt());
    INI_File.setValue("Channel_Negative", channel.toInt());
    if(!INI_File.contains("plc_product_ateq1")){
        INI_File.setValue("plc_product_ateq1", channel.toInt());
    }
    if(!INI_File.contains("plc_product_ateq2")){
        INI_File.setValue("plc_product_ateq2", channel.toInt());
    }

    INI_File.endGroup();

    if(m_Form_PrintSetting != nullptr && m_Form_PrintSetting->ui != nullptr
            && ui->Channel->currentText() == m_Form_PrintSetting->ui->CBT_Channel->currentText()){
        const bool printSaveOk = QMetaObject::invokeMethod(
                    m_Form_PrintSetting,
                    "on_BTN_Save_clicked",
                    Qt::DirectConnection);
        qDebug() << "[CHANNEL] workstep print setting saved" << printSaveOk;
    }else{
        qDebug()<<"参数设置与打印品番不一致，不保存打印参数";
    }
}

void MFormWorkStep::on_Channel_currentTextChanged(const QString &arg1)
{
    QString path = QApplication::applicationDirPath() + "/setting/channel.ini";
    QSettings INI_File(path, QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File.beginGroup(arg1);

    ui->SettingProductName->setText(INI_File.value("product_name").toString());

    ui->Cbt_ATEQ_Enable->setCurrentIndex(INI_File.value("cbt_ateq").toUInt());

    ui->SetKeyCode_1->setText(INI_File.value("code1").toString());
    ui->SPB_code_length_1->setValue(INI_File.value("CodeLength_1").toInt());
    ui->SPB_CodeStation_1->setValue(INI_File.value("CodeStation_1").toInt());

    ui->CBX_Positive->setChecked(ui->Cbt_ATEQ_Enable->currentIndex() == 1 || ui->Cbt_ATEQ_Enable->currentIndex() == 3);
    ui->CBX_Negative->setChecked(ui->Cbt_ATEQ_Enable->currentIndex() == 2 || ui->Cbt_ATEQ_Enable->currentIndex() == 3);
    ui->Channel_Positive->setValue(arg1.toInt());
    ui->Channel_Negative->setValue(arg1.toInt());

    INI_File.endGroup();

    qDebug() << "切换品番";
    if(m_Form_PrintSetting != nullptr && m_Form_PrintSetting->ui != nullptr){
        QSignalBlocker blocker(m_Form_PrintSetting->ui->CBT_Channel);
        m_Form_PrintSetting->ui->CBT_Channel->setCurrentText(arg1);
        const bool printLoadOk = QMetaObject::invokeMethod(
                    m_Form_PrintSetting,
                    "on_CBT_Channel_currentTextChanged",
                    Qt::DirectConnection,
                    Q_ARG(QString, arg1));
        qDebug() << "[CHANNEL] workstep print channel synced" << arg1 << "loaded=" << printLoadOk;
    }else{
        qDebug() << "[CHANNEL] workstep print sync ignored, object null";
    }
}

void MFormWorkStep::on_Btn_Sure_clicked()
{
    if(ui->Channel->currentIndex() == 0){
        return;
    }
    save_File_INI(ui->Channel->currentText());
}

// use按钮函数
void MFormWorkStep::on_Btn_Use_clicked()
{
    if(ui->Channel->currentIndex() == 0){
        ui->Tip_SavePars->setText(QTime::currentTime().toString() + "：请选择正确频道");
        return;
    }

    const QString channel = ui->Channel->currentText();

    // 1. 先保存当前界面参数到 setting/channel.ini
    save_File_INI(channel);

    // 2. 再重新加载刚保存的频道参数，刷新 CurWorkPar
    const short loadResult = Load_Work_ChannelPars(channel);
    if(loadResult <= 0){
   //     ui->Tip_SavePars->setText(QTime::currentTime().toString() + tr("：应用失败 [频道：%1]").arg(channel));
        return;
    }

    // 3. 同步主界面当前频道和产品显示
    if(MFormJLStation::mutualUi != nullptr){
        if(MFormJLStation::mutualUi->ui->CBT_Channel->currentText() != channel){
            MFormJLStation::mutualUi->ui->CBT_Channel->setCurrentText(channel);
        }
        MFormJLStation::mutualUi->ui->LE_Product_Number->setText(CurWorkPar.project_name);
    }

    //ui->Tip_SavePars->setText(QTime::currentTime().toString() + tr("：保存并应用成功 [频道：%1，产品型号：%2]").arg(channel, CurWorkPar.project_name));
}



/**
 * @brief MFormJLStation::getQPushButton    获取按钮对象名字和显示文本
 */
void MFormWorkStep::download_Objects(const QString &arg1)
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

    INI_File->beginGroup("QCheckBox");
    QList<QCheckBox*> checkbox = findChildren<QCheckBox*>();
    for(int i=0; i<checkbox.size(); i++){
        INI_File->setValue(checkbox.at(i)->objectName(), checkbox.at(i)->text());
    }
    INI_File->endGroup();


    INI_File->beginGroup("QGroupBox");
    QList<QGroupBox*> groupBox = findChildren<QGroupBox*>();
    for(int i=0; i<groupBox.size(); i++){
        INI_File->setValue(groupBox.at(i)->objectName(), groupBox.at(i)->title());
    }
    INI_File->endGroup();

    INI_File->beginGroup("QTabWidget");
    QList<QTabWidget*> tabWidget = findChildren<QTabWidget*>();
    for(int i=0; i<tabWidget.size(); i++){
        QString name = tabWidget.at(i)->objectName();
        int v_tab_count = tabWidget.at(i)->tabBar()->count();
        QStringList list;
        for(int j=0; j<v_tab_count; j++){
            list.append(QString::number(j));
            list.append(tabWidget.at(i)->tabText(j));
        }
        INI_File->setValue(name, list);
    }
    INI_File->endGroup();


    INI_File->destroyed();
}

/**
 * @brief MForm_ScanCode::getObject
 * @param arg1
 */
void MFormWorkStep::upload_Objects(const QString &arg1)
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

    INI_File->beginGroup("QCheckBox");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QCheckBox *object = findChild<QCheckBox*>(name);
        if(object){
            object->setText(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->beginGroup("QGroupBox");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QGroupBox *object = findChild<QGroupBox*>(name);
        if(object){
            object->setTitle(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->beginGroup("QTabWidget");
    list_childkeys =  INI_File->childKeys();
    qDebug() << list_childkeys;
    foreach(const QString& name, list_childkeys){
        QTabWidget *object = findChild<QTabWidget*>(name);
        if(object){
            QStringList list =INI_File->value(name).toStringList();
            int v_tab_count = list.count() / 2;
            for(int i=0; i<v_tab_count; i++){
                object->setTabText(i, list.at(2*i + 1));
            }
        }
    }
    INI_File->endGroup();


    INI_File->destroyed();
}

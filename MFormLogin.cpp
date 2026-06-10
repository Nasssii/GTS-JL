#include "MFormLogin.h"
#include "ui_MFormLogin.h"
#include <QSettings>
#include <QTextCodec>

MFormLogin *m_FormLogin;

MFormLogin::MFormLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MFormLogin)
{
    ui->setupUi(this);
    ui->BTN_changePassword->setEnabled(false);
    ui->LE_admin->hide();
    ui->label_4->hide();
    load_INI_File();
}

MFormLogin::~MFormLogin()
{
    delete ui;
}


void MFormLogin::load_INI_File()
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File->beginGroup("admin");

    INI_File->endGroup();

    INI_File->destroyed();
}


void MFormLogin::on_BTN_OK_clicked()
{
    QSettings *INI_File = new QSettings(QApplication::applicationDirPath() + "/System/System.ini", QSettings::IniFormat);
    INI_File->setIniCodec(QTextCodec::codecForName("GB2312"));


    QString password = INI_File->value("password", "111111").toString();

    if(ui->BTN_changePassword->isChecked()){

        INI_File->setValue("password", ui->LE_Password->text());
        QMessageBox::information(this, "information", "OK");
        ui->BTN_changePassword->setChecked(false);

    }else{
        if(ui->LE_Password->text() == password){
            MFormJLStation::mutualUi->objectEnable(true);
            ui->BTN_changePassword->setEnabled(true);
            close();
        }else{
            MFormJLStation::mutualUi->objectEnable(false);
            QMessageBox::warning(this, "warn", "error");
        }
    }

    INI_File->endGroup();

    INI_File->destroyed();
}
void MFormLogin::download_Objects(const QString &arg1)
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
void MFormLogin::upload_Objects(const QString &arg1)
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

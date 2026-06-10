#include "MForm_ProductTips.h"
#include "ui_MForm_ProductTips.h"


MForm_ProductTips *m_Form_ProductTips;
MForm_ProductTips::MForm_ProductTips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MForm_ProductTips)
{
    ui->setupUi(this);
}

MForm_ProductTips::~MForm_ProductTips()
{
    delete ui;
}

void MForm_ProductTips::download_Objects(const QString &arg1)
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

    INI_File->beginGroup("QGroupBox");
    QList<QGroupBox*> groupBox = findChildren<QGroupBox*>();
    for(int i=0; i<groupBox.size(); i++){
        INI_File->setValue(groupBox.at(i)->objectName(), groupBox.at(i)->title());
    }
    INI_File->endGroup();

    INI_File->destroyed();
}

void MForm_ProductTips::upload_Objects(const QString &arg1)
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

    INI_File->beginGroup("QGroupBox");
    list_childkeys =  INI_File->childKeys();
    foreach(const QString& name, list_childkeys){
        QGroupBox *object = findChild<QGroupBox*>(name);
        if(object){
            object->setTitle(INI_File->value(name).toString());
        }
    }
    INI_File->endGroup();

    INI_File->destroyed();
}

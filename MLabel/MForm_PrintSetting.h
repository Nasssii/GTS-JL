#ifndef MFORM_PRINTSETTING_H
#define MFORM_PRINTSETTING_H

#include <QDialog>
#include <QPrinterInfo>
#include <QSettings>
#include <QTextCodec>
#include <QAxObject>
#include "MFormJLStation.h"
#include <QCoreApplication>

namespace Ui {
class MForm_PrintSetting;
}

class MForm_PrintSetting : public QDialog
{
    Q_OBJECT

public:
    explicit MForm_PrintSetting(QWidget *parent = nullptr);
    ~MForm_PrintSetting();


    Ui::MForm_PrintSetting *ui;
    QString printer_driver_ok;//打印机驱动
    QString printer_driver_ng;//NG标签

    QString number;//序列号

    void load_FileINI();
    void autoPrintlabel(const QString &number);
    void slot_Printe_Label_OK(QString channel);
    void download_Objects(const QString &arg1);
    int days_of_year();
    void upload_Objects(const QString &arg1);
public slots:
    void slot_printer(const QString &path, const QString &printer_name);
    void slot_Printe_Label_NG(QString channel, QString leackage_value);
    void slot_ClearSerialNumber();

    void slot_set_leakvalue(const QString text);
private slots:
    void on_BTN_Save_clicked();
    void on_BTN_HandPrinte_clicked();
    void on_BTN_autoPrint_clicked();
    void on_CBT_Channel_currentTextChanged(const QString &arg1);

    void on_cbt_print_drive_ng_currentTextChanged(const QString &arg1);


    void on_cbt_print_drive_currentTextChanged(const QString &arg1);

private:


    QAxObject *m_barTender;
    QAxObject *m_btApp;
    QAxObject *m_printSetup;
    QAxObject *m_format;

};


extern MForm_PrintSetting *m_Form_PrintSetting;

#endif // MFORM_PRINTSETTING_H

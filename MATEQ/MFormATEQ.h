#ifndef MFORMATEQ_H
#define MFORMATEQ_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSettings>
#include <QTextCodec>
#include <QTime>
#include "MATEQ/combase.h"

namespace Ui {
class MFormATEQ;
}




class MFormATEQ : public QDialog
{
    Q_OBJECT

public:
    explicit MFormATEQ(QWidget *parent = nullptr);
    ~MFormATEQ();

    Ui::MFormATEQ *ui;
    void loadFileINI();

    void upload_Objects(const QString &arg1);
    void download_Objects(const QString &arg1);
private slots:
    void on_BTN_Save_clicked();

    void on_Btn_JL_1_clicked();

    void on_Btn_JL_2_clicked();

private:

public slots:
    void slot_Tips(const QString &mesg, int color_id);
    void slot_updateAteqRawDisplay(int device, const QString &raw, bool ok);

signals:

    void sign_OpenCom_JL_1();
    void sign_OpenCom_JL_2();
};

extern MFormATEQ *m_FormATEQ;

struct MS_MFormATEQ{

    QString Port_1;
    QString Buad_1;
    QString Port_2;
    QString Buad_2;


    //ATEQ
    uchar v_ATEQ_Enable = 0;//气密性检测使能 0：none 1:ATEQ 1 2:ATEQ 2 3:ATEQ 1 and ATEQ 2
    bool B_ATEQ1_Finished = false;
    bool B_ATEQ2_Finished = false;
    bool b_ATEQ_EN_1 = false;
    QString ATEQ_Datas_1 = "";
    QString ATEQ_Result_1 = "";
    QString ATEQ_Datas_2 = "";
    bool b_ATEQ_EN_2 = false;
    QString ATEQ_Result_2 = "";
};
extern MS_MFormATEQ ms_MFormATEQ;
#endif // MFORMATEQ_H

#ifndef MFORM_SCANCODE_H
#define MFORM_SCANCODE_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "MFuntions.h"
#include "MFormJLStation.h"

namespace Ui {
class MForm_ScanCode;
}

class MForm_ScanCode : public QDialog
{
    Q_OBJECT

public:
    explicit MForm_ScanCode(QWidget *parent = nullptr);
    ~MForm_ScanCode();

    QString s_codeType = "Part scanning";

    QSerialPort *m_serialPort = nullptr;
    QString port;
    QString baud;
    bool b_open = false;
    QTimer *ptimer;
    QByteArray _byteArray;
    bool b_Step_ScanCode = false;
    bool b_FX_ScanCode = false;

    QSerialPort *m_serialPort_2 = nullptr;
    QString port_2;
    QString baud_2;
    bool b_open_2 = false;
    QTimer *ptimer_2;
    QByteArray _byteArray_2;
    bool b_Step_ScanCode_2 = false;
    bool b_FX_ScanCode_2 = false;

    void load_File_INI();
    void slot_Tips(int id, QString mesg);

    void upload_Objects(const QString &arg1);
    void download_Objects(const QString &arg1);
public slots:
    void slot_readRead();
    void slot_readAll();
    void slot_readRead_2();
    void slot_readAll_2();

    void slot_WriteDatas(QByteArray send_byte);
private slots:
    void on_Btn_Save_clicked();
    void on_Btn_OpenClose_clicked();
    void on_Btn_Update_clicked();
    void on_Btn_OpenClose_2_clicked();
    void on_Btn_Update_2_clicked();

private:
    Ui::MForm_ScanCode *ui;

signals:
    void sign_GetNGCode(const QString &mesg);
    void sign_WriteDatas(QByteArray send_byte);
    void sign_barcodeReceived(const QString &barcode);
    void sign_scanWriteFailed(const QString &reason);
};
extern MForm_ScanCode *m_Form_ScanCode;
extern QString BarCode;
extern bool b_SaoMa_Fin;
#endif // MFORM_SCANCODE_H

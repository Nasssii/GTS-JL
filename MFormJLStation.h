#ifndef MFORMJLSTATION_H
#define MFORMJLSTATION_H

#include <QMainWindow>
#include "ModbusRtu/MForm_ModeBusRtu.h"
#include "ModbusRtu/mModbusRtu.h"
#include "MLabel/MForm_PrintSetting.h"
#include "ui_MForm_PrintSetting.h"
#include "MFuntions.h"
#include "MATEQ/MFormATEQ.h"
#include "mWorkTask.h"

#include "MFormWorkStep.h"
#include "ui_MFormWorkStep.h"

#include <QMessageBox>
#include "MForm_ProductTips.h"
#include "MFormLogin.h"
#include "ui_MFormLogin.h"
#include <atomic>


QT_BEGIN_NAMESPACE
namespace Ui { class MFormJLStation; }
QT_END_NAMESPACE



extern bool B_Testing_Start;//软起动

#ifndef MTESTINGUISNAPSHOT_DEFINED
#define MTESTINGUISNAPSHOT_DEFINED
struct MTestingUiSnapshot{
    QString product_code;
    QString product_number;
    QString eq_number;
    QString channel;
    QString batch;
    QString operator_id;
    QString product_code_print;
};
#endif

struct MST_MYSQL_Datas{
    QString product_code;
    QString product_number;
    QString eq_number;
    QString channel;
    QString batch;
    QString operator_id;
    QString testing_start_time;
    QString testing_finished_time;
    QString testing_time;
    //数据1
    QString testing_result;
    QString testing_pressuse;
    QString testing_leackage_value;
    //数据2
    QString testing_result_2;
    QString testing_pressuse_2;
    QString testing_leackage_value_2;
    //打印条码
    QString product_code_print;

};

class MFormJLStation : public QMainWindow
{
    Q_OBJECT

public:
    MFormJLStation(QWidget *parent = nullptr);
    ~MFormJLStation();

    QTimer *ptimer = new QTimer(this);


    uint8_t v_channel = 0;
    Ui::MFormJLStation *ui;
    static MFormJLStation *mutualUi;    //指针类型静态成员变量

    bool time_flag = false;//检测计时
    bool needPlaceNgProductChecked() const;

    bool B_BTN_grating = true;

    void download_Objects(const QString &arg1);
    void upload_Objects(const QString &arg1);
    void load_File_INI();
    void objectEnable(bool enable);
public slots:
    void slot_ClockTimeout();

    void slot_setled(QLabel *label, const int color);
    void slot_setled_cicular(QLabel *label, const int color);
    void slot_set_text(QLabel *label, const QString text);
    void slot_updateAteqDisplay(int device, const QString &pressure, const QString &leakage);
    void slot_ClearDisplayData();
    void slot_init_Display();
    void slot_onBarcodeReceived(const QString &barcode);
    void slot_onScanWriteFailed(const QString &reason);
    void slot_set_lineEdit(QLineEdit *lineEdit, const QString text);
    void slot_setTimeFlag(bool enabled);
    void applyManualResetUi();
private slots:
    void on_BTN_IO_clicked();
    void on_BTN_ATEQ_clicked();
    void on_BTN_MFormLabel_clicked();
    void on_BTN_Start_clicked();
    void on_BTN_Reset_clicked();
    void on_CBT_Channel_currentTextChanged(const QString &arg1);
    void on_BTN_ScanCode_clicked();
    void on_BTN_MFormMYSQL_clicked();
    void on_CBT_Language_currentTextChanged(const QString &arg1);
    void on_BTN_Get_Object_clicked();

    void on_BTN_Login_clicked();

    void on_BTN_Save_clicked();

    void on_BTN_Logout_clicked();

    void on_BTN_NeedPlaceNGProduct_toggled(bool checked);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QStringList mColorName = {
        "background-color: rgb(200,200,200);",
        "background-color: red;",
        "background-color: rgb(0,255,0);",
        "background-color: yellow;",
        "background-color: white;",
    };

    QString _channel;
    std::atomic_bool m_needPlaceNgProductChecked{false};

    bool isChannelValid() const;
    bool triggerScanCode();
    MTestingUiSnapshot makeTestingSnapshot(const QString &barcode) const;
};
extern QString Language;
extern QString lastProcutCode;
extern QString lastProductResult;
#endif // MFORMJLSTATION_H

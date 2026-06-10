#ifndef MFORMMYSQL_H
#define MFORMMYSQL_H

#include <QDialog>
#include <QLabel>
#include <QSqlDatabase>
#include <QSettings>
#include <QTextCodec>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "MFormJLStation.h"
#include "ui_MFormJLStation.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QCoreApplication>
#include <QDebug>


#include "MFuntions.h"

#define MYSQL_TABLE_STATION         "yuxinchuneng_table1"
#define MYSQL_TABLE_OEE             "oee"
#define MYSQL_TABLE_JL_Datas        "jl_datas"
#define MYSQL_Table_PerformanceTest ""


class MST_MYSQL_Datas;

struct MST_Data_OEE{
    uint RealQuantity = 0;
    uint TheoreticalQuantity = 0;
};
extern MST_Data_OEE mst_Data_OEE;

struct MST_Data_anGui{
    QString IR_Vlot, IR_R;
    QString AC_Vlot, AC_Current;
    QString DC_Vlot, DC_Current;
    QString GB_Current, GB_R;
};

namespace Ui {
class MFormMysql;
}

class MFormMysql : public QDialog
{
    Q_OBJECT

public:
    explicit MFormMysql(QWidget *parent = nullptr);
    ~MFormMysql();

    QString FILE_REPORT_PATH;
    QTableView *m_tableV;
    QTableView *m_tableV_DJ;
    QStandardItemModel *m_standardItemModel_DJ;

    QStandardItemModel *m_standardItemModel;
    QSqlTableModel *m_sqlTableModel;

    Ui::MFormMysql *ui;

    QString hostName = "127.0.0.1";
    QString port = "3306";
    QString databaseName = "";
    QString userName = "admin1";
    QString password = "123456";


    void load_File_INI();
    void init_TableV();

    QString uploadXlsx(QStringList &list_hlabels, QStringList &list_datas);
    bool importXlsxToTableView(const QString &filePath, QStandardItemModel *model);
    QString tableViewToHtml(QTableView *tableView);
    void saveTableViewAsHtml(QTableView *tableView, const QString &fileName);
    void Init_model_mysql();
    void download_Objects(const QString &arg1);
    void upload_Objects(const QString &arg1);
public slots:
    void slot_Display_OP_Datas(QStringList list_hlabels, QStringList list_datas);
private:

signals:
    void sign_update_JLDatas(MST_MYSQL_Datas mst_datas);
    void sign_MYSQL_queryDatas_rfid(const QString rfid);
    void sign_MYSQL_updateRealQuantity(const uint value);
    void sign_MYSQL_updateRemainingQuantity(const uint value);
    void sign_MYSQL_updateTheoreticalQuantity(const uint value);
    void sign_MYSQL_model_query(const QString queryKind, const QString queryTable, const QStringList queryInfos, const uint allPage, const uint pageOffset);

private slots:
    void on_Btn_SavePars_clicked();
    void on_BTN_query_datas_clicked();
    void on_BTN_query_datas_Date_clicked();
    void on_BTN_Export_Data_clicked();
};

class MMYSQLDatas : public QObject
{
    Q_OBJECT

public:
    explicit MMYSQLDatas(QObject *parent = nullptr);
    ~MMYSQLDatas();

    QThread *pThread;
    QSqlDatabase db;
    bool B_Connect = false;
    QSqlTableModel *modelTable_mysql_Station = new QSqlTableModel(this, db);
    QSqlTableModel *modelTable_mysql_PerformanceTest = new QSqlTableModel(this, db);

    QString Select_Data = "";

    void connectMYSQL();

    void insert_JLDatas(MST_MYSQL_Datas &mst_datas);
public slots:
    void slot_searchDatas();
    void slot_MYSQL_updateTheoreticalQuantity(const uint value);
    void slot_MYSQL_updateRealQuantity(const uint value);
    void slot_MYSQL_queryDatas_rfid(const QString rfid);
    void slot_MYSQL_updateRemainingQuantity(const uint value);
    void slot_update_JLDatas(MST_MYSQL_Datas mst_datas);
    void slot_MYSQL_model_query(const QString queryKind, const QString queryTable, const QStringList queryInfos, const uint allPage, const uint pageOffset);
signals:

    void sign_Display_OP_Datas(QStringList list_hlabels, QStringList list_datas);
    void sign_setled(QLabel *label, const uchar color);
    void sign_setled_Frame(QFrame *label, const uchar color);
    void sign_setled_cicular(QLabel *label, const uchar color);
    void sign_Tips(const QString mes, const uchar color_id=5);
    void sign_OEEDisplay(const QStringList list);

};

extern MMYSQLDatas *m_MYSQLDatas;
extern MFormMysql *m_FormMysql;
#endif // MFORMMYSQL_H

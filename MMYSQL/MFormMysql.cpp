#include "MFormMysql.h"
#include "ui_MFormMysql.h"


MST_Data_OEE mst_Data_OEE;

MFormMysql *m_FormMysql;
MMYSQLDatas *m_MYSQLDatas;
// 格式化CSV字段（处理逗号、引号、换行符）
QString formatCSVField(const QString& field) {
    QString result = field;

    // 如果字段包含特殊字符，需要用引号包裹并转义内部的引号
    if (result.contains(',') || result.contains('"') ||
        result.contains('\n') || result.contains('\r')) {
        result.replace("\"", "\"\"");
        result = "\"" + result + "\"";
    }

    return result;
}

bool exportSqlModelToCSV(QSqlTableModel* model, const QString& fileName) {
    if (!model) return false;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
//    out.setEncoding(QStringConverter::Utf8);  // Qt6
     out.setCodec("UTF-8");  // Qt5

    // 写入BOM，便于Excel识别UTF-8
    out << QChar(0xFEFF);

    // 1. 写入表头（字段名）
    QStringList headers;
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        if (header.isEmpty()) {
            header = model->record().fieldName(col);  // 使用实际字段名
        }
        headers << formatCSVField(header);
    }
    out << headers.join(",") << "\n";

    // 2. 写入数据行
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString value = index.data().toString();
            rowData << formatCSVField(value);
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    return true;
}

MFormMysql::MFormMysql(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MFormMysql)
{
    ui->setupUi(this);

    FILE_REPORT_PATH = QApplication::applicationDirPath() + "/REPORT/" + QDate::currentDate().toString("yyyyMM") + "/"
                + QString::number(QDate::currentDate().day()) + "/";


    MFuntions::mKMutiDir(FILE_REPORT_PATH);

    ui->dateEdit_Begin->setDate(QDate::currentDate());
    ui->dateEdit_End->setDate(QDate::currentDate());

    init_TableV();
    load_File_INI();

    m_MYSQLDatas = new MMYSQLDatas();
    connect(this, &MFormMysql::sign_MYSQL_queryDatas_rfid, m_MYSQLDatas, &MMYSQLDatas::slot_MYSQL_queryDatas_rfid);
    connect(this, &MFormMysql::sign_MYSQL_updateRealQuantity, m_MYSQLDatas, &MMYSQLDatas::slot_MYSQL_updateRealQuantity);
    connect(this, &MFormMysql::sign_MYSQL_updateRemainingQuantity, m_MYSQLDatas, &MMYSQLDatas::slot_MYSQL_updateRemainingQuantity);
    connect(this, &MFormMysql::sign_MYSQL_updateTheoreticalQuantity, m_MYSQLDatas, &MMYSQLDatas::slot_MYSQL_updateTheoreticalQuantity);
    connect(this, &MFormMysql::sign_update_JLDatas, m_MYSQLDatas, &MMYSQLDatas::slot_update_JLDatas);
    connect(this, &MFormMysql::sign_MYSQL_model_query, m_MYSQLDatas, &MMYSQLDatas::slot_MYSQL_model_query);
//    connect(m_MYSQLDatas, &MMYSQLDatas::sign_Tips, MainWindow::mutualUi, &MainWindow::slot_Tips);
    connect(m_MYSQLDatas, &MMYSQLDatas::sign_setled, MFormJLStation::mutualUi, &MFormJLStation::slot_setled);
    connect(m_MYSQLDatas, &MMYSQLDatas::sign_Display_OP_Datas, this, &MFormMysql::slot_Display_OP_Datas);
//    connect(MainWindow::mutualUi, &MainWindow::sign_MysqlSearchDatas, m_MYSQLDatas, &MMYSQLDatas::slot_searchDatas);


    Init_model_mysql();
    m_MYSQLDatas->pThread->start();
}

MFormMysql::~MFormMysql()
{
    delete ui;
}

void MFormMysql::init_TableV()
{
    m_tableV = new QTableView();
    m_tableV->setMaximumHeight(100);
    m_standardItemModel = new QStandardItemModel(this);

    QStringList hlabels = {"序号", "流水号", "日期", "结果"};
    m_standardItemModel->setHorizontalHeaderLabels(hlabels);

    m_tableV->setModel(m_standardItemModel);

    m_tableV_DJ = new QTableView();
    m_standardItemModel_DJ = new QStandardItemModel(this);
    m_tableV_DJ->setModel(m_standardItemModel_DJ);

}
/**
 * @brief MFormMysql::Init_model_mysql
 */
void MFormMysql::Init_model_mysql()
{
    //数据库表格模型 - 工位
    m_MYSQLDatas->modelTable_mysql_Station->setTable(MYSQL_TABLE_JL_Datas);
//    m_MYSQLDatas->modelTable_mysql->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_MYSQLDatas->modelTable_mysql_Station->select();
    ui->tableView->setModel(m_MYSQLDatas->modelTable_mysql_Station);
    ui->tableView->verticalHeader()->hide();

}
/**
 * @brief MFormMysql::download_Objects  下载
 * @param arg1
 */
void MFormMysql::download_Objects(const QString &arg1)
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
void MFormMysql::upload_Objects(const QString &arg1)
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
/**
 * @brief MFormMysql::tableViewToHtml
 * @param tableView
 * @return
 */
QString MFormMysql::tableViewToHtml(QTableView *tableView) {
    // 1. 获取表格的模型
    QAbstractItemModel *model = tableView->model();
    if (!model) {
        return QString();
    }

    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    // 2. 开始构建HTML字符串
    QString html;
    QTextStream stream(&html);

    // 3. 写入HTML基础结构及表格样式
    stream << "<!DOCTYPE html>\n";
    stream << "<html>\n<head>\n";
    stream << "<meta charset=\"UTF-8\">\n";
    stream << "<style>\n";
    stream << "  table { border-collapse: collapse; width: 100%; }\n";
    stream << "  th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n";
    stream << "  th { background-color: #4CAF50; color: white; }\n";
    stream << "  tr:nth-child(even) { background-color: #f2f2f2; }\n";
    stream << "</style>\n";
    stream << "</head>\n<body>\n";

    // 4. 创建表格标签
    stream << "<table>\n";

    // 5. 生成表头（<thead>）
    stream << "  <thead>\n    <tr>\n";
    for (int col = 0; col < colCount; ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        // 使用HTML转义防止特殊字符破坏结构
        stream << "      <th>" << header.toHtmlEscaped() << "</th>\n";
    }
    stream << "    </tr>\n  </thead>\n";

    // 6. 生成表格体（<tbody>）
    stream << "  <tbody>\n";
    for (int row = 0; row < rowCount; ++row) {
        stream << "    <tr>\n";
        for (int col = 0; col < colCount; ++col) {
            QModelIndex index = model->index(row, col);
            // 获取单元格数据并转换为字符串，同时进行HTML转义
            QString cellText = model->data(index).toString();
            stream << "      <td>" << cellText.toHtmlEscaped() << "</td>\n";
        }
        stream << "    </tr>\n";
    }
    stream << "  </tbody>\n";

    // 7. 闭合表格及HTML标签
    stream << "</table>\n";
    stream << "</body>\n</html>";

    return html;
}

// 使用示例：保存HTML到文件
void MFormMysql::saveTableViewAsHtml(QTableView *tableView, const QString &fileName) {
    QString html = tableViewToHtml(tableView);
    if (html.isEmpty()) {
        qDebug() << "Failed to generate HTML.";
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setCodec("UTF-8"); // 确保写入UTF-8编码
        out << html;
        file.close();
        qDebug() << "HTML saved to:" << fileName;
    }
}

//QString tableViewToHtmlViaDelegate(QTableView *tableView) {
//    // ... (HTML头、样式、表头部分与方法一相同) ...

//    // 关键区别：获取单元格显示的文本
//    for (int row = 0; row < rowCount; ++row) {
//        stream << "    <tr>\n";
//        for (int col = 0; col < colCount; ++col) {
//            QModelIndex index = model->index(row, col);
//            // 通过样式委托获取单元格的显示文本
//            QString cellText = tableView->itemDelegate(index)->displayText(model->data(index), QLocale::system());
//            stream << "      <td>" << cellText.toHtmlEscaped() << "</td>\n";
//        }
//        stream << "    </tr>\n";
//    }

//    // ... (闭合标签部分与方法一相同) ...
//}
bool MFormMysql::importXlsxToTableView(const QString &filePath, QStandardItemModel *model)
{
    // 2. 使用QtXlsx打开文件
//    QXlsx::Document xlsx(filePath);
//    if (!xlsx.load()) {
//        qDebug() << "加载文件失败" << filePath;
//        return false;
//    }

//    // 3. 读取工作表（默认读取第一个）
//    int maxRow = xlsx.dimension().lastRow();    // 最大行
//    int maxCol = xlsx.dimension().lastColumn(); // 最大列

//    // 4. 可选：设置表头
//    for (int col = 1; col <= maxCol; ++col) {
//        QXlsx::Cell *cell = xlsx.cellAt(3, col); // 假设第一行是表头
//        if (cell) {
//            model->setHorizontalHeaderItem(col-1,
//                                           new QStandardItem(cell->value().toString()));
//        }
//    }

//    // 5. 读取数据（如果第一行是表头，从第二行开始）
//    for (int row = 4; row <= maxRow; ++row) { // 从第2行开始
//        QList<QStandardItem*> rowItems;
//        for (int col = 1; col <= maxCol; ++col) {
//            QVariant cellValue = xlsx.read(row, col); // 读取单元格
//            QStandardItem *item = new QStandardItem(cellValue.toString());
//            rowItems.append(item);
//        }
//        model->appendRow(rowItems);
//    }

//    // 7. 优化显示
//    m_tableV_DJ->resizeColumnsToContents(); // 自动调整列宽
//    m_tableV_DJ->setAlternatingRowColors(true); // 隔行变色

    return true;
}


MMYSQLDatas::MMYSQLDatas(QObject *parent)
{
    Q_UNUSED(parent);
    pThread = new QThread();
    this->moveToThread(pThread);
    connect(pThread, &QThread::started, this, &MMYSQLDatas::connectMYSQL);
}

MMYSQLDatas::~MMYSQLDatas()
{
    pThread->deleteLater();
}
/**
 * @brief MMYSQLDatas::connectMYSQL 链接数据库
 */
void MMYSQLDatas::connectMYSQL()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(m_FormMysql->hostName);//
    db.setPort(3306);
    db.setDatabaseName(m_FormMysql->databaseName);//
    db.setUserName(m_FormMysql->userName);
    db.setPassword(m_FormMysql->password);
    B_Connect = false;
    QString mesg;
    while(!B_Connect){
        pThread->sleep(1);
        if(!db.open()){
            B_Connect = false;
            emit sign_setled(MFormJLStation::mutualUi->ui->led_sql, m_color::Red);
            mesg = "链接数据库失败" + db.lastError().text();
            emit sign_Tips(mesg, m_color::Red);
            qDebug() << mesg;
            qDebug() << "[MYSQL_DEBUG]"
                     << "driver=QODBC"
                     << "host=" << m_FormMysql->hostName
                     << "port=" << 3306
                     << "databaseName=" << m_FormMysql->databaseName
                     << "userName=" << m_FormMysql->userName
                     << "isValid=" << db.isValid();
            qDebug() << "[MYSQL_DEBUG]"
                     << "nativeErrorCode=" << db.lastError().nativeErrorCode()
                     << "driverText=" << db.lastError().driverText()
                     << "databaseText=" << db.lastError().databaseText()
                     << "fullText=" << db.lastError().text();
        }else{
            B_Connect = true;
            emit sign_setled(MFormJLStation::mutualUi->ui->led_sql, m_color::Green);
            mesg = "链接数据库成功";
            emit sign_Tips(mesg);
            qDebug() << mesg;
//            showTableNames();
        }
    }
}

/**
 * @brief MMYSQLDatas::insert_JLDatas  插入数据
 * @param mst_datas
 */
void MMYSQLDatas::insert_JLDatas(MST_MYSQL_Datas &mst_datas)
{
    QString str = "INSERT INTO " + QString(MYSQL_TABLE_JL_Datas) + " (product_number, eq_number, channel, product_code, batch, operator_id, testing_start_time, testing_finished_time, testing_time, "
                  "testing_result, testing_pressuse, testing_leackage_value, testing_result_2, testing_pressuse_2, testing_leackage_value_2,finished_product_code)" +  tr(" VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15','%16')")
            .arg(mst_datas.product_number, mst_datas.eq_number, mst_datas.channel, mst_datas.product_code, mst_datas.batch, mst_datas.operator_id,
                 mst_datas.testing_start_time,mst_datas.testing_finished_time, mst_datas.testing_time, mst_datas.testing_result, mst_datas.testing_pressuse, mst_datas.testing_leackage_value,
                 mst_datas.testing_result_2, mst_datas.testing_pressuse_2, mst_datas.testing_leackage_value_2,mst_datas.product_code_print);

    qDebug() << str;
    QSqlQuery query;
    query.prepare(str);
    if(query.exec()){
        qDebug() << "插入数据成功";
    }else{
        qDebug() << "插入数据失败" << query.lastError().text();
    }
}
/**
 * @brief MMYSQLDatas::slot_update_JLDatas
 */
void MMYSQLDatas::slot_update_JLDatas(MST_MYSQL_Datas mst_datas)
{
//    QString str = tr("SELECT id FROM %1 WHERE product_code='%2'") .arg(MYSQL_TABLE_JL_Datas, mst_datas.product_code);

//    QSqlQuery query;
//    query.prepare(str);
//    qDebug() << str;

//    if(query.exec()){
//        int id = 0;
//        while(query.next()){
//            id = query.value(0).toUInt();
//        }
//        if(id == 0){
            return insert_JLDatas(mst_datas);
//        }else{
//            str = "UPDATE " + QString(MYSQL_TABLE_JL_Datas) + tr(" SET product_number='%1', eq_number='%2', channel='%3', product_code='%4', batch='%5', operator_id='%6', testing_start_time='%7', testing_finished_time='%8', "
//                     "testing_time='%9', testing_result='%10', testing_pressuse='%11', testing_leackage_value='%12', "
//                     "testing_result_2='%13', testing_pressuse_2='%14', testing_leackage_value_2='%15'")
//                    .arg(mst_datas.product_number, mst_datas.eq_number, mst_datas.channel, mst_datas.product_code, mst_datas.batch, mst_datas.operator_id,
//                         mst_datas.testing_start_time, mst_datas.testing_finished_time, mst_datas.testing_time,
//                         mst_datas.testing_result, mst_datas.testing_pressuse, mst_datas.testing_leackage_value,
//                         mst_datas.testing_result_2, mst_datas.testing_pressuse_2, mst_datas.testing_leackage_value_2) + tr(" WHERE id=%1").arg(id);

//            qDebug() << str;
//            query.prepare(str);
//            if(query.exec()){
//                qDebug() << "更新数据成功";
//            }else{
//                qDebug() << "更新数据失败" << query.lastError().text();
//            }
//        }
//    }else{
//        qDebug() << "搜索数据失败" << query.lastError().text();
//    }
}

/**
 * @brief MMYSQLDatas::slot_searchDatas 查询数据
 */
void MMYSQLDatas::slot_searchDatas()
{
    QString str = tr("SELECT * FROM %1 WHERE 序号=1").arg(MYSQL_TABLE_OEE);

    QSqlQuery query(db);
    query.prepare(str);

    if(query.exec()){
        int id = 0;
        QStringList list_OEEDatas;
        while(query.next()){
            id = query.value(0).toInt();
            list_OEEDatas.append(query.value(1).toString());
            list_OEEDatas.append(query.value(2).toString());
            list_OEEDatas.append(query.value(3).toString());
            list_OEEDatas.append(query.value(4).toString());
            list_OEEDatas.append(query.value(5).toString());
            list_OEEDatas.append(query.value(6).toString());
        }
        if(id != 0){
            emit sign_OEEDisplay(list_OEEDatas);
        }
    }else{
        qDebug() << query.lastError();
    }
}

/**
 * @brief MMYSQLDatas::slot_MYSQL_updateTheoreticalQuantity 更新理论生产个数
 * @param value
 */
void MMYSQLDatas::slot_MYSQL_updateTheoreticalQuantity(const uint value)
{
    QString str = tr("UPDATE oee SET 理论生产个数='%1' WHERE 序号=1").arg(value);
    QSqlQuery query(db);
    query.prepare(str);

    if(query.exec()){
        qDebug() << "更新理论生产个数成功";
    }else{
        qDebug() << "更新理论生产个数失败";
    }
}
/**
 * @brief MMYSQLDatas::slot_MYSQL_updateRealQuantity    更新实际生产个数
 * @param value
 */
void MMYSQLDatas::slot_MYSQL_updateRealQuantity(const uint value)
{
    QString str = tr("UPDATE oee SET 实际生产个数='%1' WHERE 序号=1").arg(value);
    QSqlQuery query(db);
    query.prepare(str);
    if(query.exec()){
        qDebug() << "更新实际生产个数成功";
    }else{
        qDebug() << "更新实际生产个数失败";
    }
}
/**
 * @brief MMYSQLDatas::slot_MYSQL_updateRemainingQuantity    更新实际生产个数
 * @param value
 */
void MMYSQLDatas::slot_MYSQL_updateRemainingQuantity(const uint value)
{
    QString str = tr("UPDATE oee SET 剩余生产个数='%1' WHERE 序号=1").arg(value);
    QSqlQuery query(db);
    query.prepare(str);
    if(query.exec()){
        qDebug() << "更新剩余生产个数成功";
    }else{
        qDebug() << "更新剩余生产个数失败";
    }
}

/**
 * @brief MMYSQLDatas::slot_MYSQL_queryDatas_rfid   获取工位历史数据
 * @param rfid
 */
void MMYSQLDatas::slot_MYSQL_queryDatas_rfid(const QString rfid)
{
    QString str1 = "SELECT * FROM " + QString(MYSQL_TABLE_STATION) + tr(" WHERE rfid='%1'").arg(rfid);
    QSqlQuery query;
    query.prepare(str1);
    QString mesg;

    if(!query.exec()){
        mesg = "SQL SELECT ERR" + query.lastError().text();
        qDebug() << mesg;
        emit sign_Tips(mesg);

    }else{

        QStringList record_hlabels, record_datas;
        QMap<QString, QStringList>map_rec_datas;
        QSqlRecord record;
        int count_exe = 0;
        int count_hlabels = 0;//搜索字段的数量

        while(query.next()){
            if(count_exe == 0){//记录搜寻字段名称
                record = query.record();
                count_hlabels = record.count();
                for(int i=0; i<count_hlabels; i++){
                    record_hlabels << record.field(i).name();
                }
            }
            for(int i=0; i<count_hlabels; i++){//记录行数据
                record_datas << query.value(i).toString();
            }
            map_rec_datas.insert(record_datas.at(3), record_datas);//加入字典
            count_exe ++;
            //清除单行数据
            record_datas.clear();
        }
        if(count_hlabels == 0){
            mesg = "There is currently no data for the current serial number:" + rfid;
            qDebug() << mesg;
            emit sign_Tips(mesg);
        }else{
            emit sign_Display_OP_Datas(record_hlabels, map_rec_datas.last());
        }
    }
}

void MFormMysql::load_File_INI()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings INI_File(path, QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File.beginGroup("MYSQL");
    ui->Set_MysqlHostName->setText(INI_File.value("hostName", "127.0.0.1").toString());
    ui->Set_MysqlPort->setText(INI_File.value("port", "3306").toString());
    ui->Set_MysqlDatabaseName->setText(INI_File.value("databaseName", "MYSQL").toString());
    ui->Set_MysqlUserName->setText(INI_File.value("userName", "admin1").toString());
    ui->Set_MysqlPassword->setText(INI_File.value("password", "123456").toString());
    INI_File.endGroup();

    INI_File.destroyed();

    hostName = ui->Set_MysqlHostName->text();
    port = ui->Set_MysqlPort->text();
    databaseName = ui->Set_MysqlDatabaseName->text();
    userName = ui->Set_MysqlUserName->text();
    password = ui->Set_MysqlPassword->text();
}

void MFormMysql::on_Btn_SavePars_clicked()
{
    QString path = QApplication::applicationDirPath() + "/System/System.ini";
    QSettings INI_File(path, QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));

    INI_File.setValue("MYSQL/hostName",  ui->Set_MysqlHostName->text());
    INI_File.setValue("MYSQL/port", ui->Set_MysqlPort->text());
    INI_File.setValue("MYSQL/databaseName", ui->Set_MysqlDatabaseName->text());
    INI_File.setValue("MYSQL/userName", ui->Set_MysqlUserName->text());
    INI_File.setValue("MYSQL/password", ui->Set_MysqlPassword->text());

    INI_File.destroyed();

    hostName = ui->Set_MysqlHostName->text();
    port = ui->Set_MysqlPort->text();
    databaseName = ui->Set_MysqlDatabaseName->text();
    userName = ui->Set_MysqlUserName->text();
    password = ui->Set_MysqlPassword->text();

    QMessageBox::information(this, "Parameter Settings", "Parameters saved successfully");
}

/**
 * @brief MFormMysql::slot_Display_OP_Datas 工位数据
 * @param list_hlabels
 * @param list_datas
 */
void MFormMysql::slot_Display_OP_Datas(QStringList list_hlabels, QStringList list_datas)
{
//    if(list_datas.count() == 0){
//        MainWindow::mutualUi->slot_Tips("无数据导出");
//        return;
//    }
//    m_standardItemModel->clear();
//    m_standardItemModel->setHorizontalHeaderLabels(list_hlabels);
//    QList<QStandardItem*> list_StandardItem;
//    foreach(QString str, list_datas){
//        QStandardItem *item = new QStandardItem(str);
//        list_StandardItem.append(item);
//    }
//    m_standardItemModel->appendRow(list_StandardItem);

//    QCoreApplication::processEvents();

//    QString xlsxPath = uploadXlsx(list_hlabels, list_datas);

//    if(MainWindow::mutualUi->scancode_mode == "打印报告"){
//        if(Pre_uplineCode != list_datas[3]){
//            Pre_uplineCode = list_datas[3];//记录导出条码数据

//            m_FormPrinterA4->printeReport(xlsxPath);
//            QCoreApplication::processEvents();
//            QString dirname = Pre_uplineCode.mid(4, 6);
//            QString filename = tr("Z:\\%1\\%2.xlsm").arg(dirname, Pre_uplineCode);
//            m_FormPrinterA4->printeReport(filename);

//            emit sign_MYSQL_updateRealQuantity(++mst_Data_OEE.RealQuantity);
//        }
//    }else{

//    }
}
/**
 * @brief MFormMysql::uploadXlsx    把数据填入表格
 * @param excelPath
 */
QString MFormMysql::uploadXlsx(QStringList &list_hlabels, QStringList &list_datas)
{
//    using namespace QXlsx;
//    // 1. 读取 Excel 文件
//    QString fileName = FILE_REPORT_PATH + list_datas[3] + ".xlsx";
//    Document xlsxDoc;

//    //首行信息
//    xlsxDoc.write(1,1, "频道号：");
//    xlsxDoc.write(1,2, list_datas[1]);
//    xlsxDoc.write(1,3, "产品型号：");
//    xlsxDoc.write(1,4, list_datas[2]);
//    xlsxDoc.write(1,5, "产品绑定码：" );
//    xlsxDoc.write(1,6, list_datas[3]);

//    //安规检测
//    xlsxDoc.write(2,1, "安规检测");
//    int be = list_hlabels.indexOf("安规耐压电压和电流1") - 1;
//    if(be >= 0){
//        xlsxDoc.write(3,1, "安规交流耐压检测");
//        xlsxDoc.write(3,2, "安规直流耐压检测");
//        xlsxDoc.write(3,3, "安规绝缘检测");
//        xlsxDoc.write(3,4, "安规接地检测");

//        xlsxDoc.write(4,1, "[结果]电压KV，电流mA:" + list_datas[be + 1]);
//        xlsxDoc.write(4,2, "[结果]电压KV，电流mA:" + list_datas[be + 2]);
//        xlsxDoc.write(4,3, "[结果]电压KV,电阻mΩ:" + list_datas[be + 3]);
//        xlsxDoc.write(4,4, "[结果]电流A，电阻mΩ:" + list_datas[be + 4]);
//    }

//    xlsxDoc.write(6,1, "氮气保压");
//    be = list_hlabels.indexOf("氮气保压通道") - 1;
//    if(be >= 0){
//        xlsxDoc.write(7,1, "氮气保压预设压力");
//        xlsxDoc.write(7,2, "氮气保压泄漏量");
//        xlsxDoc.write(7,3, "氮气保压产品压力");
//        xlsxDoc.write(7,4, "氮气保压进口压力");
//        xlsxDoc.write(7,5, "氮气保压加气时间");
//        xlsxDoc.write(7,6, "氮气保压保压时间");
//        xlsxDoc.write(7,7, "氮气保压排气时间");

//        xlsxDoc.write(8,1, list_datas[be + 1]);
//        xlsxDoc.write(8,2, list_datas[be + 2]);
//        xlsxDoc.write(8,3, list_datas[be + 3]);
//        xlsxDoc.write(8,4, list_datas[be + 4]);
//        xlsxDoc.write(8,5, list_datas[be + 5]);
//        xlsxDoc.write(8,6, list_datas[be + 6]);
//        xlsxDoc.write(8,7, list_datas[be + 7]);
//    }

//    xlsxDoc.write(10,1, "气密性检测");
//    be = list_hlabels.indexOf("检漏1状态") - 1;
//    if(be >= 0){
//        xlsxDoc.write(11,1, "检漏1数据");
//        xlsxDoc.write(11,2, list_datas[be + 2]);

//    }

//    xlsxDoc.write(13,1, "加注机");
//    be = list_hlabels.indexOf("A枪状态") - 1;
//    if(be >= 0){

//        xlsxDoc.write(14,1, "A枪品名");
//        xlsxDoc.write(14,2, "A枪加注量g");
//        xlsxDoc.write(14,3, "A枪实时加注量g");
//        xlsxDoc.write(14,4, "A枪加注压力MPa");
//        xlsxDoc.write(14,5, "A枪实时真空值Pa");
//        xlsxDoc.write(14,6, "A枪加注时间s");

//        xlsxDoc.write(15,1, list_datas[be + 1]);
//        xlsxDoc.write(15,2, list_datas[be + 2]);
//        xlsxDoc.write(15,3, list_datas[be + 3]);
//        xlsxDoc.write(15,4, list_datas[be + 4]);
//        xlsxDoc.write(15,5, list_datas[be + 5]);
//        xlsxDoc.write(15,6, list_datas[be + 6]);


//        xlsxDoc.write(16,1, "B枪品名");
//        xlsxDoc.write(16,2, "B枪加注量g");
//        xlsxDoc.write(16,3, "B枪实时加注量g");
//        xlsxDoc.write(16,4, "B枪加注压力MPa");
//        xlsxDoc.write(16,5, "B枪实时真空值Pa");
//        xlsxDoc.write(16,6, "B枪加注时间s");

//        xlsxDoc.write(17,1, list_datas[be + 1]);
//        xlsxDoc.write(17,2, list_datas[be + 2]);
//        xlsxDoc.write(17,3, list_datas[be + 3]);
//        xlsxDoc.write(17,4, list_datas[be + 4]);
//        xlsxDoc.write(17,5, list_datas[be + 5]);
//        xlsxDoc.write(17,6, list_datas[be + 6]);
//    }
//    QString mesg;
//    if(!xlsxDoc.saveAs(fileName)){
//        mesg = "导出数据保存表格失败：" + list_datas[3];
//        qDebug() << mesg;
//        MainWindow::mutualUi->slot_Tips(mesg, m_color::Red);
//        return "";
//    }else{
//        mesg = "导出数据保存表格成功：" + list_datas[3];
//        qDebug() << mesg;
//        MainWindow::mutualUi->slot_Tips(mesg, m_color::black);
//        return fileName;
//    }
}
/**
 * @brief MFormMysql::on_BTN_query_datas_clicked    条码查询
 */
void MFormMysql::on_BTN_query_datas_clicked()
{
    uint allPage = ui->allPage->value();
    uint pageOffset = allPage * (ui->CurPage->value() - 1);

    QStringList queryInfos;
    queryInfos.append(ui->LE_LIKE->text());
    emit sign_MYSQL_model_query("总成码查询", QString(MYSQL_TABLE_JL_Datas), queryInfos, allPage, pageOffset);
}
/**
 * @brief MForm_MYSQL::on_BTN_query_datas_Date_clicked  日期查询
 */
void MFormMysql::on_BTN_query_datas_Date_clicked()
{
    uint allPage = ui->allPage->value();
    uint pageOffset = allPage * (ui->CurPage->value() - 1);

    QStringList queryInfos;

    queryInfos.append(ui->dateEdit_Begin->text() + " 00:00:00");
    queryInfos.append(ui->dateEdit_End->text() + " 23:59:59");

    emit sign_MYSQL_model_query("日期查询", QString(MYSQL_TABLE_JL_Datas), queryInfos, allPage, pageOffset);
}

void MMYSQLDatas::slot_MYSQL_model_query(const QString queryKind, const QString queryTable, const QStringList queryInfos, const uint allPage, const uint pageOffset)
{
    if(queryKind == "零部件查询"){
        QString selectStr = "SELECT * FROM " + queryTable + tr(" WHERE 工位1_扫码1='%1' OR 工位1_扫码2='%1' OR 工位1_扫码3='%1' OR 工位1_扫码4='%1' OR 工位1_扫码5='%1' OR 工位1_扫码6='%1'"
                                                               " OR 工位2_扫码1='%1' OR 工位2_扫码2='%1' OR 工位2_扫码3='%1' OR 工位2_扫码4='%1' OR 工位2_扫码5='%1' OR 工位2_扫码6='%1'"
                                                               " OR 工位3_扫码1='%1' OR 工位3_扫码2='%1' OR 工位3_扫码3='%1' OR 工位3_扫码4='%1' OR 工位3_扫码5='%1' OR 工位3_扫码6='%1'"
                                                               " OR 工位4_扫码1='%1' OR 工位4_扫码2='%1' OR 工位4_扫码3='%1' OR 工位4_扫码4='%1' OR 工位4_扫码5='%1' OR 工位4_扫码6='%1'"
                                                               " OR 工位5_扫码1='%1' OR 工位5_扫码2='%1' OR 工位5_扫码3='%1' OR 工位5_扫码4='%1' OR 工位5_扫码5='%1' OR 工位5_扫码6='%1'"
                                                               " OR 工位6_扫码1='%1' OR 工位6_扫码2='%1' OR 工位6_扫码3='%1' OR 工位6_扫码4='%1' OR 工位6_扫码5='%1' OR 工位6_扫码6='%1'"
                                                               " OR 工位7_扫码1='%1' OR 工位7_扫码2='%1' OR 工位7_扫码3='%1' OR 工位7_扫码4='%1' OR 工位7_扫码5='%1' OR 工位7_扫码6='%1'"
                                                               " OR 工位9_扫码1='%1' OR 工位9_扫码2='%1' OR 工位3_扫码9='%1' OR 工位9_扫码4='%1' OR 工位9_扫码5='%1' OR 工位9_扫码6='%1'"
                                                                 " LIMIT %2 OFFSET %3")
                .arg(queryInfos.first())
                .arg(allPage)
                .arg(allPage * pageOffset);

        Select_Data = tr(" WHERE 工位1_扫码1='%1' OR 工位1_扫码2='%1' OR 工位1_扫码3='%1' OR 工位1_扫码4='%1' OR 工位1_扫码5='%1' OR 工位1_扫码6='%1'"
                                       " OR 工位2_扫码1='%1' OR 工位2_扫码2='%1' OR 工位2_扫码3='%1' OR 工位2_扫码4='%1' OR 工位2_扫码5='%1' OR 工位2_扫码6='%1'"
                                       " OR 工位3_扫码1='%1' OR 工位3_扫码2='%1' OR 工位3_扫码3='%1' OR 工位3_扫码4='%1' OR 工位3_扫码5='%1' OR 工位3_扫码6='%1'"
                                       " OR 工位4_扫码1='%1' OR 工位4_扫码2='%1' OR 工位4_扫码3='%1' OR 工位4_扫码4='%1' OR 工位4_扫码5='%1' OR 工位4_扫码6='%1'"
                                       " OR 工位5_扫码1='%1' OR 工位5_扫码2='%1' OR 工位5_扫码3='%1' OR 工位5_扫码4='%1' OR 工位5_扫码5='%1' OR 工位5_扫码6='%1'"
                                       " OR 工位6_扫码1='%1' OR 工位6_扫码2='%1' OR 工位6_扫码3='%1' OR 工位6_扫码4='%1' OR 工位6_扫码5='%1' OR 工位6_扫码6='%1'"
                                       " OR 工位7_扫码1='%1' OR 工位7_扫码2='%1' OR 工位7_扫码3='%1' OR 工位7_扫码4='%1' OR 工位7_扫码5='%1' OR 工位7_扫码6='%1'"
                                       " OR 工位9_扫码1='%1' OR 工位9_扫码2='%1' OR 工位3_扫码9='%1' OR 工位9_扫码4='%1' OR 工位9_扫码5='%1' OR 工位9_扫码6='%1'")
                .arg(queryInfos.first());

        m_MYSQLDatas->modelTable_mysql_Station->QSqlQueryModel::setQuery(selectStr);

        int row_count = m_MYSQLDatas->modelTable_mysql_Station->rowCount();
        QStringList sss;
        for(int i=0; i<row_count; ++i) {
            QSqlRecord firstRecord = m_MYSQLDatas->modelTable_mysql_Station->record(i);
            if(firstRecord.contains("流水号")){
                sss.append(tr(" 流水号='%1' ").arg(m_MYSQLDatas->modelTable_mysql_Station->record(i).value("流水号").toString()));
            }
        }


    }else if(queryKind == "总成码查询"){

        QString selectStr = "SELECT * FROM " + queryTable + tr(" WHERE product_code='%1' or finished_product_code='%1' LIMIT %2 OFFSET %3")
                .arg(queryInfos.first())
                .arg(allPage)
                .arg(allPage * pageOffset);
        Select_Data = tr(" WHERE product_code='%1'").arg(queryInfos.first());

        m_MYSQLDatas->modelTable_mysql_Station->QSqlQueryModel::setQuery(selectStr);

    }else if(queryKind == "日期查询"){

        QString begin_time = queryInfos.first() + " 00:00:00";
        QString end_time = queryInfos.last() + " 23:59:59";

        QString selectStr = "SELECT * FROM " + queryTable + tr(" WHERE testing_start_time>='%1' AND testing_finished_time<='%2' LIMIT %3 OFFSET %4")
                .arg(begin_time, end_time)
                .arg(allPage)
                .arg(allPage * pageOffset);

        Select_Data = tr(" WHERE testing_start_time>='%1' AND testing_finished_time<='%2'").arg(begin_time, end_time);

        m_MYSQLDatas->modelTable_mysql_Station->QSqlQueryModel::setQuery(selectStr);
    }
}
/**
 * @brief MFormMysql::on_BTN_Export_Data_clicked    导出数据
 */
void MFormMysql::on_BTN_Export_Data_clicked()
{
        QString filePath = QFileDialog::getSaveFileName(
            this,
            "保存CSV文件",
            QDir::homePath() + "/datas.csv",  // 默认文件名
            "CSV文件 (*.csv);;所有文件 (*.*)"      // 文件类型过滤
        );

    exportSqlModelToCSV(m_MYSQLDatas->modelTable_mysql_Station, filePath);
}



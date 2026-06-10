#include "MFuntions.h"
#include <bitset>
#include <string>
#include <QDebug>


MS_JiaZhuJi ms_JiaZhuJiDatas;
MS_anGui ms_anGuiDatas;
MStruct_PublicVar m_Struct_PublicVar;
MDataBean Databean;
MS_Datas CurWorkPar;


/**
 * @brief MFuntions::MFuntions  其它功能函数
 */
MFuntions::MFuntions()
{

}
// 读取CSV文件的示例函数
bool MFuntions::readCsvByStream(const QString &filePath, QList<QString> &data) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件:" << filePath;
        return false;
    }
    QTextStream in(&file);
    // 设置编码，确保中文等字符正确读取
    in.setCodec("UTF-8");

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // 读取一行并去除首尾空白
        if (line.isEmpty()) continue; // 跳过空行

        // 使用逗号分割字符串，得到一行中的数据字段
//        QStringList fields = line.split(',', Qt::SkipEmptyParts);
        data.append(line);
    }

    file.close();
    return true;
}
QString MFuntions::uint8ToBinaryStringStd(uint16_t value) {
    std::bitset<16> bits(value);
    return QString::fromStdString(bits.to_string());
}

/**
 * @brief MFuntions::mKMutiDir  创建多级目录
 * @param path
 * @return
 */
QString MFuntions::mKMutiDir(const QString path)
{
    QDir dir(path);
    if(dir.exists(path)){
        return path;
    }
    QString parentDir = mKMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if(!dirname.isEmpty()){
        parentPath.mkpath(dirname);
    }
    return parentDir + '/' + dirname;
}
void MFuntions::write_TXT(const QString &filepath, const QList<QString> &list_txt)//重写文本
{
    QFile file(filepath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){

        QTextStream txtOutput(&file);
        foreach(QString msg, list_txt){
            txtOutput << msg << endl;
        }
    }
    file.close();
}
/**
 * @brief MFuntions::append_TXT
 * @param filepath
 * @param list_txt
 */
void MFuntions::append_TXT(const QString &filepath, const QList<QString> &list_txt)//增加
{
    QFile file(filepath);

    if(file.open(QIODevice::Append|QIODevice::Text)){

        QTextStream txtOutput(&file);
        foreach(QString msg, list_txt){
            txtOutput << msg << endl;
        }
    }
    file.close();
}

/**
 * @brief MFuntions::write_INI  写INI文件
 * @param fileName
 * @param group
 * @param data
 */
void MFuntions::write_INI(const QString &fileName, const QString group, QVariant data)
{
    QString path = fileName;
    QSettings INI_File(path, QSettings::IniFormat);
    INI_File.setIniCodec(QTextCodec::codecForName("GB2312"));
    INI_File.setValue(group, data);
    INI_File.destroyed();
}
/**
 * @brief MFuntions::write_CSV  写CSV文件
 * @param fileName
 * @param listDatas
 */
void MFuntions::write_CSV(const QString &fileName, const QStringList listDatas)
{
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        // 处理错误，例如可以抛出异常或者返回错误标志
        return;
    }
    QTextStream out(&file);
    out << listDatas.join(","); // 使用分号作为字段分隔符
    out << "\n"; // 每行结束后换行
    file.close();
}
/**
 * @brief 设置 uint16_t 的某一位为1
 * @param data 要操作的数据
 * @param pos 要设置的位置 (0-F)
 */
void MFuntions::setBit(uint16_t &data, uint16_t pos)
{
    if (pos < 16) {
        data |= (1 << pos);
    }
}
/**
 * @brief 清除 uint16_t 的某一位（设为0）
 * @param data 要操作的数据
 * @param pos 要清除的位置 (0-F)
 */
void MFuntions::clearBit(uint16_t &data, uint16_t pos) {
    if (pos < 16) {
        data &= ~(1 << pos);
    }
}
/**
 * @brief 切换 uint16_t 的某一位（取反）
 * @param data 要操作的数据
 * @param pos 要切换的位置 (0-7)
 */
void MFuntions::toggleBit(uint16_t &data, uint16_t pos) {
    if (pos < 16) {
        data ^= (1 << pos);
    }
}
/**
 * @brief 检查 uint8_t 的某一位是否为1
 * @param data 要检查的数据
 * @param pos 要检查的位置 (0-7)
 * @return 如果该位为1返回true，否则返回false
 */
bool MFuntions::checkBit(uint16_t data, uint16_t pos) {
    if (pos < 16) {
        return (data & (1 << pos)) != 0;
    }
    return false;
}
/**
 * @brief compareBits   异或取反：相同位得1，不同位得0
 * @param a
 * @param b
 * @return
 */
uint16_t MFuntions::compareBits(uint16_t a, uint16_t b) {
    return ~(a ^ b);
}
/**
 * @brief specialBitCompare
 * @param a
 * @param b
 * @return
 */
uint16_t MFuntions::specialBitCompare(uint16_t a, uint16_t b) {
    // (~a) 获取a的每一位取反，这样a的0位会变成1
    // (a & b) 获取a和b都为1的位
    // 两者按位或运算

    return (~a) | (a & b);
}

#ifdef Q_OS_WIN
#include <windows.h>

double MFuntions::getProcessCpuUsage() {
    static ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
    static int numProcessors = 0;
    static HANDLE hProcess = GetCurrentProcess();

    if (numProcessors == 0) {
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        numProcessors = sysInfo.dwNumberOfProcessors;
    }

    FILETIME ftime, fsys, fuser;
    GetSystemTimeAsFileTime(&ftime);
    GetProcessTimes(hProcess, &ftime, &ftime, &fsys, &fuser);

    ULARGE_INTEGER now, sys, user;
    memcpy(&now, &ftime, sizeof(FILETIME));
    memcpy(&sys, &fsys, sizeof(FILETIME));
    memcpy(&user, &fuser, sizeof(FILETIME));

    double percent = 0.0;
    if (lastCPU.QuadPart > 0) {
        ULONGLONG total = (sys.QuadPart - lastSysCPU.QuadPart) +
                         (user.QuadPart - lastUserCPU.QuadPart);
        percent = (total * 100.0) / (now.QuadPart - lastCPU.QuadPart);
        percent /= numProcessors;
    }

    lastCPU = now;
    lastUserCPU = user;
    lastSysCPU = sys;

    return percent;
}
#endif

/**
 * @brief MDataBean::MDataBean  数据类
 */
MDataBean::MDataBean()
{

}

QString generateSimpleTable(const QString &title, const QVector<QStringList> &data, const QStringList &headers);

#include <QFile>
#include <QTextStream>

QString generateSimpleTable(const QString &title, const QVector<QStringList> &data, const QStringList &headers = QStringList())
{
    QString html;
    QTextStream stream(&html);

    stream << "<!DOCTYPE html>\n";
    stream << "<html>\n";
    stream << "<head>\n";
    stream << "<meta charset=\"UTF-8\">\n";
    stream << "<title>" << title << "</title>\n";
    stream << "<style>\n";
    stream << "body { font-family: Arial; margin: 0px;  font-size: 12px;}\n";
    stream << "table { border-collapse: collapse; width: 100%; margin: 0px 0; }\n";
    stream << "th, td { border: 1px solid #ccc; padding: 10px; text-align: left; }\n";
    stream << "th { background-color: #007acc; color: white; }\n";
    stream << "tr:hover { background-color: #f0f8ff; }\n";
    stream << "</style>\n";
    stream << "</head>\n";
    stream << "<body>\n";
    stream << "<h2>" << title << "</h2>\n";
    stream << "<table>\n";

    // 添加表头（如果有）
    if (!headers.isEmpty()){
        stream << "<tr>\n";
        for (const QString &header : headers) {
            stream << "<th>" << header << "</th>\n";
        }
        stream << "</tr>\n";
    }

    // 添加数据行
    for (const QStringList &row : data) {
        stream << "<tr>\n";
        for (const QString &cell : row) {
            stream << "<td>" << cell << "</td>\n";
        }
        stream << "</tr>\n";
    }

    stream << "</table>\n";
    stream << "</body>\n";
    stream << "</html>\n";

    return html;
}

QString MFuntions::createHtmlTableFromStringList(const QList<QStringList>& data) {
    QString html;

    // 开始HTML表格
    html += "<table border='1' cellspacing='0' cellpadding='5' style='border-collapse: collapse;'>\n";

    // 遍历每一行数据
    for (const QStringList& row : data) {
        html += "  <tr>\n";

        // 遍历行中的每个单元格
        for (const QString& cell : row) {
            html += "    <td>" + cell.toHtmlEscaped() + "</td>\n";
        }

        html += "  </tr>\n";
    }

    html += "</table>";

    return html;
}

void createSimpleTableExample()
{
    // 示例数据
    QStringList headers = {"产品", "价格", "库存", "分类"};
    QVector<QStringList> data = {
        {"笔记本电脑", "¥5,999", "25", "电子产品"},
        {"办公椅", "¥899", "15", "家具"},
        {"机械键盘", "¥399", "30", "电子产品"},
        {"显示器", "¥1,299", "8", "电子产品"},
        {"书桌", "¥1,599", "5", "家具"}
    };

    QString html = generateSimpleTable("产品库存表", data, headers);

//    QFile file("product_table.html");
//    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        QTextStream out(&file);
//        out.setCodec("UTF-8");
//        out << html;
//        file.close();
//        qDebug() << "简单HTML表格文件已生成: " << file.fileName();
//    }
}

#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QVector>
#include <QString>

void MFuntions::printVectorToPrinter(const QVector<QString>& vec)
{
    // 创建打印机对象
    QPrinter printer(QPrinter::HighResolution);

    // 显示打印对话框
    QPrintDialog printDialog(&printer);
    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter;
        painter.begin(&printer);

        // 设置字体
        QFont font("Arial", 12);
        painter.setFont(font);

        // 设置起始位置
        int yPos = 100;
        const int lineHeight = 60;

        // 打印标题
        painter.drawText(100, yPos, "Vector Contents:");
        yPos += lineHeight * 2;

        // 打印每个元素
        for (int i = 0; i < vec.size(); ++i) {
            QString line = QString("[%1]: %2").arg(i).arg(vec[i]);
            painter.drawText(100, yPos, line);
            yPos += lineHeight;

            // 如果到达页面底部，开始新页面
            if (yPos > printer.height() - 100) {
                printer.newPage();
                yPos = 100;
            }
        }

        painter.end();
    }
}

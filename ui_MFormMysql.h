/********************************************************************************
** Form generated from reading UI file 'MFormMysql.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORMMYSQL_H
#define UI_MFORMMYSQL_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MFormMysql
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *BTN_query_datas_Date;
    QLabel *label_5;
    QLineEdit *LE_LIKE;
    QDateEdit *dateEdit_Begin;
    QLabel *label_6;
    QDateEdit *dateEdit_End;
    QPushButton *BTN_query_datas;
    QPushButton *BTN_Export_Data;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_8;
    QLineEdit *Set_MysqlDatabaseName;
    QLineEdit *Set_MysqlUserName;
    QLabel *label_2;
    QLineEdit *Set_MysqlPassword;
    QLineEdit *Set_MysqlHostName;
    QLabel *label_7;
    QLabel *label_3;
    QLineEdit *Set_MysqlPort;
    QLabel *label;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_SavePars;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_PageUp;
    QSpinBox *CurPage;
    QLabel *label_4;
    QPushButton *Btn_PageDown;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_14;
    QSpinBox *allPage;

    void setupUi(QDialog *MFormMysql)
    {
        if (MFormMysql->objectName().isEmpty())
            MFormMysql->setObjectName(QString::fromUtf8("MFormMysql"));
        MFormMysql->resize(1249, 681);
        gridLayout_2 = new QGridLayout(MFormMysql);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        BTN_query_datas_Date = new QPushButton(MFormMysql);
        BTN_query_datas_Date->setObjectName(QString::fromUtf8("BTN_query_datas_Date"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BTN_query_datas_Date->sizePolicy().hasHeightForWidth());
        BTN_query_datas_Date->setSizePolicy(sizePolicy);
        BTN_query_datas_Date->setMinimumSize(QSize(120, 31));
        BTN_query_datas_Date->setMaximumSize(QSize(120, 16777215));
        QFont font;
        font.setPointSize(12);
        BTN_query_datas_Date->setFont(font);

        gridLayout->addWidget(BTN_query_datas_Date, 0, 3, 1, 1);

        label_5 = new QLabel(MFormMysql);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 31));
        label_5->setMaximumSize(QSize(120, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        LE_LIKE = new QLineEdit(MFormMysql);
        LE_LIKE->setObjectName(QString::fromUtf8("LE_LIKE"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LE_LIKE->sizePolicy().hasHeightForWidth());
        LE_LIKE->setSizePolicy(sizePolicy1);
        LE_LIKE->setMinimumSize(QSize(0, 31));
        LE_LIKE->setMaximumSize(QSize(16777215, 31));
        LE_LIKE->setFont(font1);

        gridLayout->addWidget(LE_LIKE, 1, 1, 1, 2);

        dateEdit_Begin = new QDateEdit(MFormMysql);
        dateEdit_Begin->setObjectName(QString::fromUtf8("dateEdit_Begin"));
        dateEdit_Begin->setMinimumSize(QSize(121, 31));
        dateEdit_Begin->setMaximumSize(QSize(16777215, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        dateEdit_Begin->setFont(font2);
        dateEdit_Begin->setStyleSheet(QString::fromUtf8(""));
        dateEdit_Begin->setReadOnly(false);
        dateEdit_Begin->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(0, 0, 0)));
        dateEdit_Begin->setCalendarPopup(true);
        dateEdit_Begin->setDate(QDate(2025, 1, 1));

        gridLayout->addWidget(dateEdit_Begin, 0, 1, 1, 1);

        label_6 = new QLabel(MFormMysql);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 31));
        label_6->setMaximumSize(QSize(120, 31));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        dateEdit_End = new QDateEdit(MFormMysql);
        dateEdit_End->setObjectName(QString::fromUtf8("dateEdit_End"));
        dateEdit_End->setMinimumSize(QSize(121, 31));
        dateEdit_End->setMaximumSize(QSize(16777215, 31));
        dateEdit_End->setFont(font2);
        dateEdit_End->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(0, 0, 0)));
        dateEdit_End->setCalendarPopup(true);
        dateEdit_End->setDate(QDate(2025, 1, 1));

        gridLayout->addWidget(dateEdit_End, 0, 2, 1, 1);

        BTN_query_datas = new QPushButton(MFormMysql);
        BTN_query_datas->setObjectName(QString::fromUtf8("BTN_query_datas"));
        sizePolicy.setHeightForWidth(BTN_query_datas->sizePolicy().hasHeightForWidth());
        BTN_query_datas->setSizePolicy(sizePolicy);
        BTN_query_datas->setMinimumSize(QSize(120, 31));
        BTN_query_datas->setMaximumSize(QSize(120, 16777215));
        BTN_query_datas->setFont(font);

        gridLayout->addWidget(BTN_query_datas, 1, 3, 1, 1);

        BTN_Export_Data = new QPushButton(MFormMysql);
        BTN_Export_Data->setObjectName(QString::fromUtf8("BTN_Export_Data"));
        sizePolicy.setHeightForWidth(BTN_Export_Data->sizePolicy().hasHeightForWidth());
        BTN_Export_Data->setSizePolicy(sizePolicy);
        BTN_Export_Data->setMinimumSize(QSize(120, 31));
        BTN_Export_Data->setMaximumSize(QSize(16777215, 16777215));
        BTN_Export_Data->setFont(font);

        gridLayout->addWidget(BTN_Export_Data, 1, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(MFormMysql);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        Set_MysqlDatabaseName = new QLineEdit(tab);
        Set_MysqlDatabaseName->setObjectName(QString::fromUtf8("Set_MysqlDatabaseName"));
        sizePolicy1.setHeightForWidth(Set_MysqlDatabaseName->sizePolicy().hasHeightForWidth());
        Set_MysqlDatabaseName->setSizePolicy(sizePolicy1);
        Set_MysqlDatabaseName->setMaximumSize(QSize(16777215, 31));
        Set_MysqlDatabaseName->setFont(font1);

        gridLayout_8->addWidget(Set_MysqlDatabaseName, 2, 1, 1, 1);

        Set_MysqlUserName = new QLineEdit(tab);
        Set_MysqlUserName->setObjectName(QString::fromUtf8("Set_MysqlUserName"));
        sizePolicy1.setHeightForWidth(Set_MysqlUserName->sizePolicy().hasHeightForWidth());
        Set_MysqlUserName->setSizePolicy(sizePolicy1);
        Set_MysqlUserName->setMaximumSize(QSize(16777215, 31));
        Set_MysqlUserName->setFont(font1);

        gridLayout_8->addWidget(Set_MysqlUserName, 3, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 31));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_2, 3, 0, 1, 1);

        Set_MysqlPassword = new QLineEdit(tab);
        Set_MysqlPassword->setObjectName(QString::fromUtf8("Set_MysqlPassword"));
        sizePolicy1.setHeightForWidth(Set_MysqlPassword->sizePolicy().hasHeightForWidth());
        Set_MysqlPassword->setSizePolicy(sizePolicy1);
        Set_MysqlPassword->setMaximumSize(QSize(16777215, 31));
        Set_MysqlPassword->setFont(font1);
        Set_MysqlPassword->setEchoMode(QLineEdit::Password);

        gridLayout_8->addWidget(Set_MysqlPassword, 4, 1, 1, 1);

        Set_MysqlHostName = new QLineEdit(tab);
        Set_MysqlHostName->setObjectName(QString::fromUtf8("Set_MysqlHostName"));
        sizePolicy1.setHeightForWidth(Set_MysqlHostName->sizePolicy().hasHeightForWidth());
        Set_MysqlHostName->setSizePolicy(sizePolicy1);
        Set_MysqlHostName->setMaximumSize(QSize(16777215, 31));
        Set_MysqlHostName->setFont(font1);

        gridLayout_8->addWidget(Set_MysqlHostName, 0, 1, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 31));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_7, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 31));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_3, 2, 0, 1, 1);

        Set_MysqlPort = new QLineEdit(tab);
        Set_MysqlPort->setObjectName(QString::fromUtf8("Set_MysqlPort"));
        Set_MysqlPort->setEnabled(false);
        sizePolicy1.setHeightForWidth(Set_MysqlPort->sizePolicy().hasHeightForWidth());
        Set_MysqlPort->setSizePolicy(sizePolicy1);
        Set_MysqlPort->setMaximumSize(QSize(16777215, 31));
        Set_MysqlPort->setFont(font1);

        gridLayout_8->addWidget(Set_MysqlPort, 1, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 31));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label, 4, 0, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 31));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_8, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_SavePars = new QPushButton(tab);
        Btn_SavePars->setObjectName(QString::fromUtf8("Btn_SavePars"));
        sizePolicy.setHeightForWidth(Btn_SavePars->sizePolicy().hasHeightForWidth());
        Btn_SavePars->setSizePolicy(sizePolicy);
        Btn_SavePars->setFont(font);

        horizontalLayout->addWidget(Btn_SavePars);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 434, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 3, 1);

        tableView = new QTableView(MFormMysql);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->horizontalHeader()->setMinimumSectionSize(80);
        tableView->horizontalHeader()->setDefaultSectionSize(80);
        tableView->verticalHeader()->setMinimumSectionSize(31);
        tableView->verticalHeader()->setDefaultSectionSize(31);

        gridLayout_2->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Btn_PageUp = new QPushButton(MFormMysql);
        Btn_PageUp->setObjectName(QString::fromUtf8("Btn_PageUp"));
        Btn_PageUp->setEnabled(false);
        sizePolicy.setHeightForWidth(Btn_PageUp->sizePolicy().hasHeightForWidth());
        Btn_PageUp->setSizePolicy(sizePolicy);
        Btn_PageUp->setMinimumSize(QSize(0, 21));
        Btn_PageUp->setMaximumSize(QSize(61, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(9);
        font3.setUnderline(false);
        Btn_PageUp->setFont(font3);
        Btn_PageUp->setAutoDefault(false);
        Btn_PageUp->setFlat(false);

        horizontalLayout_2->addWidget(Btn_PageUp);

        CurPage = new QSpinBox(MFormMysql);
        CurPage->setObjectName(QString::fromUtf8("CurPage"));
        CurPage->setEnabled(false);
        CurPage->setMinimumSize(QSize(0, 21));
        CurPage->setMaximumSize(QSize(31, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setUnderline(false);
        font4.setWeight(50);
        CurPage->setFont(font4);
        CurPage->setFrame(true);
        CurPage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurPage->setReadOnly(true);
        CurPage->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CurPage->setAccelerated(false);
        CurPage->setMinimum(1);
        CurPage->setMaximum(1000);

        horizontalLayout_2->addWidget(CurPage);

        label_4 = new QLabel(MFormMysql);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);
        label_4->setMinimumSize(QSize(21, 21));
        label_4->setMaximumSize(QSize(21, 21));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        Btn_PageDown = new QPushButton(MFormMysql);
        Btn_PageDown->setObjectName(QString::fromUtf8("Btn_PageDown"));
        Btn_PageDown->setEnabled(false);
        sizePolicy.setHeightForWidth(Btn_PageDown->sizePolicy().hasHeightForWidth());
        Btn_PageDown->setSizePolicy(sizePolicy);
        Btn_PageDown->setMinimumSize(QSize(0, 21));
        Btn_PageDown->setMaximumSize(QSize(61, 21));
        Btn_PageDown->setFont(font3);
        Btn_PageDown->setAutoDefault(false);
        Btn_PageDown->setFlat(false);

        horizontalLayout_2->addWidget(Btn_PageDown);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_14 = new QLabel(MFormMysql);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 21));
        label_14->setMaximumSize(QSize(16777215, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(9);
        label_14->setFont(font5);

        horizontalLayout_2->addWidget(label_14);

        allPage = new QSpinBox(MFormMysql);
        allPage->setObjectName(QString::fromUtf8("allPage"));
        sizePolicy.setHeightForWidth(allPage->sizePolicy().hasHeightForWidth());
        allPage->setSizePolicy(sizePolicy);
        allPage->setMinimumSize(QSize(41, 21));
        allPage->setMaximumSize(QSize(16777215, 21));
        allPage->setFont(font);
        allPage->setReadOnly(false);
        allPage->setMinimum(20);
        allPage->setMaximum(1000000);
        allPage->setSingleStep(5);
        allPage->setValue(50);

        horizontalLayout_2->addWidget(allPage);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(MFormMysql);

        Btn_PageUp->setDefault(false);
        Btn_PageDown->setDefault(false);


        QMetaObject::connectSlotsByName(MFormMysql);
    } // setupUi

    void retranslateUi(QDialog *MFormMysql)
    {
        MFormMysql->setWindowTitle(QString());
        BTN_query_datas_Date->setText(QCoreApplication::translate("MFormMysql", "\346\237\245\350\257\242", nullptr));
        label_5->setText(QCoreApplication::translate("MFormMysql", "\346\227\245\346\234\237:", nullptr));
        LE_LIKE->setPlaceholderText(QString());
        dateEdit_Begin->setDisplayFormat(QCoreApplication::translate("MFormMysql", "yyyy-MM-dd", nullptr));
        label_6->setText(QCoreApplication::translate("MFormMysql", "\346\200\273\346\210\220\347\240\201:", nullptr));
        dateEdit_End->setDisplayFormat(QCoreApplication::translate("MFormMysql", "yyyy-MM-dd", nullptr));
        BTN_query_datas->setText(QCoreApplication::translate("MFormMysql", "\346\237\245\350\257\242", nullptr));
        BTN_Export_Data->setText(QCoreApplication::translate("MFormMysql", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("MFormMysql", "UserName:", nullptr));
        label_7->setText(QCoreApplication::translate("MFormMysql", "HostName:", nullptr));
        label_3->setText(QCoreApplication::translate("MFormMysql", "DatabaseName:", nullptr));
        Set_MysqlPort->setText(QCoreApplication::translate("MFormMysql", "3306", nullptr));
        label->setText(QCoreApplication::translate("MFormMysql", "Password:", nullptr));
        label_8->setText(QCoreApplication::translate("MFormMysql", "Port:", nullptr));
        Btn_SavePars->setText(QCoreApplication::translate("MFormMysql", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MFormMysql", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MFormMysql", "Tab 2", nullptr));
        Btn_PageUp->setText(QCoreApplication::translate("MFormMysql", "<", nullptr));
        label_4->setText(QCoreApplication::translate("MFormMysql", "/", nullptr));
        Btn_PageDown->setText(QCoreApplication::translate("MFormMysql", ">", nullptr));
        label_14->setText(QCoreApplication::translate("MFormMysql", "\346\234\200\345\244\247\346\230\276\347\244\272\350\241\214\346\225\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MFormMysql: public Ui_MFormMysql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORMMYSQL_H

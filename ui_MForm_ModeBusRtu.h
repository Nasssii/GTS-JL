/********************************************************************************
** Form generated from reading UI file 'MForm_ModeBusRtu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORM_MODEBUSRTU_H
#define UI_MFORM_MODEBUSRTU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MForm_ModeBusRtu
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;
    QPushButton *Btn_board_1;
    QPushButton *Btn_board_2;
    QTableWidget *led_BSM_1;
    QTableWidget *led_BSM_2;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QComboBox *RS485Com;
    QLabel *label_17;
    QComboBox *Cbt_Baud_RS485;
    QPushButton *Btn_Updata_Com;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_RS485;
    QSpacerItem *horizontalSpacer_3;
    QLabel *led_485;
    QPushButton *Btn_Save;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Btn_loadfile;
    QLabel *led_tips;

    void setupUi(QWidget *MForm_ModeBusRtu)
    {
        if (MForm_ModeBusRtu->objectName().isEmpty())
            MForm_ModeBusRtu->setObjectName(QString::fromUtf8("MForm_ModeBusRtu"));
        MForm_ModeBusRtu->resize(1064, 629);
        gridLayout = new QGridLayout(MForm_ModeBusRtu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(MForm_ModeBusRtu);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("IO configuration"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_2 = new QGridLayout(tab_5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Btn_board_1 = new QPushButton(tab_5);
        Btn_board_1->setObjectName(QString::fromUtf8("Btn_board_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Btn_board_1->sizePolicy().hasHeightForWidth());
        Btn_board_1->setSizePolicy(sizePolicy);
        Btn_board_1->setMinimumSize(QSize(81, 21));
        Btn_board_1->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        Btn_board_1->setFont(font1);
        Btn_board_1->setStyleSheet(QString::fromUtf8("border:0px solid black;"));
        Btn_board_1->setCheckable(true);

        gridLayout_2->addWidget(Btn_board_1, 0, 0, 1, 1);

        Btn_board_2 = new QPushButton(tab_5);
        Btn_board_2->setObjectName(QString::fromUtf8("Btn_board_2"));
        sizePolicy.setHeightForWidth(Btn_board_2->sizePolicy().hasHeightForWidth());
        Btn_board_2->setSizePolicy(sizePolicy);
        Btn_board_2->setMinimumSize(QSize(81, 21));
        Btn_board_2->setMaximumSize(QSize(16777215, 16777215));
        Btn_board_2->setFont(font1);
        Btn_board_2->setStyleSheet(QString::fromUtf8("border:0px solid black;"));
        Btn_board_2->setCheckable(true);

        gridLayout_2->addWidget(Btn_board_2, 0, 1, 1, 1);

        led_BSM_1 = new QTableWidget(tab_5);
        led_BSM_1->setObjectName(QString::fromUtf8("led_BSM_1"));
        led_BSM_1->setFont(font);
        led_BSM_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(led_BSM_1, 1, 0, 1, 1);

        led_BSM_2 = new QTableWidget(tab_5);
        led_BSM_2->setObjectName(QString::fromUtf8("led_BSM_2"));
        led_BSM_2->setFont(font);
        led_BSM_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(led_BSM_2, 1, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        groupBox_9 = new QGroupBox(MForm_ModeBusRtu);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setMinimumSize(QSize(0, 60));
        groupBox_9->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_9);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(groupBox_9);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(81, 16777215));
        label_16->setFont(font1);
        label_16->setWordWrap(true);

        horizontalLayout_7->addWidget(label_16);

        RS485Com = new QComboBox(groupBox_9);
        RS485Com->addItem(QString());
        RS485Com->setObjectName(QString::fromUtf8("RS485Com"));
        RS485Com->setMinimumSize(QSize(121, 31));
        RS485Com->setMaximumSize(QSize(121, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        RS485Com->setFont(font2);
        RS485Com->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout_7->addWidget(RS485Com);

        label_17 = new QLabel(groupBox_9);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setMaximumSize(QSize(81, 16777215));
        label_17->setFont(font1);
        label_17->setWordWrap(true);

        horizontalLayout_7->addWidget(label_17);

        Cbt_Baud_RS485 = new QComboBox(groupBox_9);
        Cbt_Baud_RS485->addItem(QString());
        Cbt_Baud_RS485->addItem(QString());
        Cbt_Baud_RS485->addItem(QString());
        Cbt_Baud_RS485->addItem(QString());
        Cbt_Baud_RS485->setObjectName(QString::fromUtf8("Cbt_Baud_RS485"));
        Cbt_Baud_RS485->setMinimumSize(QSize(81, 31));
        Cbt_Baud_RS485->setMaximumSize(QSize(121, 16777215));
        Cbt_Baud_RS485->setFont(font2);
        Cbt_Baud_RS485->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout_7->addWidget(Cbt_Baud_RS485);

        Btn_Updata_Com = new QPushButton(groupBox_9);
        Btn_Updata_Com->setObjectName(QString::fromUtf8("Btn_Updata_Com"));
        Btn_Updata_Com->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Btn_Updata_Com->sizePolicy().hasHeightForWidth());
        Btn_Updata_Com->setSizePolicy(sizePolicy1);
        Btn_Updata_Com->setMinimumSize(QSize(81, 31));
        Btn_Updata_Com->setMaximumSize(QSize(121, 31));
        Btn_Updata_Com->setFont(font2);
        Btn_Updata_Com->setIconSize(QSize(30, 30));
        Btn_Updata_Com->setAutoRepeat(false);

        horizontalLayout_7->addWidget(Btn_Updata_Com);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        Btn_RS485 = new QPushButton(groupBox_9);
        Btn_RS485->setObjectName(QString::fromUtf8("Btn_RS485"));
        Btn_RS485->setMinimumSize(QSize(161, 31));
        Btn_RS485->setMaximumSize(QSize(161, 16777215));
        Btn_RS485->setFont(font2);

        horizontalLayout_7->addWidget(Btn_RS485);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        led_485 = new QLabel(groupBox_9);
        led_485->setObjectName(QString::fromUtf8("led_485"));
        led_485->setMinimumSize(QSize(21, 21));
        led_485->setMaximumSize(QSize(21, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        led_485->setFont(font3);
        led_485->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 10px;"));
        led_485->setFrameShape(QFrame::Box);
        led_485->setTextFormat(Qt::AutoText);
        led_485->setScaledContents(false);
        led_485->setAlignment(Qt::AlignCenter);
        led_485->setWordWrap(false);

        horizontalLayout_7->addWidget(led_485);

        Btn_Save = new QPushButton(groupBox_9);
        Btn_Save->setObjectName(QString::fromUtf8("Btn_Save"));
        sizePolicy.setHeightForWidth(Btn_Save->sizePolicy().hasHeightForWidth());
        Btn_Save->setSizePolicy(sizePolicy);
        Btn_Save->setFont(font1);

        horizontalLayout_7->addWidget(Btn_Save);


        horizontalLayout_2->addLayout(horizontalLayout_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        Btn_loadfile = new QPushButton(groupBox_9);
        Btn_loadfile->setObjectName(QString::fromUtf8("Btn_loadfile"));
        Btn_loadfile->setMinimumSize(QSize(81, 31));
        Btn_loadfile->setMaximumSize(QSize(16777215, 31));
        Btn_loadfile->setFont(font1);

        horizontalLayout_2->addWidget(Btn_loadfile);


        gridLayout->addWidget(groupBox_9, 0, 0, 1, 1);

        led_tips = new QLabel(MForm_ModeBusRtu);
        led_tips->setObjectName(QString::fromUtf8("led_tips"));
        led_tips->setFont(font);

        gridLayout->addWidget(led_tips, 2, 0, 1, 1);


        retranslateUi(MForm_ModeBusRtu);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MForm_ModeBusRtu);
    } // setupUi

    void retranslateUi(QWidget *MForm_ModeBusRtu)
    {
        MForm_ModeBusRtu->setWindowTitle(QString());
        Btn_board_1->setText(QCoreApplication::translate("MForm_ModeBusRtu", "\345\237\272\345\261\202\346\235\277", nullptr));
        Btn_board_2->setText(QCoreApplication::translate("MForm_ModeBusRtu", "\346\211\251\345\261\225\346\235\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MForm_ModeBusRtu", "IO-Di/CO", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MForm_ModeBusRtu", "SmartBox", nullptr));
        label_16->setText(QCoreApplication::translate("MForm_ModeBusRtu", "Port:", nullptr));
        RS485Com->setItemText(0, QString());

        label_17->setText(QCoreApplication::translate("MForm_ModeBusRtu", "Baud:", nullptr));
        Cbt_Baud_RS485->setItemText(0, QString());
        Cbt_Baud_RS485->setItemText(1, QCoreApplication::translate("MForm_ModeBusRtu", "9600", nullptr));
        Cbt_Baud_RS485->setItemText(2, QCoreApplication::translate("MForm_ModeBusRtu", "19200", nullptr));
        Cbt_Baud_RS485->setItemText(3, QCoreApplication::translate("MForm_ModeBusRtu", "115200", nullptr));

        Btn_Updata_Com->setText(QCoreApplication::translate("MForm_ModeBusRtu", "Refresh", nullptr));
        Btn_RS485->setText(QCoreApplication::translate("MForm_ModeBusRtu", "Connect/Disconnect", nullptr));
        led_485->setText(QString());
        Btn_Save->setText(QCoreApplication::translate("MForm_ModeBusRtu", "OK", nullptr));
        Btn_loadfile->setText(QCoreApplication::translate("MForm_ModeBusRtu", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        led_tips->setText(QCoreApplication::translate("MForm_ModeBusRtu", "##", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MForm_ModeBusRtu: public Ui_MForm_ModeBusRtu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORM_MODEBUSRTU_H

/********************************************************************************
** Form generated from reading UI file 'MFormJLStation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORMJLSTATION_H
#define UI_MFORMJLSTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MFormJLStation
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *LB_productnumber;
    QLineEdit *LE_Product_Number;
    QLabel *LB_equnumber;
    QLineEdit *LE_EQ_Number;
    QLabel *LB_channel;
    QComboBox *CBT_Channel;
    QLabel *LB_batch_number;
    QLineEdit *LE_Batch;
    QLabel *LB_operator;
    QLineEdit *LE_Operator_Code;
    QPushButton *BTN_Save;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *BTN_Get_Object;
    QLabel *led_485;
    QLabel *label_21;
    QLabel *led_sql;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BTN_NeedPlaceNGProduct;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *led_GetCodeOK;
    QLabel *led_LockProduct;
    QLabel *led_Result;
    QLabel *led_Exhaust;
    QLabel *led_Loosen;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QLabel *led_Detection_Pressure;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_18;
    QLabel *led_Leakage_value;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QLabel *led_JL_Result;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *led_DetectionTime;
    QLabel *label_12;
    QPushButton *BTN_Start;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *BTN_Reset;
    QSpacerItem *horizontalSpacer_6;
    QLabel *LB_EMC_Stop;
    QLabel *led_EMC_Stop;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_6;
    QLineEdit *LE_ProductCode;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QLabel *led_Detection_Pressure_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_19;
    QLabel *led_Leakage_value_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLabel *led_JL_Result_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_7;
    QLineEdit *LE_ProductCode_Print;
    QLabel *label;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *logo;
    QGridLayout *gridLayout_2;
    QPushButton *BTN_ATEQ;
    QPushButton *BTN_IO;
    QPushButton *BTN_ScanCode;
    QPushButton *BTN_MFormLabel;
    QPushButton *BTN_MFormMYSQL;
    QLabel *LD_admin;
    QPushButton *BTN_Login;
    QPushButton *BTN_Logout;
    QLabel *label_17;
    QComboBox *CBT_Language;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MFormJLStation)
    {
        if (MFormJLStation->objectName().isEmpty())
            MFormJLStation->setObjectName(QString::fromUtf8("MFormJLStation"));
        MFormJLStation->resize(1600, 900);
        MFormJLStation->setMinimumSize(QSize(120, 0));
        centralwidget = new QWidget(MFormJLStation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 40));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LB_productnumber = new QLabel(frame_3);
        LB_productnumber->setObjectName(QString::fromUtf8("LB_productnumber"));
        LB_productnumber->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(12);
        LB_productnumber->setFont(font);
        LB_productnumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LB_productnumber);

        LE_Product_Number = new QLineEdit(frame_3);
        LE_Product_Number->setObjectName(QString::fromUtf8("LE_Product_Number"));
        LE_Product_Number->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LE_Product_Number->sizePolicy().hasHeightForWidth());
        LE_Product_Number->setSizePolicy(sizePolicy);
        LE_Product_Number->setMinimumSize(QSize(300, 0));
        LE_Product_Number->setFont(font);

        horizontalLayout->addWidget(LE_Product_Number);

        LB_equnumber = new QLabel(frame_3);
        LB_equnumber->setObjectName(QString::fromUtf8("LB_equnumber"));
        LB_equnumber->setMaximumSize(QSize(16777215, 16777215));
        LB_equnumber->setFont(font);
        LB_equnumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LB_equnumber);

        LE_EQ_Number = new QLineEdit(frame_3);
        LE_EQ_Number->setObjectName(QString::fromUtf8("LE_EQ_Number"));
        sizePolicy.setHeightForWidth(LE_EQ_Number->sizePolicy().hasHeightForWidth());
        LE_EQ_Number->setSizePolicy(sizePolicy);
        LE_EQ_Number->setFont(font);

        horizontalLayout->addWidget(LE_EQ_Number);

        LB_channel = new QLabel(frame_3);
        LB_channel->setObjectName(QString::fromUtf8("LB_channel"));
        LB_channel->setMaximumSize(QSize(16777215, 16777215));
        LB_channel->setFont(font);
        LB_channel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LB_channel);

        CBT_Channel = new QComboBox(frame_3);
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->addItem(QString());
        CBT_Channel->setObjectName(QString::fromUtf8("CBT_Channel"));
        sizePolicy.setHeightForWidth(CBT_Channel->sizePolicy().hasHeightForWidth());
        CBT_Channel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        CBT_Channel->setFont(font1);

        horizontalLayout->addWidget(CBT_Channel);

        LB_batch_number = new QLabel(frame_3);
        LB_batch_number->setObjectName(QString::fromUtf8("LB_batch_number"));
        LB_batch_number->setMaximumSize(QSize(16777215, 16777215));
        LB_batch_number->setFont(font);
        LB_batch_number->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LB_batch_number);

        LE_Batch = new QLineEdit(frame_3);
        LE_Batch->setObjectName(QString::fromUtf8("LE_Batch"));
        sizePolicy.setHeightForWidth(LE_Batch->sizePolicy().hasHeightForWidth());
        LE_Batch->setSizePolicy(sizePolicy);
        LE_Batch->setFont(font);

        horizontalLayout->addWidget(LE_Batch);

        LB_operator = new QLabel(frame_3);
        LB_operator->setObjectName(QString::fromUtf8("LB_operator"));
        sizePolicy.setHeightForWidth(LB_operator->sizePolicy().hasHeightForWidth());
        LB_operator->setSizePolicy(sizePolicy);
        LB_operator->setMinimumSize(QSize(100, 0));
        LB_operator->setMaximumSize(QSize(16777215, 16777215));
        LB_operator->setFont(font);
        LB_operator->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LB_operator);

        LE_Operator_Code = new QLineEdit(frame_3);
        LE_Operator_Code->setObjectName(QString::fromUtf8("LE_Operator_Code"));
        sizePolicy.setHeightForWidth(LE_Operator_Code->sizePolicy().hasHeightForWidth());
        LE_Operator_Code->setSizePolicy(sizePolicy);
        LE_Operator_Code->setMinimumSize(QSize(120, 0));
        LE_Operator_Code->setFont(font);

        horizontalLayout->addWidget(LE_Operator_Code);


        horizontalLayout_2->addLayout(horizontalLayout);

        BTN_Save = new QPushButton(frame_3);
        BTN_Save->setObjectName(QString::fromUtf8("BTN_Save"));
        sizePolicy.setHeightForWidth(BTN_Save->sizePolicy().hasHeightForWidth());
        BTN_Save->setSizePolicy(sizePolicy);
        BTN_Save->setMinimumSize(QSize(0, 0));
        BTN_Save->setMaximumSize(QSize(80, 16777215));
        BTN_Save->setFont(font);

        horizontalLayout_2->addWidget(BTN_Save);


        gridLayout->addWidget(frame_3, 1, 0, 1, 2);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 40));
        frame_4->setMaximumSize(QSize(600, 16777215));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        horizontalLayout_8 = new QHBoxLayout(frame_4);
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        BTN_Get_Object = new QPushButton(frame_4);
        BTN_Get_Object->setObjectName(QString::fromUtf8("BTN_Get_Object"));
        sizePolicy.setHeightForWidth(BTN_Get_Object->sizePolicy().hasHeightForWidth());
        BTN_Get_Object->setSizePolicy(sizePolicy);
        BTN_Get_Object->setMaximumSize(QSize(60, 16777215));
        BTN_Get_Object->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));

        horizontalLayout_15->addWidget(BTN_Get_Object);

        led_485 = new QLabel(frame_4);
        led_485->setObjectName(QString::fromUtf8("led_485"));
        led_485->setMinimumSize(QSize(21, 21));
        led_485->setMaximumSize(QSize(21, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        led_485->setFont(font2);
        led_485->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 10px;"));
        led_485->setFrameShape(QFrame::Box);
        led_485->setTextFormat(Qt::AutoText);
        led_485->setScaledContents(false);
        led_485->setAlignment(Qt::AlignCenter);
        led_485->setWordWrap(false);

        horizontalLayout_15->addWidget(led_485);

        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(0, 0));
        label_21->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_21->setFont(font3);
        label_21->setFrameShape(QFrame::NoFrame);
        label_21->setTextFormat(Qt::AutoText);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_21->setWordWrap(false);

        horizontalLayout_15->addWidget(label_21);

        led_sql = new QLabel(frame_4);
        led_sql->setObjectName(QString::fromUtf8("led_sql"));
        led_sql->setMinimumSize(QSize(21, 21));
        led_sql->setMaximumSize(QSize(21, 21));
        led_sql->setFont(font2);
        led_sql->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 10px;"));
        led_sql->setFrameShape(QFrame::Box);
        led_sql->setTextFormat(Qt::AutoText);
        led_sql->setScaledContents(false);
        led_sql->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(led_sql);

        label_24 = new QLabel(frame_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setMaximumSize(QSize(16777215, 16777215));
        label_24->setFont(font3);
        label_24->setFrameShape(QFrame::NoFrame);
        label_24->setTextFormat(Qt::AutoText);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_24->setWordWrap(false);

        horizontalLayout_15->addWidget(label_24);


        horizontalLayout_8->addLayout(horizontalLayout_15);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        BTN_NeedPlaceNGProduct = new QPushButton(frame_4);
        BTN_NeedPlaceNGProduct->setObjectName(QString::fromUtf8("BTN_NeedPlaceNGProduct"));
        BTN_NeedPlaceNGProduct->setEnabled(true);
        BTN_NeedPlaceNGProduct->setStyleSheet(QString::fromUtf8("QPushButton:checked{\n"
"	background-color: rgb(0, 255, 0);\n"
"	color: black;\n"
"}\n"
"QPushButton:!checked{\n"
"	background-color: white;\n"
"color: black;\n"
"}\n"
""));
        BTN_NeedPlaceNGProduct->setCheckable(true);
        BTN_NeedPlaceNGProduct->setChecked(false);

        horizontalLayout_8->addWidget(BTN_NeedPlaceNGProduct);


        gridLayout->addWidget(frame_4, 5, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(600, 16777215));
        groupBox_3->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        led_GetCodeOK = new QLabel(groupBox_3);
        led_GetCodeOK->setObjectName(QString::fromUtf8("led_GetCodeOK"));
        led_GetCodeOK->setMinimumSize(QSize(21, 21));
        led_GetCodeOK->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        led_GetCodeOK->setFont(font4);
        led_GetCodeOK->setFrameShape(QFrame::Panel);
        led_GetCodeOK->setFrameShadow(QFrame::Raised);
        led_GetCodeOK->setTextFormat(Qt::AutoText);
        led_GetCodeOK->setScaledContents(false);
        led_GetCodeOK->setAlignment(Qt::AlignCenter);
        led_GetCodeOK->setWordWrap(false);

        verticalLayout_2->addWidget(led_GetCodeOK);

        led_LockProduct = new QLabel(groupBox_3);
        led_LockProduct->setObjectName(QString::fromUtf8("led_LockProduct"));
        led_LockProduct->setMinimumSize(QSize(21, 21));
        led_LockProduct->setMaximumSize(QSize(16777215, 16777215));
        led_LockProduct->setFont(font4);
        led_LockProduct->setFrameShape(QFrame::Panel);
        led_LockProduct->setFrameShadow(QFrame::Raised);
        led_LockProduct->setTextFormat(Qt::AutoText);
        led_LockProduct->setScaledContents(false);
        led_LockProduct->setAlignment(Qt::AlignCenter);
        led_LockProduct->setWordWrap(false);

        verticalLayout_2->addWidget(led_LockProduct);

        led_Result = new QLabel(groupBox_3);
        led_Result->setObjectName(QString::fromUtf8("led_Result"));
        led_Result->setMinimumSize(QSize(21, 21));
        led_Result->setMaximumSize(QSize(16777215, 16777215));
        led_Result->setFont(font4);
        led_Result->setFrameShape(QFrame::Panel);
        led_Result->setFrameShadow(QFrame::Raised);
        led_Result->setTextFormat(Qt::AutoText);
        led_Result->setScaledContents(false);
        led_Result->setAlignment(Qt::AlignCenter);
        led_Result->setWordWrap(false);

        verticalLayout_2->addWidget(led_Result);

        led_Exhaust = new QLabel(groupBox_3);
        led_Exhaust->setObjectName(QString::fromUtf8("led_Exhaust"));
        led_Exhaust->setMinimumSize(QSize(21, 21));
        led_Exhaust->setMaximumSize(QSize(16777215, 16777215));
        led_Exhaust->setFont(font4);
        led_Exhaust->setFrameShape(QFrame::Panel);
        led_Exhaust->setFrameShadow(QFrame::Raised);
        led_Exhaust->setTextFormat(Qt::AutoText);
        led_Exhaust->setScaledContents(false);
        led_Exhaust->setAlignment(Qt::AlignCenter);
        led_Exhaust->setWordWrap(false);

        verticalLayout_2->addWidget(led_Exhaust);

        led_Loosen = new QLabel(groupBox_3);
        led_Loosen->setObjectName(QString::fromUtf8("led_Loosen"));
        led_Loosen->setMinimumSize(QSize(21, 21));
        led_Loosen->setMaximumSize(QSize(16777215, 16777215));
        led_Loosen->setFont(font4);
        led_Loosen->setFrameShape(QFrame::Panel);
        led_Loosen->setFrameShadow(QFrame::Raised);
        led_Loosen->setTextFormat(Qt::AutoText);
        led_Loosen->setScaledContents(false);
        led_Loosen->setAlignment(Qt::AlignCenter);
        led_Loosen->setWordWrap(false);

        verticalLayout_2->addWidget(led_Loosen);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(800, 0));
        frame->setMaximumSize(QSize(16777214, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 300));
        groupBox->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 16777215));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(true);

        horizontalLayout_6->addWidget(label_15);

        led_Detection_Pressure = new QLabel(groupBox);
        led_Detection_Pressure->setObjectName(QString::fromUtf8("led_Detection_Pressure"));
        led_Detection_Pressure->setMinimumSize(QSize(300, 0));
        QFont font5;
        font5.setPointSize(36);
        led_Detection_Pressure->setFont(font5);
        led_Detection_Pressure->setFrameShape(QFrame::Panel);
        led_Detection_Pressure->setFrameShadow(QFrame::Raised);
        led_Detection_Pressure->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(led_Detection_Pressure);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(16777215, 16777215));
        label_18->setFont(font1);
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(true);

        horizontalLayout_9->addWidget(label_18);

        led_Leakage_value = new QLabel(groupBox);
        led_Leakage_value->setObjectName(QString::fromUtf8("led_Leakage_value"));
        led_Leakage_value->setMinimumSize(QSize(300, 0));
        led_Leakage_value->setFont(font5);
        led_Leakage_value->setFrameShape(QFrame::Panel);
        led_Leakage_value->setFrameShadow(QFrame::Raised);
        led_Leakage_value->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(led_Leakage_value);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 16777215));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(true);

        horizontalLayout_5->addWidget(label_13);

        led_JL_Result = new QLabel(groupBox);
        led_JL_Result->setObjectName(QString::fromUtf8("led_JL_Result"));
        led_JL_Result->setMinimumSize(QSize(300, 0));
        led_JL_Result->setFont(font5);
        led_JL_Result->setFrameShape(QFrame::Panel);
        led_JL_Result->setFrameShadow(QFrame::Raised);
        led_JL_Result->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(led_JL_Result);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 16777215));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);

        horizontalLayout_4->addWidget(label_10);

        led_DetectionTime = new QLabel(frame);
        led_DetectionTime->setObjectName(QString::fromUtf8("led_DetectionTime"));
        led_DetectionTime->setMinimumSize(QSize(160, 0));
        led_DetectionTime->setMaximumSize(QSize(16777215, 16777215));
        led_DetectionTime->setFont(font5);
        led_DetectionTime->setFrameShape(QFrame::Panel);
        led_DetectionTime->setFrameShadow(QFrame::Raised);
        led_DetectionTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(led_DetectionTime);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 16777215));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setWordWrap(true);

        horizontalLayout_4->addWidget(label_12);


        horizontalLayout_7->addLayout(horizontalLayout_4);

        BTN_Start = new QPushButton(frame);
        BTN_Start->setObjectName(QString::fromUtf8("BTN_Start"));
        sizePolicy.setHeightForWidth(BTN_Start->sizePolicy().hasHeightForWidth());
        BTN_Start->setSizePolicy(sizePolicy);
        BTN_Start->setMinimumSize(QSize(200, 100));
        BTN_Start->setMaximumSize(QSize(200, 100));
        QFont font6;
        font6.setPointSize(32);
        BTN_Start->setFont(font6);

        horizontalLayout_7->addWidget(BTN_Start);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        BTN_Reset = new QPushButton(frame);
        BTN_Reset->setObjectName(QString::fromUtf8("BTN_Reset"));
        sizePolicy.setHeightForWidth(BTN_Reset->sizePolicy().hasHeightForWidth());
        BTN_Reset->setSizePolicy(sizePolicy);
        BTN_Reset->setMinimumSize(QSize(200, 100));
        BTN_Reset->setMaximumSize(QSize(200, 100));
        BTN_Reset->setFont(font6);

        horizontalLayout_7->addWidget(BTN_Reset);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        LB_EMC_Stop = new QLabel(frame);
        LB_EMC_Stop->setObjectName(QString::fromUtf8("LB_EMC_Stop"));
        LB_EMC_Stop->setMaximumSize(QSize(16777215, 16777215));
        LB_EMC_Stop->setFont(font1);
        LB_EMC_Stop->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LB_EMC_Stop->setWordWrap(true);

        horizontalLayout_7->addWidget(LB_EMC_Stop);

        led_EMC_Stop = new QLabel(frame);
        led_EMC_Stop->setObjectName(QString::fromUtf8("led_EMC_Stop"));
        led_EMC_Stop->setMinimumSize(QSize(100, 60));
        led_EMC_Stop->setMaximumSize(QSize(16777215, 16777215));
        QFont font7;
        font7.setPointSize(24);
        led_EMC_Stop->setFont(font7);
        led_EMC_Stop->setFrameShape(QFrame::Panel);
        led_EMC_Stop->setFrameShadow(QFrame::Raised);
        led_EMC_Stop->setAlignment(Qt::AlignCenter);
        led_EMC_Stop->setWordWrap(true);

        horizontalLayout_7->addWidget(led_EMC_Stop);


        gridLayout_3->addLayout(horizontalLayout_7, 5, 0, 1, 2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 31));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setFont(font1);
        label_6->setWordWrap(true);

        horizontalLayout_13->addWidget(label_6);

        LE_ProductCode = new QLineEdit(frame);
        LE_ProductCode->setObjectName(QString::fromUtf8("LE_ProductCode"));
        LE_ProductCode->setEnabled(false);
        sizePolicy1.setHeightForWidth(LE_ProductCode->sizePolicy().hasHeightForWidth());
        LE_ProductCode->setSizePolicy(sizePolicy1);
        LE_ProductCode->setMinimumSize(QSize(0, 61));
        LE_ProductCode->setMaximumSize(QSize(16777215, 61));
        LE_ProductCode->setFont(font1);
        LE_ProductCode->setReadOnly(true);

        horizontalLayout_13->addWidget(LE_ProductCode);


        gridLayout_3->addLayout(horizontalLayout_13, 0, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 300));
        groupBox_2->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 16777215));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(true);

        horizontalLayout_10->addWidget(label_16);

        led_Detection_Pressure_2 = new QLabel(groupBox_2);
        led_Detection_Pressure_2->setObjectName(QString::fromUtf8("led_Detection_Pressure_2"));
        led_Detection_Pressure_2->setMinimumSize(QSize(300, 0));
        led_Detection_Pressure_2->setFont(font5);
        led_Detection_Pressure_2->setFrameShape(QFrame::Panel);
        led_Detection_Pressure_2->setFrameShadow(QFrame::Raised);
        led_Detection_Pressure_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(led_Detection_Pressure_2);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(16777215, 16777215));
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignCenter);
        label_19->setWordWrap(true);

        horizontalLayout_11->addWidget(label_19);

        led_Leakage_value_2 = new QLabel(groupBox_2);
        led_Leakage_value_2->setObjectName(QString::fromUtf8("led_Leakage_value_2"));
        led_Leakage_value_2->setMinimumSize(QSize(300, 0));
        led_Leakage_value_2->setFont(font5);
        led_Leakage_value_2->setFrameShape(QFrame::Panel);
        led_Leakage_value_2->setFrameShadow(QFrame::Raised);
        led_Leakage_value_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(led_Leakage_value_2);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 16777215));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(true);

        horizontalLayout_12->addWidget(label_14);

        led_JL_Result_2 = new QLabel(groupBox_2);
        led_JL_Result_2->setObjectName(QString::fromUtf8("led_JL_Result_2"));
        led_JL_Result_2->setMinimumSize(QSize(300, 0));
        led_JL_Result_2->setFont(font5);
        led_JL_Result_2->setFrameShape(QFrame::Panel);
        led_JL_Result_2->setFrameShadow(QFrame::Raised);
        led_JL_Result_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(led_JL_Result_2);


        verticalLayout_4->addLayout(horizontalLayout_12);


        gridLayout_5->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 3, 1, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 31));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font1);
        label_7->setWordWrap(true);

        horizontalLayout_14->addWidget(label_7);

        LE_ProductCode_Print = new QLineEdit(frame);
        LE_ProductCode_Print->setObjectName(QString::fromUtf8("LE_ProductCode_Print"));
        LE_ProductCode_Print->setEnabled(false);
        sizePolicy1.setHeightForWidth(LE_ProductCode_Print->sizePolicy().hasHeightForWidth());
        LE_ProductCode_Print->setSizePolicy(sizePolicy1);
        LE_ProductCode_Print->setMinimumSize(QSize(0, 61));
        LE_ProductCode_Print->setMaximumSize(QSize(16777215, 61));
        LE_ProductCode_Print->setFont(font1);
        LE_ProductCode_Print->setReadOnly(true);

        horizontalLayout_14->addWidget(LE_ProductCode_Print);


        gridLayout_3->addLayout(horizontalLayout_14, 2, 0, 1, 2);


        gridLayout->addWidget(frame, 2, 1, 3, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(600, 16777215));
        label->setFont(font1);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 60));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        logo = new QLabel(frame_2);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMaximumSize(QSize(120, 60));
        logo->setFont(font);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo/logo.png")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(logo);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        BTN_ATEQ = new QPushButton(frame_2);
        BTN_ATEQ->setObjectName(QString::fromUtf8("BTN_ATEQ"));
        BTN_ATEQ->setFont(font);

        gridLayout_2->addWidget(BTN_ATEQ, 0, 0, 1, 1);

        BTN_IO = new QPushButton(frame_2);
        BTN_IO->setObjectName(QString::fromUtf8("BTN_IO"));
        BTN_IO->setFont(font);

        gridLayout_2->addWidget(BTN_IO, 0, 1, 1, 1);

        BTN_ScanCode = new QPushButton(frame_2);
        BTN_ScanCode->setObjectName(QString::fromUtf8("BTN_ScanCode"));
        BTN_ScanCode->setFont(font);

        gridLayout_2->addWidget(BTN_ScanCode, 0, 2, 1, 1);

        BTN_MFormLabel = new QPushButton(frame_2);
        BTN_MFormLabel->setObjectName(QString::fromUtf8("BTN_MFormLabel"));
        BTN_MFormLabel->setFont(font);

        gridLayout_2->addWidget(BTN_MFormLabel, 0, 3, 1, 1);

        BTN_MFormMYSQL = new QPushButton(frame_2);
        BTN_MFormMYSQL->setObjectName(QString::fromUtf8("BTN_MFormMYSQL"));
        BTN_MFormMYSQL->setFont(font);

        gridLayout_2->addWidget(BTN_MFormMYSQL, 0, 4, 1, 1);

        LD_admin = new QLabel(frame_2);
        LD_admin->setObjectName(QString::fromUtf8("LD_admin"));
        sizePolicy.setHeightForWidth(LD_admin->sizePolicy().hasHeightForWidth());
        LD_admin->setSizePolicy(sizePolicy);
        LD_admin->setMinimumSize(QSize(100, 0));
        LD_admin->setMaximumSize(QSize(16777215, 16777215));
        LD_admin->setFont(font);
        LD_admin->setFrameShape(QFrame::Panel);
        LD_admin->setFrameShadow(QFrame::Raised);
        LD_admin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(LD_admin, 1, 1, 1, 1);

        BTN_Login = new QPushButton(frame_2);
        BTN_Login->setObjectName(QString::fromUtf8("BTN_Login"));
        BTN_Login->setFont(font);

        gridLayout_2->addWidget(BTN_Login, 1, 0, 1, 1);

        BTN_Logout = new QPushButton(frame_2);
        BTN_Logout->setObjectName(QString::fromUtf8("BTN_Logout"));
        BTN_Logout->setFont(font);

        gridLayout_2->addWidget(BTN_Logout, 1, 2, 1, 1);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(80, 16777215));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 1, 3, 1, 1);

        CBT_Language = new QComboBox(frame_2);
        CBT_Language->addItem(QString());
        CBT_Language->addItem(QString());
        CBT_Language->setObjectName(QString::fromUtf8("CBT_Language"));
        sizePolicy.setHeightForWidth(CBT_Language->sizePolicy().hasHeightForWidth());
        CBT_Language->setSizePolicy(sizePolicy);
        CBT_Language->setFont(font);

        gridLayout_2->addWidget(CBT_Language, 1, 4, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777215, 16777215));
        label_9->setFont(font7);

        horizontalLayout_3->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addWidget(frame_2, 0, 0, 1, 2);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 0));
        textBrowser->setMaximumSize(QSize(600, 16777215));

        gridLayout->addWidget(textBrowser, 4, 0, 1, 1);

        MFormJLStation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MFormJLStation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 23));
        MFormJLStation->setMenuBar(menubar);

        retranslateUi(MFormJLStation);

        QMetaObject::connectSlotsByName(MFormJLStation);
    } // setupUi

    void retranslateUi(QMainWindow *MFormJLStation)
    {
        MFormJLStation->setWindowTitle(QString());
        LB_productnumber->setText(QCoreApplication::translate("MFormJLStation", "\344\272\247\345\223\201\347\274\226\345\217\267", nullptr));
        LB_equnumber->setText(QCoreApplication::translate("MFormJLStation", "\350\256\276\345\244\207\347\274\226\345\217\267", nullptr));
        LB_channel->setText(QCoreApplication::translate("MFormJLStation", "\345\223\201\347\225\252", nullptr));
        CBT_Channel->setItemText(0, QString());
        CBT_Channel->setItemText(1, QCoreApplication::translate("MFormJLStation", "1", nullptr));
        CBT_Channel->setItemText(2, QCoreApplication::translate("MFormJLStation", "2", nullptr));
        CBT_Channel->setItemText(3, QCoreApplication::translate("MFormJLStation", "3", nullptr));
        CBT_Channel->setItemText(4, QCoreApplication::translate("MFormJLStation", "4", nullptr));
        CBT_Channel->setItemText(5, QCoreApplication::translate("MFormJLStation", "5", nullptr));
        CBT_Channel->setItemText(6, QCoreApplication::translate("MFormJLStation", "6", nullptr));
        CBT_Channel->setItemText(7, QCoreApplication::translate("MFormJLStation", "7", nullptr));
        CBT_Channel->setItemText(8, QCoreApplication::translate("MFormJLStation", "8", nullptr));
        CBT_Channel->setItemText(9, QCoreApplication::translate("MFormJLStation", "9", nullptr));
        CBT_Channel->setItemText(10, QCoreApplication::translate("MFormJLStation", "10", nullptr));
        CBT_Channel->setItemText(11, QCoreApplication::translate("MFormJLStation", "11", nullptr));
        CBT_Channel->setItemText(12, QCoreApplication::translate("MFormJLStation", "12", nullptr));
        CBT_Channel->setItemText(13, QCoreApplication::translate("MFormJLStation", "13", nullptr));
        CBT_Channel->setItemText(14, QCoreApplication::translate("MFormJLStation", "14", nullptr));
        CBT_Channel->setItemText(15, QCoreApplication::translate("MFormJLStation", "15", nullptr));
        CBT_Channel->setItemText(16, QCoreApplication::translate("MFormJLStation", "16", nullptr));
        CBT_Channel->setItemText(17, QCoreApplication::translate("MFormJLStation", "17", nullptr));
        CBT_Channel->setItemText(18, QCoreApplication::translate("MFormJLStation", "18", nullptr));
        CBT_Channel->setItemText(19, QCoreApplication::translate("MFormJLStation", "19", nullptr));
        CBT_Channel->setItemText(20, QCoreApplication::translate("MFormJLStation", "20", nullptr));
        CBT_Channel->setItemText(21, QCoreApplication::translate("MFormJLStation", "21", nullptr));
        CBT_Channel->setItemText(22, QCoreApplication::translate("MFormJLStation", "22", nullptr));
        CBT_Channel->setItemText(23, QCoreApplication::translate("MFormJLStation", "23", nullptr));
        CBT_Channel->setItemText(24, QCoreApplication::translate("MFormJLStation", "24", nullptr));
        CBT_Channel->setItemText(25, QCoreApplication::translate("MFormJLStation", "25", nullptr));
        CBT_Channel->setItemText(26, QCoreApplication::translate("MFormJLStation", "26", nullptr));
        CBT_Channel->setItemText(27, QCoreApplication::translate("MFormJLStation", "27", nullptr));
        CBT_Channel->setItemText(28, QCoreApplication::translate("MFormJLStation", "28", nullptr));
        CBT_Channel->setItemText(29, QCoreApplication::translate("MFormJLStation", "29", nullptr));
        CBT_Channel->setItemText(30, QCoreApplication::translate("MFormJLStation", "30", nullptr));
        CBT_Channel->setItemText(31, QCoreApplication::translate("MFormJLStation", "31", nullptr));
        CBT_Channel->setItemText(32, QCoreApplication::translate("MFormJLStation", "32", nullptr));

        LB_batch_number->setText(QCoreApplication::translate("MFormJLStation", "\346\211\271\346\254\241\345\217\267", nullptr));
        LB_operator->setText(QCoreApplication::translate("MFormJLStation", "\346\223\215\344\275\234\345\221\230", nullptr));
        BTN_Save->setText(QCoreApplication::translate("MFormJLStation", "\344\277\235\345\255\230", nullptr));
        BTN_Get_Object->setText(QString());
        led_485->setText(QString());
        label_21->setText(QCoreApplication::translate("MFormJLStation", "\351\230\262\350\257\257\347\256\261", nullptr));
        led_sql->setText(QString());
        label_24->setText(QCoreApplication::translate("MFormJLStation", "\346\225\260\346\215\256\345\272\223", nullptr));
        BTN_NeedPlaceNGProduct->setText(QCoreApplication::translate("MFormJLStation", "\351\234\200\346\224\276\347\275\256NG\344\272\247\345\223\201", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MFormJLStation", "\346\255\245\351\252\244", nullptr));
        led_GetCodeOK->setText(QCoreApplication::translate("MFormJLStation", "\346\211\253\347\240\201\345\256\214\346\210\220", nullptr));
        led_LockProduct->setText(QCoreApplication::translate("MFormJLStation", "\345\216\213\347\264\247\344\272\247\345\223\201", nullptr));
        led_Result->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        led_Exhaust->setText(QCoreApplication::translate("MFormJLStation", "\346\216\222\346\260\224\347\273\223\346\235\237", nullptr));
        led_Loosen->setText(QCoreApplication::translate("MFormJLStation", "\351\207\212\346\224\276\344\272\247\345\223\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MFormJLStation", "\351\241\271\347\233\2561", nullptr));
        label_15->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\345\216\213\345\212\233", nullptr));
        led_Detection_Pressure->setText(QCoreApplication::translate("MFormJLStation", "0", nullptr));
        label_18->setText(QCoreApplication::translate("MFormJLStation", "\346\263\204\351\234\262\345\200\274", nullptr));
        led_Leakage_value->setText(QCoreApplication::translate("MFormJLStation", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        led_JL_Result->setText(QCoreApplication::translate("MFormJLStation", "#", nullptr));
        label_10->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\346\227\266\351\227\264", nullptr));
        led_DetectionTime->setText(QCoreApplication::translate("MFormJLStation", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MFormJLStation", "s", nullptr));
        BTN_Start->setText(QCoreApplication::translate("MFormJLStation", "\345\274\200\345\247\213", nullptr));
        BTN_Reset->setText(QCoreApplication::translate("MFormJLStation", "\345\244\215\344\275\215", nullptr));
        LB_EMC_Stop->setText(QCoreApplication::translate("MFormJLStation", "\346\200\245\345\201\234", nullptr));
        led_EMC_Stop->setText(QString());
        label_6->setText(QCoreApplication::translate("MFormJLStation", "\344\272\247\345\223\201\346\235\241\347\240\201:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MFormJLStation", "\351\241\271\347\233\2562", nullptr));
        label_16->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\345\216\213\345\212\233", nullptr));
        led_Detection_Pressure_2->setText(QCoreApplication::translate("MFormJLStation", "0", nullptr));
        label_19->setText(QCoreApplication::translate("MFormJLStation", "\346\263\204\351\234\262\345\200\274", nullptr));
        led_Leakage_value_2->setText(QCoreApplication::translate("MFormJLStation", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        led_JL_Result_2->setText(QCoreApplication::translate("MFormJLStation", "#", nullptr));
        label_7->setText(QCoreApplication::translate("MFormJLStation", "\346\211\223\345\215\260\346\235\241\347\240\201:", nullptr));
        label->setText(QCoreApplication::translate("MFormJLStation", "\350\260\203\350\257\225\344\277\241\346\201\257", nullptr));
        logo->setText(QString());
        BTN_ATEQ->setText(QCoreApplication::translate("MFormJLStation", "ATEQ", nullptr));
        BTN_IO->setText(QCoreApplication::translate("MFormJLStation", "\347\233\221\350\247\206", nullptr));
        BTN_ScanCode->setText(QCoreApplication::translate("MFormJLStation", "\346\211\253\347\240\201\346\236\252", nullptr));
        BTN_MFormLabel->setText(QCoreApplication::translate("MFormJLStation", "\345\223\201\347\225\252", nullptr));
        BTN_MFormMYSQL->setText(QCoreApplication::translate("MFormJLStation", "MYSQL", nullptr));
        LD_admin->setText(QString());
        BTN_Login->setText(QCoreApplication::translate("MFormJLStation", "\347\231\273\345\275\225", nullptr));
        BTN_Logout->setText(QCoreApplication::translate("MFormJLStation", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label_17->setText(QCoreApplication::translate("MFormJLStation", "\350\257\255\350\250\200:", nullptr));
        CBT_Language->setItemText(0, QCoreApplication::translate("MFormJLStation", "\344\270\255\346\226\207", nullptr));
        CBT_Language->setItemText(1, QCoreApplication::translate("MFormJLStation", "English", nullptr));

        label_9->setText(QCoreApplication::translate("MFormJLStation", "\346\243\200\346\274\217\345\267\245\344\275\234\347\253\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MFormJLStation: public Ui_MFormJLStation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORMJLSTATION_H

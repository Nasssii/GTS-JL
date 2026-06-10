/********************************************************************************
** Form generated from reading UI file 'MForm_PrintSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORM_PRINTSETTING_H
#define UI_MFORM_PRINTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MForm_PrintSetting
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label;
    QComboBox *cbt_print_drive_ng;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *CBT_Channel;
    QSpacerItem *horizontalSpacer;
    QPushButton *BTN_Save;
    QComboBox *cbt_print_drive;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *LE_TitleNumber;
    QComboBox *CBX_Mode;
    QFrame *line_3;
    QComboBox *CBX_Location;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *frame_2;
    QLineEdit *LE_TitleName;
    QSpinBox *sbox_days;
    QFrame *line_2;
    QFrame *line_6;
    QLineEdit *LE_Leak_value;
    QLineEdit *LE_Number;
    QSpinBox *sbox_year;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *SPB_PrinteCount;
    QPushButton *BTN_autoPrint;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *LE_HandNumber;
    QPushButton *BTN_HandPrinte;
    QLineEdit *LE_Date;

    void setupUi(QDialog *MForm_PrintSetting)
    {
        if (MForm_PrintSetting->objectName().isEmpty())
            MForm_PrintSetting->setObjectName(QString::fromUtf8("MForm_PrintSetting"));
        MForm_PrintSetting->resize(800, 345);
        MForm_PrintSetting->setMaximumSize(QSize(800, 350));
        gridLayout_2 = new QGridLayout(MForm_PrintSetting);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(MForm_PrintSetting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label = new QLabel(MForm_PrintSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        cbt_print_drive_ng = new QComboBox(MForm_PrintSetting);
        cbt_print_drive_ng->setObjectName(QString::fromUtf8("cbt_print_drive_ng"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbt_print_drive_ng->sizePolicy().hasHeightForWidth());
        cbt_print_drive_ng->setSizePolicy(sizePolicy);
        cbt_print_drive_ng->setMinimumSize(QSize(0, 31));
        cbt_print_drive_ng->setMaximumSize(QSize(16777215, 31));
        QFont font1;
        font1.setPointSize(12);
        cbt_print_drive_ng->setFont(font1);
        cbt_print_drive_ng->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(cbt_print_drive_ng, 3, 0, 1, 1);

        line = new QFrame(MForm_PrintSetting);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::VLine);

        gridLayout_2->addWidget(line, 0, 1, 9, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(MForm_PrintSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        CBT_Channel = new QComboBox(MForm_PrintSetting);
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CBT_Channel->sizePolicy().hasHeightForWidth());
        CBT_Channel->setSizePolicy(sizePolicy1);
        CBT_Channel->setMinimumSize(QSize(100, 0));
        CBT_Channel->setMaximumSize(QSize(100, 30));
        CBT_Channel->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setPointSize(16);
        CBT_Channel->setFont(font2);

        horizontalLayout->addWidget(CBT_Channel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BTN_Save = new QPushButton(MForm_PrintSetting);
        BTN_Save->setObjectName(QString::fromUtf8("BTN_Save"));
        sizePolicy1.setHeightForWidth(BTN_Save->sizePolicy().hasHeightForWidth());
        BTN_Save->setSizePolicy(sizePolicy1);
        BTN_Save->setMinimumSize(QSize(60, 31));
        BTN_Save->setMaximumSize(QSize(16777215, 31));
        BTN_Save->setFont(font1);

        horizontalLayout->addWidget(BTN_Save);


        gridLayout_2->addLayout(horizontalLayout, 0, 2, 2, 1);

        cbt_print_drive = new QComboBox(MForm_PrintSetting);
        cbt_print_drive->setObjectName(QString::fromUtf8("cbt_print_drive"));
        sizePolicy.setHeightForWidth(cbt_print_drive->sizePolicy().hasHeightForWidth());
        cbt_print_drive->setSizePolicy(sizePolicy);
        cbt_print_drive->setMinimumSize(QSize(0, 31));
        cbt_print_drive->setMaximumSize(QSize(16777215, 31));
        cbt_print_drive->setFont(font1);
        cbt_print_drive->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        gridLayout_2->addWidget(cbt_print_drive, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 0, 1, 1);

        frame = new QFrame(MForm_PrintSetting);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LE_TitleNumber = new QLineEdit(frame);
        LE_TitleNumber->setObjectName(QString::fromUtf8("LE_TitleNumber"));
        sizePolicy1.setHeightForWidth(LE_TitleNumber->sizePolicy().hasHeightForWidth());
        LE_TitleNumber->setSizePolicy(sizePolicy1);
        LE_TitleNumber->setMinimumSize(QSize(0, 31));
        LE_TitleNumber->setMaximumSize(QSize(16777215, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        LE_TitleNumber->setFont(font3);
        LE_TitleNumber->setMaxLength(50);
        LE_TitleNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_TitleNumber, 0, 0, 1, 4);

        CBX_Mode = new QComboBox(frame);
        CBX_Mode->addItem(QString());
        CBX_Mode->addItem(QString());
        CBX_Mode->setObjectName(QString::fromUtf8("CBX_Mode"));
        CBX_Mode->setMinimumSize(QSize(120, 0));
        CBX_Mode->setMaximumSize(QSize(120, 16777215));
        CBX_Mode->setFont(font3);

        gridLayout->addWidget(CBX_Mode, 4, 3, 1, 1);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(5);
        line_3->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(line_3, 6, 2, 3, 1);

        CBX_Location = new QComboBox(frame);
        CBX_Location->addItem(QString());
        CBX_Location->addItem(QString());
        CBX_Location->setObjectName(QString::fromUtf8("CBX_Location"));
        CBX_Location->setMinimumSize(QSize(180, 0));
        CBX_Location->setMaximumSize(QSize(180, 16777215));
        CBX_Location->setFont(font3);

        gridLayout->addWidget(CBX_Location, 4, 0, 1, 3);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(5);
        line_4->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_4, 3, 0, 1, 4);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(5);
        line_5->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_5, 7, 0, 1, 2);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(100, 80));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);

        gridLayout->addWidget(frame_2, 7, 3, 2, 1);

        LE_TitleName = new QLineEdit(frame);
        LE_TitleName->setObjectName(QString::fromUtf8("LE_TitleName"));
        sizePolicy1.setHeightForWidth(LE_TitleName->sizePolicy().hasHeightForWidth());
        LE_TitleName->setSizePolicy(sizePolicy1);
        LE_TitleName->setMinimumSize(QSize(0, 31));
        LE_TitleName->setMaximumSize(QSize(16777215, 31));
        LE_TitleName->setFont(font3);
        LE_TitleName->setMaxLength(50);
        LE_TitleName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_TitleName, 2, 0, 1, 4);

        sbox_days = new QSpinBox(frame);
        sbox_days->setObjectName(QString::fromUtf8("sbox_days"));
        sbox_days->setFont(font3);
        sbox_days->setMinimum(1);
        sbox_days->setMaximum(365);
        sbox_days->setValue(1);

        gridLayout->addWidget(sbox_days, 6, 1, 1, 1);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_2, 1, 0, 1, 4);

        line_6 = new QFrame(frame);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(5);
        line_6->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_6, 5, 0, 1, 4);

        LE_Leak_value = new QLineEdit(frame);
        LE_Leak_value->setObjectName(QString::fromUtf8("LE_Leak_value"));
        sizePolicy1.setHeightForWidth(LE_Leak_value->sizePolicy().hasHeightForWidth());
        LE_Leak_value->setSizePolicy(sizePolicy1);
        LE_Leak_value->setMinimumSize(QSize(0, 31));
        LE_Leak_value->setMaximumSize(QSize(16777215, 31));
        LE_Leak_value->setFont(font3);
        LE_Leak_value->setMaxLength(50);
        LE_Leak_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_Leak_value, 6, 3, 1, 1);

        LE_Number = new QLineEdit(frame);
        LE_Number->setObjectName(QString::fromUtf8("LE_Number"));
        sizePolicy1.setHeightForWidth(LE_Number->sizePolicy().hasHeightForWidth());
        LE_Number->setSizePolicy(sizePolicy1);
        LE_Number->setMinimumSize(QSize(0, 31));
        LE_Number->setMaximumSize(QSize(16777215, 31));
        LE_Number->setFont(font3);
        LE_Number->setMaxLength(6);
        LE_Number->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_Number, 8, 0, 1, 2);

        sbox_year = new QSpinBox(frame);
        sbox_year->setObjectName(QString::fromUtf8("sbox_year"));
        sbox_year->setFont(font3);
        sbox_year->setMinimum(25);

        gridLayout->addWidget(sbox_year, 6, 0, 1, 1);


        gridLayout_2->addWidget(frame, 2, 2, 7, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(MForm_PrintSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setWordWrap(true);

        horizontalLayout_2->addWidget(label_4);

        SPB_PrinteCount = new QSpinBox(MForm_PrintSetting);
        SPB_PrinteCount->setObjectName(QString::fromUtf8("SPB_PrinteCount"));
        sizePolicy1.setHeightForWidth(SPB_PrinteCount->sizePolicy().hasHeightForWidth());
        SPB_PrinteCount->setSizePolicy(sizePolicy1);
        SPB_PrinteCount->setMinimumSize(QSize(60, 31));
        SPB_PrinteCount->setMaximumSize(QSize(60, 31));
        SPB_PrinteCount->setFont(font2);
        SPB_PrinteCount->setAlignment(Qt::AlignCenter);
        SPB_PrinteCount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        SPB_PrinteCount->setMinimum(1);
        SPB_PrinteCount->setMaximum(20);

        horizontalLayout_2->addWidget(SPB_PrinteCount);

        BTN_autoPrint = new QPushButton(MForm_PrintSetting);
        BTN_autoPrint->setObjectName(QString::fromUtf8("BTN_autoPrint"));
        sizePolicy1.setHeightForWidth(BTN_autoPrint->sizePolicy().hasHeightForWidth());
        BTN_autoPrint->setSizePolicy(sizePolicy1);
        BTN_autoPrint->setMinimumSize(QSize(100, 31));
        BTN_autoPrint->setMaximumSize(QSize(100, 31));
        BTN_autoPrint->setFont(font1);

        horizontalLayout_2->addWidget(BTN_autoPrint);


        gridLayout_2->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(MForm_PrintSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        LE_HandNumber = new QLineEdit(MForm_PrintSetting);
        LE_HandNumber->setObjectName(QString::fromUtf8("LE_HandNumber"));
        sizePolicy1.setHeightForWidth(LE_HandNumber->sizePolicy().hasHeightForWidth());
        LE_HandNumber->setSizePolicy(sizePolicy1);
        LE_HandNumber->setMinimumSize(QSize(0, 31));
        LE_HandNumber->setMaximumSize(QSize(100, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(16);
        LE_HandNumber->setFont(font4);
        LE_HandNumber->setMaxLength(6);
        LE_HandNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LE_HandNumber);

        BTN_HandPrinte = new QPushButton(MForm_PrintSetting);
        BTN_HandPrinte->setObjectName(QString::fromUtf8("BTN_HandPrinte"));
        sizePolicy1.setHeightForWidth(BTN_HandPrinte->sizePolicy().hasHeightForWidth());
        BTN_HandPrinte->setSizePolicy(sizePolicy1);
        BTN_HandPrinte->setMinimumSize(QSize(100, 31));
        BTN_HandPrinte->setMaximumSize(QSize(100, 31));
        BTN_HandPrinte->setFont(font1);

        horizontalLayout_3->addWidget(BTN_HandPrinte);


        gridLayout_2->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        LE_Date = new QLineEdit(MForm_PrintSetting);
        LE_Date->setObjectName(QString::fromUtf8("LE_Date"));
        sizePolicy1.setHeightForWidth(LE_Date->sizePolicy().hasHeightForWidth());
        LE_Date->setSizePolicy(sizePolicy1);
        LE_Date->setMinimumSize(QSize(0, 31));
        LE_Date->setMaximumSize(QSize(16777215, 31));
        LE_Date->setFont(font3);
        LE_Date->setMaxLength(50);
        LE_Date->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LE_Date, 7, 0, 1, 1);


        retranslateUi(MForm_PrintSetting);

        QMetaObject::connectSlotsByName(MForm_PrintSetting);
    } // setupUi

    void retranslateUi(QDialog *MForm_PrintSetting)
    {
        MForm_PrintSetting->setWindowTitle(QString());
        label_5->setText(QCoreApplication::translate("MForm_PrintSetting", "\346\240\207\347\255\276\346\211\223\345\215\260\346\234\272(\344\270\215\345\220\210\346\240\274)", nullptr));
        label->setText(QCoreApplication::translate("MForm_PrintSetting", "\346\240\207\347\255\276\346\211\223\345\215\260\346\234\272(\345\220\210\346\240\274)", nullptr));
        label_2->setText(QCoreApplication::translate("MForm_PrintSetting", "\351\242\221\351\201\223\345\217\267:", nullptr));
        CBT_Channel->setItemText(0, QString());
        CBT_Channel->setItemText(1, QCoreApplication::translate("MForm_PrintSetting", "1", nullptr));
        CBT_Channel->setItemText(2, QCoreApplication::translate("MForm_PrintSetting", "2", nullptr));
        CBT_Channel->setItemText(3, QCoreApplication::translate("MForm_PrintSetting", "3", nullptr));
        CBT_Channel->setItemText(4, QCoreApplication::translate("MForm_PrintSetting", "4", nullptr));
        CBT_Channel->setItemText(5, QCoreApplication::translate("MForm_PrintSetting", "5", nullptr));
        CBT_Channel->setItemText(6, QCoreApplication::translate("MForm_PrintSetting", "6", nullptr));
        CBT_Channel->setItemText(7, QCoreApplication::translate("MForm_PrintSetting", "7", nullptr));
        CBT_Channel->setItemText(8, QCoreApplication::translate("MForm_PrintSetting", "8", nullptr));
        CBT_Channel->setItemText(9, QCoreApplication::translate("MForm_PrintSetting", "9", nullptr));
        CBT_Channel->setItemText(10, QCoreApplication::translate("MForm_PrintSetting", "10", nullptr));
        CBT_Channel->setItemText(11, QCoreApplication::translate("MForm_PrintSetting", "11", nullptr));
        CBT_Channel->setItemText(12, QCoreApplication::translate("MForm_PrintSetting", "12", nullptr));
        CBT_Channel->setItemText(13, QCoreApplication::translate("MForm_PrintSetting", "13", nullptr));
        CBT_Channel->setItemText(14, QCoreApplication::translate("MForm_PrintSetting", "14", nullptr));
        CBT_Channel->setItemText(15, QCoreApplication::translate("MForm_PrintSetting", "15", nullptr));
        CBT_Channel->setItemText(16, QCoreApplication::translate("MForm_PrintSetting", "16", nullptr));
        CBT_Channel->setItemText(17, QCoreApplication::translate("MForm_PrintSetting", "17", nullptr));
        CBT_Channel->setItemText(18, QCoreApplication::translate("MForm_PrintSetting", "18", nullptr));
        CBT_Channel->setItemText(19, QCoreApplication::translate("MForm_PrintSetting", "19", nullptr));
        CBT_Channel->setItemText(20, QCoreApplication::translate("MForm_PrintSetting", "20", nullptr));
        CBT_Channel->setItemText(21, QCoreApplication::translate("MForm_PrintSetting", "21", nullptr));
        CBT_Channel->setItemText(22, QCoreApplication::translate("MForm_PrintSetting", "22", nullptr));
        CBT_Channel->setItemText(23, QCoreApplication::translate("MForm_PrintSetting", "23", nullptr));
        CBT_Channel->setItemText(24, QCoreApplication::translate("MForm_PrintSetting", "24", nullptr));
        CBT_Channel->setItemText(25, QCoreApplication::translate("MForm_PrintSetting", "25", nullptr));
        CBT_Channel->setItemText(26, QCoreApplication::translate("MForm_PrintSetting", "26", nullptr));
        CBT_Channel->setItemText(27, QCoreApplication::translate("MForm_PrintSetting", "27", nullptr));
        CBT_Channel->setItemText(28, QCoreApplication::translate("MForm_PrintSetting", "28", nullptr));
        CBT_Channel->setItemText(29, QCoreApplication::translate("MForm_PrintSetting", "29", nullptr));
        CBT_Channel->setItemText(30, QCoreApplication::translate("MForm_PrintSetting", "30", nullptr));
        CBT_Channel->setItemText(31, QCoreApplication::translate("MForm_PrintSetting", "31", nullptr));
        CBT_Channel->setItemText(32, QCoreApplication::translate("MForm_PrintSetting", "32", nullptr));

        BTN_Save->setText(QCoreApplication::translate("MForm_PrintSetting", "\344\277\235\345\255\230", nullptr));
        LE_TitleNumber->setPlaceholderText(QString());
        CBX_Mode->setItemText(0, QCoreApplication::translate("MForm_PrintSetting", "COOLER", nullptr));
        CBX_Mode->setItemText(1, QCoreApplication::translate("MForm_PrintSetting", "HEATER", nullptr));

        CBX_Location->setItemText(0, QCoreApplication::translate("MForm_PrintSetting", "MADE IN CHINA", nullptr));
        CBX_Location->setItemText(1, QCoreApplication::translate("MForm_PrintSetting", "MADE IN Mexico", nullptr));

        LE_TitleName->setPlaceholderText(QString());
        LE_Leak_value->setText(QString());
        LE_Leak_value->setPlaceholderText(QString());
        LE_Number->setText(QString());
        LE_Number->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("MForm_PrintSetting", "\345\272\217\345\217\267\351\200\222\345\242\236\346\254\241\346\225\260:", nullptr));
        BTN_autoPrint->setText(QCoreApplication::translate("MForm_PrintSetting", "\350\207\252\345\212\250\346\211\223\345\215\260", nullptr));
        label_3->setText(QCoreApplication::translate("MForm_PrintSetting", "\345\272\217\345\210\227\345\217\267:", nullptr));
        BTN_HandPrinte->setText(QCoreApplication::translate("MForm_PrintSetting", "\346\211\213\345\212\250\346\211\223\345\215\260", nullptr));
        LE_Date->setText(QString());
        LE_Date->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class MForm_PrintSetting: public Ui_MForm_PrintSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORM_PRINTSETTING_H

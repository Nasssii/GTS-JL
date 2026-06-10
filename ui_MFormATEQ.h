/********************************************************************************
** Form generated from reading UI file 'MFormATEQ.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORMATEQ_H
#define UI_MFORMATEQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MFormATEQ
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_ATEQ;
    QGridLayout *gridLayout_9;
    QLabel *led_JL_Com_1;
    QLabel *led_ATEQ_Channel_1;
    QLabel *led_ATEQ_Res_1;
    QLabel *label_35;
    QFrame *frame_ATEQ_2;
    QGridLayout *gridLayout_6;
    QLabel *led_JL_Com_2;
    QLabel *label_36;
    QLabel *led_ATEQ_Channel_2;
    QLabel *led_ATEQ_Res_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *label_22;
    QComboBox *CBB_COM_JL_1;
    QPushButton *Btn_Updata_Com_2;
    QLabel *label_24;
    QComboBox *CBB_Buad_JL_1;
    QPushButton *Btn_JL_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_25;
    QComboBox *CBB_COM_JL_2;
    QPushButton *Btn_Updata_Com_3;
    QLabel *label_26;
    QComboBox *CBB_Buad_JL_2;
    QPushButton *Btn_JL_2;
    QPushButton *BTN_Save;

    void setupUi(QDialog *MFormATEQ)
    {
        if (MFormATEQ->objectName().isEmpty())
            MFormATEQ->setObjectName(QString::fromUtf8("MFormATEQ"));
        MFormATEQ->resize(617, 359);
        gridLayout = new QGridLayout(MFormATEQ);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_ATEQ = new QFrame(MFormATEQ);
        frame_ATEQ->setObjectName(QString::fromUtf8("frame_ATEQ"));
        frame_ATEQ->setMinimumSize(QSize(0, 61));
        frame_ATEQ->setMaximumSize(QSize(16777215, 16777215));
        frame_ATEQ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_ATEQ->setFrameShape(QFrame::Box);
        frame_ATEQ->setFrameShadow(QFrame::Plain);
        gridLayout_9 = new QGridLayout(frame_ATEQ);
        gridLayout_9->setSpacing(2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(2, 2, 2, 2);
        led_JL_Com_1 = new QLabel(frame_ATEQ);
        led_JL_Com_1->setObjectName(QString::fromUtf8("led_JL_Com_1"));
        led_JL_Com_1->setMinimumSize(QSize(21, 0));
        led_JL_Com_1->setMaximumSize(QSize(31, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        led_JL_Com_1->setFont(font);
        led_JL_Com_1->setFrameShape(QFrame::Box);
        led_JL_Com_1->setTextFormat(Qt::AutoText);
        led_JL_Com_1->setScaledContents(false);
        led_JL_Com_1->setAlignment(Qt::AlignCenter);
        led_JL_Com_1->setWordWrap(false);

        gridLayout_9->addWidget(led_JL_Com_1, 0, 2, 1, 1);

        led_ATEQ_Channel_1 = new QLabel(frame_ATEQ);
        led_ATEQ_Channel_1->setObjectName(QString::fromUtf8("led_ATEQ_Channel_1"));
        led_ATEQ_Channel_1->setMinimumSize(QSize(21, 0));
        led_ATEQ_Channel_1->setMaximumSize(QSize(31, 21));
        led_ATEQ_Channel_1->setFont(font);
        led_ATEQ_Channel_1->setFrameShape(QFrame::Box);
        led_ATEQ_Channel_1->setTextFormat(Qt::AutoText);
        led_ATEQ_Channel_1->setScaledContents(false);
        led_ATEQ_Channel_1->setAlignment(Qt::AlignCenter);
        led_ATEQ_Channel_1->setWordWrap(false);

        gridLayout_9->addWidget(led_ATEQ_Channel_1, 0, 0, 1, 1);

        led_ATEQ_Res_1 = new QLabel(frame_ATEQ);
        led_ATEQ_Res_1->setObjectName(QString::fromUtf8("led_ATEQ_Res_1"));
        led_ATEQ_Res_1->setMinimumSize(QSize(0, 25));
        led_ATEQ_Res_1->setMaximumSize(QSize(16777215, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        led_ATEQ_Res_1->setFont(font1);
        led_ATEQ_Res_1->setFrameShape(QFrame::Panel);
        led_ATEQ_Res_1->setFrameShadow(QFrame::Sunken);
        led_ATEQ_Res_1->setTextFormat(Qt::AutoText);
        led_ATEQ_Res_1->setAlignment(Qt::AlignCenter);
        led_ATEQ_Res_1->setWordWrap(true);

        gridLayout_9->addWidget(led_ATEQ_Res_1, 1, 0, 1, 3);

        label_35 = new QLabel(frame_ATEQ);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(0, 0));
        label_35->setMaximumSize(QSize(16777215, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_35->setFont(font2);
        label_35->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_35->setFrameShape(QFrame::NoFrame);
        label_35->setTextFormat(Qt::AutoText);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_35->setWordWrap(false);

        gridLayout_9->addWidget(label_35, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(frame_ATEQ);

        frame_ATEQ_2 = new QFrame(MFormATEQ);
        frame_ATEQ_2->setObjectName(QString::fromUtf8("frame_ATEQ_2"));
        frame_ATEQ_2->setMinimumSize(QSize(0, 61));
        frame_ATEQ_2->setMaximumSize(QSize(16777215, 16777215));
        frame_ATEQ_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_ATEQ_2->setFrameShape(QFrame::Box);
        frame_ATEQ_2->setFrameShadow(QFrame::Plain);
        gridLayout_6 = new QGridLayout(frame_ATEQ_2);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(2, 2, 2, 2);
        led_JL_Com_2 = new QLabel(frame_ATEQ_2);
        led_JL_Com_2->setObjectName(QString::fromUtf8("led_JL_Com_2"));
        led_JL_Com_2->setMinimumSize(QSize(21, 0));
        led_JL_Com_2->setMaximumSize(QSize(31, 21));
        led_JL_Com_2->setFont(font);
        led_JL_Com_2->setFrameShape(QFrame::Box);
        led_JL_Com_2->setTextFormat(Qt::AutoText);
        led_JL_Com_2->setScaledContents(false);
        led_JL_Com_2->setAlignment(Qt::AlignCenter);
        led_JL_Com_2->setWordWrap(false);

        gridLayout_6->addWidget(led_JL_Com_2, 0, 2, 1, 1);

        label_36 = new QLabel(frame_ATEQ_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(0, 0));
        label_36->setMaximumSize(QSize(16777215, 21));
        label_36->setFont(font2);
        label_36->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_36->setFrameShape(QFrame::NoFrame);
        label_36->setTextFormat(Qt::AutoText);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_36->setWordWrap(false);

        gridLayout_6->addWidget(label_36, 0, 1, 1, 1);

        led_ATEQ_Channel_2 = new QLabel(frame_ATEQ_2);
        led_ATEQ_Channel_2->setObjectName(QString::fromUtf8("led_ATEQ_Channel_2"));
        led_ATEQ_Channel_2->setMinimumSize(QSize(21, 0));
        led_ATEQ_Channel_2->setMaximumSize(QSize(31, 21));
        led_ATEQ_Channel_2->setFont(font);
        led_ATEQ_Channel_2->setFrameShape(QFrame::Box);
        led_ATEQ_Channel_2->setTextFormat(Qt::AutoText);
        led_ATEQ_Channel_2->setScaledContents(false);
        led_ATEQ_Channel_2->setAlignment(Qt::AlignCenter);
        led_ATEQ_Channel_2->setWordWrap(false);

        gridLayout_6->addWidget(led_ATEQ_Channel_2, 0, 0, 1, 1);

        led_ATEQ_Res_2 = new QLabel(frame_ATEQ_2);
        led_ATEQ_Res_2->setObjectName(QString::fromUtf8("led_ATEQ_Res_2"));
        led_ATEQ_Res_2->setMinimumSize(QSize(0, 25));
        led_ATEQ_Res_2->setMaximumSize(QSize(16777215, 31));
        led_ATEQ_Res_2->setFont(font1);
        led_ATEQ_Res_2->setFrameShape(QFrame::Panel);
        led_ATEQ_Res_2->setFrameShadow(QFrame::Sunken);
        led_ATEQ_Res_2->setTextFormat(Qt::AutoText);
        led_ATEQ_Res_2->setAlignment(Qt::AlignCenter);
        led_ATEQ_Res_2->setWordWrap(true);

        gridLayout_6->addWidget(led_ATEQ_Res_2, 1, 0, 1, 3);


        horizontalLayout_3->addWidget(frame_ATEQ_2);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 2);

        textBrowser = new QTextBrowser(MFormATEQ);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 3, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_22 = new QLabel(MFormATEQ);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setMinimumSize(QSize(81, 0));
        label_22->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_22);

        CBB_COM_JL_1 = new QComboBox(MFormATEQ);
        CBB_COM_JL_1->addItem(QString());
        CBB_COM_JL_1->setObjectName(QString::fromUtf8("CBB_COM_JL_1"));
        sizePolicy.setHeightForWidth(CBB_COM_JL_1->sizePolicy().hasHeightForWidth());
        CBB_COM_JL_1->setSizePolicy(sizePolicy);
        CBB_COM_JL_1->setMinimumSize(QSize(81, 0));
        CBB_COM_JL_1->setMaximumSize(QSize(16777215, 16777215));
        CBB_COM_JL_1->setFont(font1);
        CBB_COM_JL_1->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout->addWidget(CBB_COM_JL_1);

        Btn_Updata_Com_2 = new QPushButton(MFormATEQ);
        Btn_Updata_Com_2->setObjectName(QString::fromUtf8("Btn_Updata_Com_2"));
        Btn_Updata_Com_2->setEnabled(true);
        sizePolicy.setHeightForWidth(Btn_Updata_Com_2->sizePolicy().hasHeightForWidth());
        Btn_Updata_Com_2->setSizePolicy(sizePolicy);
        Btn_Updata_Com_2->setMinimumSize(QSize(0, 0));
        Btn_Updata_Com_2->setMaximumSize(QSize(16777215, 16777215));
        Btn_Updata_Com_2->setFont(font);
        Btn_Updata_Com_2->setIconSize(QSize(30, 30));
        Btn_Updata_Com_2->setAutoRepeat(false);

        horizontalLayout->addWidget(Btn_Updata_Com_2);

        label_24 = new QLabel(MFormATEQ);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setMinimumSize(QSize(81, 0));
        label_24->setMaximumSize(QSize(16777215, 16777215));
        label_24->setFont(font3);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_24);

        CBB_Buad_JL_1 = new QComboBox(MFormATEQ);
        CBB_Buad_JL_1->addItem(QString());
        CBB_Buad_JL_1->addItem(QString());
        CBB_Buad_JL_1->addItem(QString());
        CBB_Buad_JL_1->addItem(QString());
        CBB_Buad_JL_1->setObjectName(QString::fromUtf8("CBB_Buad_JL_1"));
        sizePolicy.setHeightForWidth(CBB_Buad_JL_1->sizePolicy().hasHeightForWidth());
        CBB_Buad_JL_1->setSizePolicy(sizePolicy);
        CBB_Buad_JL_1->setMinimumSize(QSize(81, 0));
        CBB_Buad_JL_1->setMaximumSize(QSize(16777215, 16777215));
        CBB_Buad_JL_1->setFont(font1);
        CBB_Buad_JL_1->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout->addWidget(CBB_Buad_JL_1);

        Btn_JL_1 = new QPushButton(MFormATEQ);
        Btn_JL_1->setObjectName(QString::fromUtf8("Btn_JL_1"));
        sizePolicy.setHeightForWidth(Btn_JL_1->sizePolicy().hasHeightForWidth());
        Btn_JL_1->setSizePolicy(sizePolicy);
        Btn_JL_1->setMinimumSize(QSize(81, 0));
        Btn_JL_1->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        Btn_JL_1->setFont(font4);

        horizontalLayout->addWidget(Btn_JL_1);


        gridLayout->addLayout(horizontalLayout, 0, 0, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_25 = new QLabel(MFormATEQ);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMinimumSize(QSize(81, 0));
        label_25->setMaximumSize(QSize(16777215, 16777215));
        label_25->setFont(font3);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_25);

        CBB_COM_JL_2 = new QComboBox(MFormATEQ);
        CBB_COM_JL_2->addItem(QString());
        CBB_COM_JL_2->setObjectName(QString::fromUtf8("CBB_COM_JL_2"));
        sizePolicy.setHeightForWidth(CBB_COM_JL_2->sizePolicy().hasHeightForWidth());
        CBB_COM_JL_2->setSizePolicy(sizePolicy);
        CBB_COM_JL_2->setMinimumSize(QSize(81, 0));
        CBB_COM_JL_2->setMaximumSize(QSize(16777215, 16777215));
        CBB_COM_JL_2->setFont(font1);
        CBB_COM_JL_2->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout_2->addWidget(CBB_COM_JL_2);

        Btn_Updata_Com_3 = new QPushButton(MFormATEQ);
        Btn_Updata_Com_3->setObjectName(QString::fromUtf8("Btn_Updata_Com_3"));
        Btn_Updata_Com_3->setEnabled(true);
        sizePolicy.setHeightForWidth(Btn_Updata_Com_3->sizePolicy().hasHeightForWidth());
        Btn_Updata_Com_3->setSizePolicy(sizePolicy);
        Btn_Updata_Com_3->setMinimumSize(QSize(0, 0));
        Btn_Updata_Com_3->setMaximumSize(QSize(16777215, 16777215));
        Btn_Updata_Com_3->setFont(font);
        Btn_Updata_Com_3->setIconSize(QSize(30, 30));
        Btn_Updata_Com_3->setAutoRepeat(false);

        horizontalLayout_2->addWidget(Btn_Updata_Com_3);

        label_26 = new QLabel(MFormATEQ);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(81, 0));
        label_26->setMaximumSize(QSize(16777215, 16777215));
        label_26->setFont(font3);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_26);

        CBB_Buad_JL_2 = new QComboBox(MFormATEQ);
        CBB_Buad_JL_2->addItem(QString());
        CBB_Buad_JL_2->addItem(QString());
        CBB_Buad_JL_2->addItem(QString());
        CBB_Buad_JL_2->addItem(QString());
        CBB_Buad_JL_2->setObjectName(QString::fromUtf8("CBB_Buad_JL_2"));
        sizePolicy.setHeightForWidth(CBB_Buad_JL_2->sizePolicy().hasHeightForWidth());
        CBB_Buad_JL_2->setSizePolicy(sizePolicy);
        CBB_Buad_JL_2->setMinimumSize(QSize(81, 0));
        CBB_Buad_JL_2->setMaximumSize(QSize(16777215, 16777215));
        CBB_Buad_JL_2->setFont(font1);
        CBB_Buad_JL_2->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);\n"
""));

        horizontalLayout_2->addWidget(CBB_Buad_JL_2);

        Btn_JL_2 = new QPushButton(MFormATEQ);
        Btn_JL_2->setObjectName(QString::fromUtf8("Btn_JL_2"));
        sizePolicy.setHeightForWidth(Btn_JL_2->sizePolicy().hasHeightForWidth());
        Btn_JL_2->setSizePolicy(sizePolicy);
        Btn_JL_2->setMinimumSize(QSize(81, 0));
        Btn_JL_2->setMaximumSize(QSize(16777215, 16777215));
        Btn_JL_2->setFont(font4);

        horizontalLayout_2->addWidget(Btn_JL_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        BTN_Save = new QPushButton(MFormATEQ);
        BTN_Save->setObjectName(QString::fromUtf8("BTN_Save"));
        sizePolicy.setHeightForWidth(BTN_Save->sizePolicy().hasHeightForWidth());
        BTN_Save->setSizePolicy(sizePolicy);
        BTN_Save->setMinimumSize(QSize(81, 0));
        BTN_Save->setMaximumSize(QSize(16777215, 16777215));
        BTN_Save->setFont(font);

        gridLayout->addWidget(BTN_Save, 0, 1, 1, 1);


        retranslateUi(MFormATEQ);

        QMetaObject::connectSlotsByName(MFormATEQ);
    } // setupUi

    void retranslateUi(QDialog *MFormATEQ)
    {
        MFormATEQ->setWindowTitle(QString());
        led_JL_Com_1->setText(QString());
        led_ATEQ_Channel_1->setText(QString());
        led_ATEQ_Res_1->setText(QString());
        label_35->setText(QCoreApplication::translate("MFormATEQ", "ATEQ 1                     \350\277\236\346\216\245\347\212\266\346\200\201: ", nullptr));
        led_JL_Com_2->setText(QString());
        label_36->setText(QCoreApplication::translate("MFormATEQ", "ATEQ 2                     \350\277\236\346\216\245\347\212\266\346\200\201: ", nullptr));
        led_ATEQ_Channel_2->setText(QString());
        led_ATEQ_Res_2->setText(QString());
        label_22->setText(QCoreApplication::translate("MFormATEQ", "ATEQ1 Port:", nullptr));
        CBB_COM_JL_1->setItemText(0, QString());

        Btn_Updata_Com_2->setText(QCoreApplication::translate("MFormATEQ", "\345\210\267\346\226\260", nullptr));
        label_24->setText(QCoreApplication::translate("MFormATEQ", "ATEQ1 Baud:", nullptr));
        CBB_Buad_JL_1->setItemText(0, QString());
        CBB_Buad_JL_1->setItemText(1, QCoreApplication::translate("MFormATEQ", "9600", nullptr));
        CBB_Buad_JL_1->setItemText(2, QCoreApplication::translate("MFormATEQ", "19200", nullptr));
        CBB_Buad_JL_1->setItemText(3, QCoreApplication::translate("MFormATEQ", "115200", nullptr));

        Btn_JL_1->setText(QCoreApplication::translate("MFormATEQ", "ON/OFF", nullptr));
        label_25->setText(QCoreApplication::translate("MFormATEQ", "ATEQ2 Port:", nullptr));
        CBB_COM_JL_2->setItemText(0, QString());

        Btn_Updata_Com_3->setText(QCoreApplication::translate("MFormATEQ", "\345\210\267\346\226\260", nullptr));
        label_26->setText(QCoreApplication::translate("MFormATEQ", "ATEQ2 Baud:", nullptr));
        CBB_Buad_JL_2->setItemText(0, QString());
        CBB_Buad_JL_2->setItemText(1, QCoreApplication::translate("MFormATEQ", "9600", nullptr));
        CBB_Buad_JL_2->setItemText(2, QCoreApplication::translate("MFormATEQ", "19200", nullptr));
        CBB_Buad_JL_2->setItemText(3, QCoreApplication::translate("MFormATEQ", "115200", nullptr));

        Btn_JL_2->setText(QCoreApplication::translate("MFormATEQ", "ON/OFF", nullptr));
        BTN_Save->setText(QCoreApplication::translate("MFormATEQ", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MFormATEQ: public Ui_MFormATEQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORMATEQ_H

/********************************************************************************
** Form generated from reading UI file 'MForm_ScanCode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORM_SCANCODE_H
#define UI_MFORM_SCANCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MForm_ScanCode
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *Cbt_Port;
    QPushButton *Btn_Update;
    QLabel *label;
    QComboBox *Cbt_Buad;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_OpenClose;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *Cbt_Port_2;
    QPushButton *Btn_Update_2;
    QLabel *label_6;
    QComboBox *Cbt_Buad_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Btn_OpenClose_2;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_Save;

    void setupUi(QDialog *MForm_ScanCode)
    {
        if (MForm_ScanCode->objectName().isEmpty())
            MForm_ScanCode->setObjectName(QString::fromUtf8("MForm_ScanCode"));
        MForm_ScanCode->resize(792, 328);
        gridLayout = new QGridLayout(MForm_ScanCode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(MForm_ScanCode);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{border: 0px solid white;}"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        Cbt_Port = new QComboBox(groupBox);
        Cbt_Port->setObjectName(QString::fromUtf8("Cbt_Port"));

        horizontalLayout->addWidget(Cbt_Port);

        Btn_Update = new QPushButton(groupBox);
        Btn_Update->setObjectName(QString::fromUtf8("Btn_Update"));
        Btn_Update->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(Btn_Update);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Cbt_Buad = new QComboBox(groupBox);
        Cbt_Buad->addItem(QString());
        Cbt_Buad->addItem(QString());
        Cbt_Buad->addItem(QString());
        Cbt_Buad->addItem(QString());
        Cbt_Buad->setObjectName(QString::fromUtf8("Cbt_Buad"));

        horizontalLayout->addWidget(Cbt_Buad);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_OpenClose = new QPushButton(groupBox);
        Btn_OpenClose->setObjectName(QString::fromUtf8("Btn_OpenClose"));

        horizontalLayout->addWidget(Btn_OpenClose);


        verticalLayout_2->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(MForm_ScanCode);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{border: 0px solid white;}"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        Cbt_Port_2 = new QComboBox(groupBox_2);
        Cbt_Port_2->setObjectName(QString::fromUtf8("Cbt_Port_2"));

        horizontalLayout_4->addWidget(Cbt_Port_2);

        Btn_Update_2 = new QPushButton(groupBox_2);
        Btn_Update_2->setObjectName(QString::fromUtf8("Btn_Update_2"));
        Btn_Update_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(Btn_Update_2);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        Cbt_Buad_2 = new QComboBox(groupBox_2);
        Cbt_Buad_2->addItem(QString());
        Cbt_Buad_2->addItem(QString());
        Cbt_Buad_2->addItem(QString());
        Cbt_Buad_2->addItem(QString());
        Cbt_Buad_2->setObjectName(QString::fromUtf8("Cbt_Buad_2"));

        horizontalLayout_4->addWidget(Cbt_Buad_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        Btn_OpenClose_2 = new QPushButton(groupBox_2);
        Btn_OpenClose_2->setObjectName(QString::fromUtf8("Btn_OpenClose_2"));

        horizontalLayout_4->addWidget(Btn_OpenClose_2);


        verticalLayout->addLayout(horizontalLayout_4);

        textBrowser_2 = new QTextBrowser(groupBox_2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout->addWidget(textBrowser_2);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Btn_Save = new QPushButton(MForm_ScanCode);
        Btn_Save->setObjectName(QString::fromUtf8("Btn_Save"));

        horizontalLayout_2->addWidget(Btn_Save);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        retranslateUi(MForm_ScanCode);

        QMetaObject::connectSlotsByName(MForm_ScanCode);
    } // setupUi

    void retranslateUi(QDialog *MForm_ScanCode)
    {
        MForm_ScanCode->setWindowTitle(QString());
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MForm_ScanCode", "\347\253\257\345\217\243\345\217\267", nullptr));
        Btn_Update->setText(QCoreApplication::translate("MForm_ScanCode", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("MForm_ScanCode", "\346\263\242\347\211\271\347\216\207", nullptr));
        Cbt_Buad->setItemText(0, QString());
        Cbt_Buad->setItemText(1, QCoreApplication::translate("MForm_ScanCode", "9600", nullptr));
        Cbt_Buad->setItemText(2, QCoreApplication::translate("MForm_ScanCode", "19200", nullptr));
        Cbt_Buad->setItemText(3, QCoreApplication::translate("MForm_ScanCode", "115200", nullptr));

        Btn_OpenClose->setText(QCoreApplication::translate("MForm_ScanCode", "\346\211\253\347\240\201\346\236\252", nullptr));
        groupBox_2->setTitle(QString());
        label_5->setText(QCoreApplication::translate("MForm_ScanCode", "\347\253\257\345\217\243\345\217\267", nullptr));
        Btn_Update_2->setText(QCoreApplication::translate("MForm_ScanCode", "\345\210\267\346\226\260", nullptr));
        label_6->setText(QCoreApplication::translate("MForm_ScanCode", "\346\263\242\347\211\271\347\216\207", nullptr));
        Cbt_Buad_2->setItemText(0, QString());
        Cbt_Buad_2->setItemText(1, QCoreApplication::translate("MForm_ScanCode", "9600", nullptr));
        Cbt_Buad_2->setItemText(2, QCoreApplication::translate("MForm_ScanCode", "19200", nullptr));
        Cbt_Buad_2->setItemText(3, QCoreApplication::translate("MForm_ScanCode", "115200", nullptr));

        Btn_OpenClose_2->setText(QCoreApplication::translate("MForm_ScanCode", "\346\211\253\347\240\201\346\236\252", nullptr));
        Btn_Save->setText(QCoreApplication::translate("MForm_ScanCode", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MForm_ScanCode: public Ui_MForm_ScanCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORM_SCANCODE_H

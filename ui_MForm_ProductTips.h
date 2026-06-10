/********************************************************************************
** Form generated from reading UI file 'MForm_ProductTips.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORM_PRODUCTTIPS_H
#define UI_MFORM_PRODUCTTIPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MForm_ProductTips
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *MForm_ProductTips)
    {
        if (MForm_ProductTips->objectName().isEmpty())
            MForm_ProductTips->setObjectName(QString::fromUtf8("MForm_ProductTips"));
        MForm_ProductTips->resize(551, 142);
        MForm_ProductTips->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
""));
        horizontalLayout = new QHBoxLayout(MForm_ProductTips);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MForm_ProductTips);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);


        retranslateUi(MForm_ProductTips);

        QMetaObject::connectSlotsByName(MForm_ProductTips);
    } // setupUi

    void retranslateUi(QDialog *MForm_ProductTips)
    {
        MForm_ProductTips->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("MForm_ProductTips", "\344\272\247\345\223\201\344\270\215\345\220\210\346\240\274\357\274\214\350\257\267\346\224\276\347\275\256\345\210\260NG\346\226\231\350\275\246\346\210\226\351\207\215\346\226\260\346\243\200\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MForm_ProductTips: public Ui_MForm_ProductTips {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORM_PRODUCTTIPS_H

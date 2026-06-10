/********************************************************************************
** Form generated from reading UI file 'MFormLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORMLOGIN_H
#define UI_MFORMLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MFormLogin
{
public:
    QPushButton *BTN_changePassword;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *LE_admin;
    QLabel *label_2;
    QLineEdit *LE_Password;
    QPushButton *BTN_OK;

    void setupUi(QDialog *MFormLogin)
    {
        if (MFormLogin->objectName().isEmpty())
            MFormLogin->setObjectName(QString::fromUtf8("MFormLogin"));
        MFormLogin->resize(452, 202);
        QFont font;
        font.setPointSize(12);
        MFormLogin->setFont(font);
        BTN_changePassword = new QPushButton(MFormLogin);
        BTN_changePassword->setObjectName(QString::fromUtf8("BTN_changePassword"));
        BTN_changePassword->setGeometry(QRect(10, 170, 161, 23));
        BTN_changePassword->setFocusPolicy(Qt::NoFocus);
        BTN_changePassword->setCheckable(true);
        label_3 = new QLabel(MFormLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 10, 241, 41));
        QFont font1;
        font1.setPointSize(24);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        widget = new QWidget(MFormLogin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 60, 271, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        LE_admin = new QLineEdit(widget);
        LE_admin->setObjectName(QString::fromUtf8("LE_admin"));
        LE_admin->setMaximumSize(QSize(16777215, 31));
        LE_admin->setFont(font);
        LE_admin->setMaxLength(6);
        LE_admin->setEchoMode(QLineEdit::Normal);
        LE_admin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        LE_admin->setReadOnly(true);

        gridLayout->addWidget(LE_admin, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        LE_Password = new QLineEdit(widget);
        LE_Password->setObjectName(QString::fromUtf8("LE_Password"));
        LE_Password->setMaximumSize(QSize(16777215, 31));
        LE_Password->setFont(font);
        LE_Password->setMaxLength(6);
        LE_Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(LE_Password, 1, 1, 1, 1);

        BTN_OK = new QPushButton(widget);
        BTN_OK->setObjectName(QString::fromUtf8("BTN_OK"));
        BTN_OK->setMaximumSize(QSize(16777215, 31));

        gridLayout->addWidget(BTN_OK, 1, 2, 1, 1);

        QWidget::setTabOrder(LE_Password, BTN_changePassword);
        QWidget::setTabOrder(BTN_changePassword, BTN_OK);
        QWidget::setTabOrder(BTN_OK, LE_admin);

        retranslateUi(MFormLogin);

        QMetaObject::connectSlotsByName(MFormLogin);
    } // setupUi

    void retranslateUi(QDialog *MFormLogin)
    {
        MFormLogin->setWindowTitle(QString());
        BTN_changePassword->setText(QCoreApplication::translate("MFormLogin", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("MFormLogin", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("MFormLogin", "\347\224\250\346\210\267", nullptr));
        LE_admin->setText(QCoreApplication::translate("MFormLogin", "admin", nullptr));
        label_2->setText(QCoreApplication::translate("MFormLogin", "\345\257\206\347\240\201", nullptr));
        BTN_OK->setText(QCoreApplication::translate("MFormLogin", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MFormLogin: public Ui_MFormLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORMLOGIN_H

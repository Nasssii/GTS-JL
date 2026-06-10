/********************************************************************************
** Form generated from reading UI file 'MFormWorkStep.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFORMWORKSTEP_H
#define UI_MFORMWORKSTEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MFormWorkStep
{
public:
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_23;
    QComboBox *Channel;
    QLabel *label_9;
    QLineEdit *SettingProductName;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_25;
    QComboBox *Copy_Channel;
    QPushButton *Btn_Copy_Channel_Sure;
    QSpacerItem *horizontalSpacer_3;
    QLabel *Tip_SavePars;
    QPushButton *Btn_Sure;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Use;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGroupBox *GB_SN;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_26;
    QLineEdit *SetKeyCode_1;
    QLabel *label_46;
    QSpinBox *SPB_code_length_1;
    QLabel *label_28;
    QSpinBox *SPB_CodeStation_1;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_47;
    QComboBox *Cbt_ATEQ_Enable;
    QCheckBox *CBX_Positive;
    QSpinBox *Channel_Positive;
    QCheckBox *CBX_Negative;
    QSpinBox *Channel_Negative;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QWidget *MFormWorkStep)
    {
        if (MFormWorkStep->objectName().isEmpty())
            MFormWorkStep->setObjectName(QString::fromUtf8("MFormWorkStep"));
        MFormWorkStep->resize(1172, 712);
        gridLayout_6 = new QGridLayout(MFormWorkStep);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame = new QFrame(MFormWorkStep);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setMinimumSize(QSize(0, 31));
        label_23->setMaximumSize(QSize(120, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_23);

        Channel = new QComboBox(frame);
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->addItem(QString());
        Channel->setObjectName(QString::fromUtf8("Channel"));
        Channel->setEnabled(true);
        sizePolicy.setHeightForWidth(Channel->sizePolicy().hasHeightForWidth());
        Channel->setSizePolicy(sizePolicy);
        Channel->setMinimumSize(QSize(81, 31));
        Channel->setMaximumSize(QSize(81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        Channel->setFont(font1);
        Channel->setAutoFillBackground(false);
        Channel->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);"));
        Channel->setEditable(false);
        Channel->setMaxVisibleItems(20);
        Channel->setDuplicatesEnabled(false);
        Channel->setFrame(true);

        horizontalLayout->addWidget(Channel);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(81, 31));
        label_9->setMaximumSize(QSize(141, 31));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_9);

        SettingProductName = new QLineEdit(frame);
        SettingProductName->setObjectName(QString::fromUtf8("SettingProductName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SettingProductName->sizePolicy().hasHeightForWidth());
        SettingProductName->setSizePolicy(sizePolicy1);
        SettingProductName->setMinimumSize(QSize(201, 31));
        SettingProductName->setMaximumSize(QSize(16777215, 31));
        SettingProductName->setFont(font);
        SettingProductName->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(SettingProductName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_6->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(MFormWorkStep);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_25 = new QLabel(frame_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(0, 31));
        label_25->setMaximumSize(QSize(16777215, 31));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_25);

        Copy_Channel = new QComboBox(frame_2);
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->addItem(QString());
        Copy_Channel->setObjectName(QString::fromUtf8("Copy_Channel"));
        Copy_Channel->setEnabled(true);
        Copy_Channel->setMinimumSize(QSize(51, 31));
        Copy_Channel->setMaximumSize(QSize(51, 31));
        Copy_Channel->setFont(font1);
        Copy_Channel->setAutoFillBackground(false);
        Copy_Channel->setStyleSheet(QString::fromUtf8("border-color: rgb(190, 190, 190);\n"
"border: 1px solid rgb(0,0,0);"));
        Copy_Channel->setEditable(false);
        Copy_Channel->setDuplicatesEnabled(false);
        Copy_Channel->setFrame(true);

        horizontalLayout_5->addWidget(Copy_Channel);

        Btn_Copy_Channel_Sure = new QPushButton(frame_2);
        Btn_Copy_Channel_Sure->setObjectName(QString::fromUtf8("Btn_Copy_Channel_Sure"));
        Btn_Copy_Channel_Sure->setMinimumSize(QSize(0, 31));
        Btn_Copy_Channel_Sure->setMaximumSize(QSize(16777215, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        Btn_Copy_Channel_Sure->setFont(font2);
        Btn_Copy_Channel_Sure->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_5->addWidget(Btn_Copy_Channel_Sure);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        Tip_SavePars = new QLabel(frame_2);
        Tip_SavePars->setObjectName(QString::fromUtf8("Tip_SavePars"));
        sizePolicy1.setHeightForWidth(Tip_SavePars->sizePolicy().hasHeightForWidth());
        Tip_SavePars->setSizePolicy(sizePolicy1);
        Tip_SavePars->setMinimumSize(QSize(0, 31));
        Tip_SavePars->setMaximumSize(QSize(16777215, 16777215));
        Tip_SavePars->setFont(font1);
        Tip_SavePars->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        Tip_SavePars->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(Tip_SavePars);

        Btn_Sure = new QPushButton(frame_2);
        Btn_Sure->setObjectName(QString::fromUtf8("Btn_Sure"));
        Btn_Sure->setMinimumSize(QSize(0, 31));
        Btn_Sure->setMaximumSize(QSize(16777215, 31));
        Btn_Sure->setFont(font2);
        Btn_Sure->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_5->addWidget(Btn_Sure);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        Btn_Use = new QPushButton(frame_2);
        Btn_Use->setObjectName(QString::fromUtf8("Btn_Use"));
        Btn_Use->setMinimumSize(QSize(0, 31));
        Btn_Use->setMaximumSize(QSize(16777215, 31));
        Btn_Use->setFont(font2);
        Btn_Use->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_5->addWidget(Btn_Use);


        gridLayout_6->addWidget(frame_2, 2, 0, 1, 1);

        tabWidget = new QTabWidget(MFormWorkStep);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font2);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        GB_SN = new QGroupBox(tab_5);
        GB_SN->setObjectName(QString::fromUtf8("GB_SN"));
        GB_SN->setGeometry(QRect(10, 356, 1101, 121));
        GB_SN->setMinimumSize(QSize(0, 0));
        GB_SN->setMaximumSize(QSize(16777215, 16777215));
        GB_SN->setFont(font2);
        gridLayout = new QGridLayout(GB_SN);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_26 = new QLabel(GB_SN);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMaximumSize(QSize(81, 16777215));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignCenter);
        label_26->setWordWrap(false);

        horizontalLayout_2->addWidget(label_26);

        SetKeyCode_1 = new QLineEdit(GB_SN);
        SetKeyCode_1->setObjectName(QString::fromUtf8("SetKeyCode_1"));
        sizePolicy.setHeightForWidth(SetKeyCode_1->sizePolicy().hasHeightForWidth());
        SetKeyCode_1->setSizePolicy(sizePolicy);
        SetKeyCode_1->setMinimumSize(QSize(401, 31));
        SetKeyCode_1->setMaximumSize(QSize(16777215, 16777215));
        SetKeyCode_1->setFont(font);
        SetKeyCode_1->setDragEnabled(false);
        SetKeyCode_1->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(SetKeyCode_1);

        label_46 = new QLabel(GB_SN);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMaximumSize(QSize(91, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        label_46->setFont(font3);
        label_46->setStyleSheet(QString::fromUtf8(""));
        label_46->setAlignment(Qt::AlignCenter);
        label_46->setWordWrap(false);

        horizontalLayout_2->addWidget(label_46);

        SPB_code_length_1 = new QSpinBox(GB_SN);
        SPB_code_length_1->setObjectName(QString::fromUtf8("SPB_code_length_1"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SPB_code_length_1->sizePolicy().hasHeightForWidth());
        SPB_code_length_1->setSizePolicy(sizePolicy3);
        SPB_code_length_1->setMaximumSize(QSize(60, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(16);
        SPB_code_length_1->setFont(font4);
        SPB_code_length_1->setAlignment(Qt::AlignCenter);
        SPB_code_length_1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        SPB_code_length_1->setMaximum(100);

        horizontalLayout_2->addWidget(SPB_code_length_1);

        label_28 = new QLabel(GB_SN);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(91, 16777215));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8(""));
        label_28->setAlignment(Qt::AlignCenter);
        label_28->setWordWrap(false);

        horizontalLayout_2->addWidget(label_28);

        SPB_CodeStation_1 = new QSpinBox(GB_SN);
        SPB_CodeStation_1->setObjectName(QString::fromUtf8("SPB_CodeStation_1"));
        sizePolicy.setHeightForWidth(SPB_CodeStation_1->sizePolicy().hasHeightForWidth());
        SPB_CodeStation_1->setSizePolicy(sizePolicy);
        SPB_CodeStation_1->setMinimumSize(QSize(121, 31));
        SPB_CodeStation_1->setMaximumSize(QSize(121, 81));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(12);
        SPB_CodeStation_1->setFont(font5);
        SPB_CodeStation_1->setMinimum(0);
        SPB_CodeStation_1->setMaximum(1);
        SPB_CodeStation_1->setValue(0);

        horizontalLayout_2->addWidget(SPB_CodeStation_1);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(tab_5);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(480, 40, 561, 261));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(tab_5);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 120, 201, 132));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_47 = new QLabel(layoutWidget);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMinimumSize(QSize(160, 0));
        label_47->setMaximumSize(QSize(160, 16777215));
        label_47->setFont(font);
        label_47->setStyleSheet(QString::fromUtf8(""));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_47->setWordWrap(false);

        gridLayout_2->addWidget(label_47, 0, 0, 1, 2);

        Cbt_ATEQ_Enable = new QComboBox(layoutWidget);
        Cbt_ATEQ_Enable->addItem(QString());
        Cbt_ATEQ_Enable->addItem(QString());
        Cbt_ATEQ_Enable->addItem(QString());
        Cbt_ATEQ_Enable->addItem(QString());
        Cbt_ATEQ_Enable->setObjectName(QString::fromUtf8("Cbt_ATEQ_Enable"));
        Cbt_ATEQ_Enable->setMinimumSize(QSize(160, 31));
        Cbt_ATEQ_Enable->setMaximumSize(QSize(16777215, 16777215));
        Cbt_ATEQ_Enable->setFont(font);
        Cbt_ATEQ_Enable->setMaxVisibleItems(20);
        Cbt_ATEQ_Enable->setMaxCount(10);

        gridLayout_2->addWidget(Cbt_ATEQ_Enable, 1, 0, 1, 2);

        CBX_Positive = new QCheckBox(layoutWidget);
        CBX_Positive->setObjectName(QString::fromUtf8("CBX_Positive"));

        gridLayout_2->addWidget(CBX_Positive, 2, 0, 1, 1);

        Channel_Positive = new QSpinBox(layoutWidget);
        Channel_Positive->setObjectName(QString::fromUtf8("Channel_Positive"));
        Channel_Positive->setMinimum(1);
        Channel_Positive->setMaximum(32);

        gridLayout_2->addWidget(Channel_Positive, 2, 1, 1, 1);

        CBX_Negative = new QCheckBox(layoutWidget);
        CBX_Negative->setObjectName(QString::fromUtf8("CBX_Negative"));

        gridLayout_2->addWidget(CBX_Negative, 3, 0, 1, 1);

        Channel_Negative = new QSpinBox(layoutWidget);
        Channel_Negative->setObjectName(QString::fromUtf8("Channel_Negative"));
        Channel_Negative->setMinimum(1);
        Channel_Negative->setMaximum(32);

        gridLayout_2->addWidget(Channel_Negative, 3, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayoutWidget_2 = new QWidget(tab_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(180, 60, 831, 431));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(MFormWorkStep);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MFormWorkStep);
    } // setupUi

    void retranslateUi(QWidget *MFormWorkStep)
    {
        MFormWorkStep->setWindowTitle(QString());
        label_23->setText(QCoreApplication::translate("MFormWorkStep", "\351\242\221\351\201\223\357\274\232", nullptr));
        Channel->setItemText(0, QString());
        Channel->setItemText(1, QCoreApplication::translate("MFormWorkStep", "1", nullptr));
        Channel->setItemText(2, QCoreApplication::translate("MFormWorkStep", "2", nullptr));
        Channel->setItemText(3, QCoreApplication::translate("MFormWorkStep", "3", nullptr));
        Channel->setItemText(4, QCoreApplication::translate("MFormWorkStep", "4", nullptr));
        Channel->setItemText(5, QCoreApplication::translate("MFormWorkStep", "5", nullptr));
        Channel->setItemText(6, QCoreApplication::translate("MFormWorkStep", "6", nullptr));
        Channel->setItemText(7, QCoreApplication::translate("MFormWorkStep", "7", nullptr));
        Channel->setItemText(8, QCoreApplication::translate("MFormWorkStep", "8", nullptr));
        Channel->setItemText(9, QCoreApplication::translate("MFormWorkStep", "9", nullptr));
        Channel->setItemText(10, QCoreApplication::translate("MFormWorkStep", "10", nullptr));
        Channel->setItemText(11, QCoreApplication::translate("MFormWorkStep", "11", nullptr));
        Channel->setItemText(12, QCoreApplication::translate("MFormWorkStep", "12", nullptr));
        Channel->setItemText(13, QCoreApplication::translate("MFormWorkStep", "13", nullptr));
        Channel->setItemText(14, QCoreApplication::translate("MFormWorkStep", "14", nullptr));
        Channel->setItemText(15, QCoreApplication::translate("MFormWorkStep", "15", nullptr));
        Channel->setItemText(16, QCoreApplication::translate("MFormWorkStep", "16", nullptr));
        Channel->setItemText(17, QCoreApplication::translate("MFormWorkStep", "17", nullptr));
        Channel->setItemText(18, QCoreApplication::translate("MFormWorkStep", "18", nullptr));
        Channel->setItemText(19, QCoreApplication::translate("MFormWorkStep", "19", nullptr));
        Channel->setItemText(20, QCoreApplication::translate("MFormWorkStep", "20", nullptr));
        Channel->setItemText(21, QCoreApplication::translate("MFormWorkStep", "21", nullptr));
        Channel->setItemText(22, QCoreApplication::translate("MFormWorkStep", "22", nullptr));
        Channel->setItemText(23, QCoreApplication::translate("MFormWorkStep", "23", nullptr));
        Channel->setItemText(24, QCoreApplication::translate("MFormWorkStep", "24", nullptr));
        Channel->setItemText(25, QCoreApplication::translate("MFormWorkStep", "25", nullptr));
        Channel->setItemText(26, QCoreApplication::translate("MFormWorkStep", "26", nullptr));
        Channel->setItemText(27, QCoreApplication::translate("MFormWorkStep", "27", nullptr));
        Channel->setItemText(28, QCoreApplication::translate("MFormWorkStep", "28", nullptr));
        Channel->setItemText(29, QCoreApplication::translate("MFormWorkStep", "29", nullptr));
        Channel->setItemText(30, QCoreApplication::translate("MFormWorkStep", "30", nullptr));
        Channel->setItemText(31, QCoreApplication::translate("MFormWorkStep", "31", nullptr));
        Channel->setItemText(32, QCoreApplication::translate("MFormWorkStep", "32", nullptr));
        Channel->setItemText(33, QCoreApplication::translate("MFormWorkStep", "33", nullptr));
        Channel->setItemText(34, QCoreApplication::translate("MFormWorkStep", "34", nullptr));
        Channel->setItemText(35, QCoreApplication::translate("MFormWorkStep", "35", nullptr));
        Channel->setItemText(36, QCoreApplication::translate("MFormWorkStep", "36", nullptr));
        Channel->setItemText(37, QCoreApplication::translate("MFormWorkStep", "37", nullptr));
        Channel->setItemText(38, QCoreApplication::translate("MFormWorkStep", "38", nullptr));
        Channel->setItemText(39, QCoreApplication::translate("MFormWorkStep", "39", nullptr));
        Channel->setItemText(40, QCoreApplication::translate("MFormWorkStep", "40", nullptr));
        Channel->setItemText(41, QCoreApplication::translate("MFormWorkStep", "41", nullptr));
        Channel->setItemText(42, QCoreApplication::translate("MFormWorkStep", "42", nullptr));
        Channel->setItemText(43, QCoreApplication::translate("MFormWorkStep", "43", nullptr));
        Channel->setItemText(44, QCoreApplication::translate("MFormWorkStep", "44", nullptr));
        Channel->setItemText(45, QCoreApplication::translate("MFormWorkStep", "45", nullptr));
        Channel->setItemText(46, QCoreApplication::translate("MFormWorkStep", "46", nullptr));
        Channel->setItemText(47, QCoreApplication::translate("MFormWorkStep", "47", nullptr));
        Channel->setItemText(48, QCoreApplication::translate("MFormWorkStep", "48", nullptr));
        Channel->setItemText(49, QCoreApplication::translate("MFormWorkStep", "49", nullptr));
        Channel->setItemText(50, QCoreApplication::translate("MFormWorkStep", "50", nullptr));

#if QT_CONFIG(whatsthis)
        Channel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_9->setText(QCoreApplication::translate("MFormWorkStep", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_25->setText(QCoreApplication::translate("MFormWorkStep", "\345\244\215\345\210\266\345\210\260\357\274\232", nullptr));
        Copy_Channel->setItemText(0, QString());
        Copy_Channel->setItemText(1, QCoreApplication::translate("MFormWorkStep", "1", nullptr));
        Copy_Channel->setItemText(2, QCoreApplication::translate("MFormWorkStep", "2", nullptr));
        Copy_Channel->setItemText(3, QCoreApplication::translate("MFormWorkStep", "3", nullptr));
        Copy_Channel->setItemText(4, QCoreApplication::translate("MFormWorkStep", "4", nullptr));
        Copy_Channel->setItemText(5, QCoreApplication::translate("MFormWorkStep", "5", nullptr));
        Copy_Channel->setItemText(6, QCoreApplication::translate("MFormWorkStep", "6", nullptr));
        Copy_Channel->setItemText(7, QCoreApplication::translate("MFormWorkStep", "7", nullptr));
        Copy_Channel->setItemText(8, QCoreApplication::translate("MFormWorkStep", "8", nullptr));
        Copy_Channel->setItemText(9, QCoreApplication::translate("MFormWorkStep", "9", nullptr));
        Copy_Channel->setItemText(10, QCoreApplication::translate("MFormWorkStep", "10", nullptr));
        Copy_Channel->setItemText(11, QCoreApplication::translate("MFormWorkStep", "11", nullptr));
        Copy_Channel->setItemText(12, QCoreApplication::translate("MFormWorkStep", "12", nullptr));
        Copy_Channel->setItemText(13, QCoreApplication::translate("MFormWorkStep", "13", nullptr));
        Copy_Channel->setItemText(14, QCoreApplication::translate("MFormWorkStep", "14", nullptr));
        Copy_Channel->setItemText(15, QCoreApplication::translate("MFormWorkStep", "15", nullptr));
        Copy_Channel->setItemText(16, QCoreApplication::translate("MFormWorkStep", "16", nullptr));
        Copy_Channel->setItemText(17, QCoreApplication::translate("MFormWorkStep", "17", nullptr));
        Copy_Channel->setItemText(18, QCoreApplication::translate("MFormWorkStep", "18", nullptr));
        Copy_Channel->setItemText(19, QCoreApplication::translate("MFormWorkStep", "19", nullptr));
        Copy_Channel->setItemText(20, QCoreApplication::translate("MFormWorkStep", "20", nullptr));
        Copy_Channel->setItemText(21, QCoreApplication::translate("MFormWorkStep", "21", nullptr));
        Copy_Channel->setItemText(22, QCoreApplication::translate("MFormWorkStep", "22", nullptr));
        Copy_Channel->setItemText(23, QCoreApplication::translate("MFormWorkStep", "23", nullptr));
        Copy_Channel->setItemText(24, QCoreApplication::translate("MFormWorkStep", "24", nullptr));
        Copy_Channel->setItemText(25, QCoreApplication::translate("MFormWorkStep", "25", nullptr));
        Copy_Channel->setItemText(26, QCoreApplication::translate("MFormWorkStep", "26", nullptr));
        Copy_Channel->setItemText(27, QCoreApplication::translate("MFormWorkStep", "27", nullptr));
        Copy_Channel->setItemText(28, QCoreApplication::translate("MFormWorkStep", "28", nullptr));
        Copy_Channel->setItemText(29, QCoreApplication::translate("MFormWorkStep", "29", nullptr));
        Copy_Channel->setItemText(30, QCoreApplication::translate("MFormWorkStep", "30", nullptr));
        Copy_Channel->setItemText(31, QCoreApplication::translate("MFormWorkStep", "31", nullptr));
        Copy_Channel->setItemText(32, QCoreApplication::translate("MFormWorkStep", "32", nullptr));
        Copy_Channel->setItemText(33, QCoreApplication::translate("MFormWorkStep", "33", nullptr));
        Copy_Channel->setItemText(34, QCoreApplication::translate("MFormWorkStep", "34", nullptr));
        Copy_Channel->setItemText(35, QCoreApplication::translate("MFormWorkStep", "35", nullptr));
        Copy_Channel->setItemText(36, QCoreApplication::translate("MFormWorkStep", "36", nullptr));
        Copy_Channel->setItemText(37, QCoreApplication::translate("MFormWorkStep", "37", nullptr));
        Copy_Channel->setItemText(38, QCoreApplication::translate("MFormWorkStep", "38", nullptr));
        Copy_Channel->setItemText(39, QCoreApplication::translate("MFormWorkStep", "39", nullptr));
        Copy_Channel->setItemText(40, QCoreApplication::translate("MFormWorkStep", "40", nullptr));
        Copy_Channel->setItemText(41, QCoreApplication::translate("MFormWorkStep", "41", nullptr));
        Copy_Channel->setItemText(42, QCoreApplication::translate("MFormWorkStep", "42", nullptr));
        Copy_Channel->setItemText(43, QCoreApplication::translate("MFormWorkStep", "43", nullptr));
        Copy_Channel->setItemText(44, QCoreApplication::translate("MFormWorkStep", "44", nullptr));
        Copy_Channel->setItemText(45, QCoreApplication::translate("MFormWorkStep", "45", nullptr));
        Copy_Channel->setItemText(46, QCoreApplication::translate("MFormWorkStep", "46", nullptr));
        Copy_Channel->setItemText(47, QCoreApplication::translate("MFormWorkStep", "47", nullptr));
        Copy_Channel->setItemText(48, QCoreApplication::translate("MFormWorkStep", "48", nullptr));
        Copy_Channel->setItemText(49, QCoreApplication::translate("MFormWorkStep", "49", nullptr));
        Copy_Channel->setItemText(50, QCoreApplication::translate("MFormWorkStep", "50", nullptr));

#if QT_CONFIG(whatsthis)
        Copy_Channel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Btn_Copy_Channel_Sure->setText(QCoreApplication::translate("MFormWorkStep", "OK", nullptr));
        Tip_SavePars->setText(QCoreApplication::translate("MFormWorkStep", "###", nullptr));
        Btn_Sure->setText(QCoreApplication::translate("MFormWorkStep", "\344\277\235\345\255\230", nullptr));
        Btn_Use->setText(QCoreApplication::translate("MFormWorkStep", "\344\275\277\347\224\250", nullptr));
        GB_SN->setTitle(QCoreApplication::translate("MFormWorkStep", "\344\272\247\345\223\201\346\235\241\345\275\242\347\240\201", nullptr));
        label_26->setText(QCoreApplication::translate("MFormWorkStep", "NO.1", nullptr));
        label_46->setText(QCoreApplication::translate("MFormWorkStep", "\351\225\277\345\272\246", nullptr));
        label_28->setText(QCoreApplication::translate("MFormWorkStep", "\345\205\266\344\273\226\351\200\211\351\241\271:", nullptr));
        SPB_CodeStation_1->setPrefix(QString());
        label_47->setText(QCoreApplication::translate("MFormWorkStep", "\346\260\224\345\257\206\346\200\247\351\200\211\346\213\251:", nullptr));
        Cbt_ATEQ_Enable->setItemText(0, QString());
        Cbt_ATEQ_Enable->setItemText(1, QCoreApplication::translate("MFormWorkStep", "ATEQ 1", nullptr));
        Cbt_ATEQ_Enable->setItemText(2, QCoreApplication::translate("MFormWorkStep", "ATEQ 2", nullptr));
        Cbt_ATEQ_Enable->setItemText(3, QCoreApplication::translate("MFormWorkStep", "ATEQ 1\343\200\201ATEQ 2", nullptr));

        CBX_Positive->setText(QCoreApplication::translate("MFormWorkStep", "\351\241\271\347\233\2561", nullptr));
        CBX_Negative->setText(QCoreApplication::translate("MFormWorkStep", "\351\241\271\347\233\2562", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MFormWorkStep", "\346\235\241\347\240\201\343\200\201\346\243\200\346\274\217\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MFormWorkStep", "\346\211\223\345\215\260\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MFormWorkStep: public Ui_MFormWorkStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFORMWORKSTEP_H

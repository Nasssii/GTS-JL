QT       += core gui serialport sql concurrent network serialbus printsupport axcontainer


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PLC/actutltypelib.cpp \
    Honeywell/MForm_ScanCode.cpp \
    MATEQ/MFormATEQ.cpp \
    MATEQ/combase.cpp \
    MFormLogin.cpp \
    MFormWorkStep.cpp \
    MForm_ProductTips.cpp \
    MFuntions.cpp \
    MLabel/MForm_PrintSetting.cpp \
    MMYSQL/MFormMysql.cpp \
    ModbusRtu/MForm_ModeBusRtu.cpp \
    ModbusRtu/mModbusRtu.cpp \
    mWorkTask.cpp \
    main.cpp \
    MFormJLStation.cpp

HEADERS += \
    PLC/actutltypelib.h \
    Honeywell/MForm_ScanCode.h \
    MATEQ/MFormATEQ.h \
    MATEQ/combase.h \
    MFormJLStation.h \
    MFormLogin.h \
    MFormWorkStep.h \
    MForm_ProductTips.h \
    MFuntions.h \
    MLabel/MForm_PrintSetting.h \
    MMYSQL/MFormMysql.h \
    ModbusRtu/MForm_ModeBusRtu.h \
    ModbusRtu/mModbusRtu.h \
    mWorkTask.h

FORMS += \
    Honeywell/MForm_ScanCode.ui \
    MATEQ/MFormATEQ.ui \
    MFormJLStation.ui \
    MFormLogin.ui \
    MFormWorkStep.ui \
    MForm_ProductTips.ui \
    MLabel/MForm_PrintSetting.ui \
    MMYSQL/MFormMysql.ui \
    ModbusRtu/MForm_ModeBusRtu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RC_FILE += app.rc

RESOURCES += \
    logo.qrc

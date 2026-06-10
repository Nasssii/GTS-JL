/****************************************************************************
** Meta object code from reading C++ file 'MForm_PrintSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MLabel/MForm_PrintSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MForm_PrintSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MForm_PrintSetting_t {
    QByteArrayData data[18];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MForm_PrintSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MForm_PrintSetting_t qt_meta_stringdata_MForm_PrintSetting = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MForm_PrintSetting"
QT_MOC_LITERAL(1, 19, 12), // "slot_printer"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "path"
QT_MOC_LITERAL(4, 38, 12), // "printer_name"
QT_MOC_LITERAL(5, 51, 20), // "slot_Printe_Label_NG"
QT_MOC_LITERAL(6, 72, 7), // "channel"
QT_MOC_LITERAL(7, 80, 14), // "leackage_value"
QT_MOC_LITERAL(8, 95, 22), // "slot_ClearSerialNumber"
QT_MOC_LITERAL(9, 118, 18), // "slot_set_leakvalue"
QT_MOC_LITERAL(10, 137, 4), // "text"
QT_MOC_LITERAL(11, 142, 19), // "on_BTN_Save_clicked"
QT_MOC_LITERAL(12, 162, 25), // "on_BTN_HandPrinte_clicked"
QT_MOC_LITERAL(13, 188, 24), // "on_BTN_autoPrint_clicked"
QT_MOC_LITERAL(14, 213, 33), // "on_CBT_Channel_currentTextCha..."
QT_MOC_LITERAL(15, 247, 4), // "arg1"
QT_MOC_LITERAL(16, 252, 40), // "on_cbt_print_drive_ng_current..."
QT_MOC_LITERAL(17, 293, 37) // "on_cbt_print_drive_currentTex..."

    },
    "MForm_PrintSetting\0slot_printer\0\0path\0"
    "printer_name\0slot_Printe_Label_NG\0"
    "channel\0leackage_value\0slot_ClearSerialNumber\0"
    "slot_set_leakvalue\0text\0on_BTN_Save_clicked\0"
    "on_BTN_HandPrinte_clicked\0"
    "on_BTN_autoPrint_clicked\0"
    "on_CBT_Channel_currentTextChanged\0"
    "arg1\0on_cbt_print_drive_ng_currentTextChanged\0"
    "on_cbt_print_drive_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MForm_PrintSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a /* Public */,
       5,    2,   69,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      16,    1,   84,    2, 0x08 /* Private */,
      17,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void MForm_PrintSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MForm_PrintSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_printer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->slot_Printe_Label_NG((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slot_ClearSerialNumber(); break;
        case 3: _t->slot_set_leakvalue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_BTN_Save_clicked(); break;
        case 5: _t->on_BTN_HandPrinte_clicked(); break;
        case 6: _t->on_BTN_autoPrint_clicked(); break;
        case 7: _t->on_CBT_Channel_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_cbt_print_drive_ng_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_cbt_print_drive_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MForm_PrintSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MForm_PrintSetting.data,
    qt_meta_data_MForm_PrintSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MForm_PrintSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MForm_PrintSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MForm_PrintSetting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MForm_PrintSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'MForm_ScanCode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Honeywell/MForm_ScanCode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MForm_ScanCode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MForm_ScanCode_t {
    QByteArrayData data[20];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MForm_ScanCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MForm_ScanCode_t qt_meta_stringdata_MForm_ScanCode = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MForm_ScanCode"
QT_MOC_LITERAL(1, 15, 14), // "sign_GetNGCode"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "mesg"
QT_MOC_LITERAL(4, 36, 15), // "sign_WriteDatas"
QT_MOC_LITERAL(5, 52, 9), // "send_byte"
QT_MOC_LITERAL(6, 62, 20), // "sign_barcodeReceived"
QT_MOC_LITERAL(7, 83, 7), // "barcode"
QT_MOC_LITERAL(8, 91, 20), // "sign_scanWriteFailed"
QT_MOC_LITERAL(9, 112, 6), // "reason"
QT_MOC_LITERAL(10, 119, 13), // "slot_readRead"
QT_MOC_LITERAL(11, 133, 12), // "slot_readAll"
QT_MOC_LITERAL(12, 146, 15), // "slot_readRead_2"
QT_MOC_LITERAL(13, 162, 14), // "slot_readAll_2"
QT_MOC_LITERAL(14, 177, 15), // "slot_WriteDatas"
QT_MOC_LITERAL(15, 193, 19), // "on_Btn_Save_clicked"
QT_MOC_LITERAL(16, 213, 24), // "on_Btn_OpenClose_clicked"
QT_MOC_LITERAL(17, 238, 21), // "on_Btn_Update_clicked"
QT_MOC_LITERAL(18, 260, 26), // "on_Btn_OpenClose_2_clicked"
QT_MOC_LITERAL(19, 287, 23) // "on_Btn_Update_2_clicked"

    },
    "MForm_ScanCode\0sign_GetNGCode\0\0mesg\0"
    "sign_WriteDatas\0send_byte\0"
    "sign_barcodeReceived\0barcode\0"
    "sign_scanWriteFailed\0reason\0slot_readRead\0"
    "slot_readAll\0slot_readRead_2\0"
    "slot_readAll_2\0slot_WriteDatas\0"
    "on_Btn_Save_clicked\0on_Btn_OpenClose_clicked\0"
    "on_Btn_Update_clicked\0on_Btn_OpenClose_2_clicked\0"
    "on_Btn_Update_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MForm_ScanCode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   96,    2, 0x0a /* Public */,
      11,    0,   97,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MForm_ScanCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MForm_ScanCode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_GetNGCode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sign_WriteDatas((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->sign_barcodeReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sign_scanWriteFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slot_readRead(); break;
        case 5: _t->slot_readAll(); break;
        case 6: _t->slot_readRead_2(); break;
        case 7: _t->slot_readAll_2(); break;
        case 8: _t->slot_WriteDatas((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->on_Btn_Save_clicked(); break;
        case 10: _t->on_Btn_OpenClose_clicked(); break;
        case 11: _t->on_Btn_Update_clicked(); break;
        case 12: _t->on_Btn_OpenClose_2_clicked(); break;
        case 13: _t->on_Btn_Update_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MForm_ScanCode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ScanCode::sign_GetNGCode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MForm_ScanCode::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ScanCode::sign_WriteDatas)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MForm_ScanCode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ScanCode::sign_barcodeReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MForm_ScanCode::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ScanCode::sign_scanWriteFailed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MForm_ScanCode::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MForm_ScanCode.data,
    qt_meta_data_MForm_ScanCode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MForm_ScanCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MForm_ScanCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MForm_ScanCode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MForm_ScanCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MForm_ScanCode::sign_GetNGCode(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MForm_ScanCode::sign_WriteDatas(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MForm_ScanCode::sign_barcodeReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MForm_ScanCode::sign_scanWriteFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

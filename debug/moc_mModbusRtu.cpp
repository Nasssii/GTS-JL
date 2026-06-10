/****************************************************************************
** Meta object code from reading C++ file 'mModbusRtu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ModbusRtu/mModbusRtu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mModbusRtu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mModbusRtu_t {
    QByteArrayData data[23];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mModbusRtu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mModbusRtu_t qt_meta_stringdata_mModbusRtu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mModbusRtu"
QT_MOC_LITERAL(1, 11, 11), // "sign_setled"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "QLabel*"
QT_MOC_LITERAL(4, 32, 19), // "sign_setled_cicular"
QT_MOC_LITERAL(5, 52, 5), // "label"
QT_MOC_LITERAL(6, 58, 5), // "color"
QT_MOC_LITERAL(7, 64, 18), // "Sign_COMStyleSheet"
QT_MOC_LITERAL(8, 83, 4), // "name"
QT_MOC_LITERAL(9, 88, 7), // "b_value"
QT_MOC_LITERAL(10, 96, 23), // "slot_ReadDiscreteInputs"
QT_MOC_LITERAL(11, 120, 14), // "slot_ReadCoils"
QT_MOC_LITERAL(12, 135, 15), // "slot_WriteCoils"
QT_MOC_LITERAL(13, 151, 15), // "reConnectDevice"
QT_MOC_LITERAL(14, 167, 16), // "slot_OpCl_Device"
QT_MOC_LITERAL(15, 184, 3), // "com"
QT_MOC_LITERAL(16, 188, 7), // "baudBit"
QT_MOC_LITERAL(17, 196, 7), // "dataBit"
QT_MOC_LITERAL(18, 204, 8), // "stopBits"
QT_MOC_LITERAL(19, 213, 9), // "parityBit"
QT_MOC_LITERAL(20, 223, 23), // "slot_ReadInputRegisters"
QT_MOC_LITERAL(21, 247, 15), // "_WR_OnReadReady"
QT_MOC_LITERAL(22, 263, 15) // "_RD_OnReadReady"

    },
    "mModbusRtu\0sign_setled\0\0QLabel*\0"
    "sign_setled_cicular\0label\0color\0"
    "Sign_COMStyleSheet\0name\0b_value\0"
    "slot_ReadDiscreteInputs\0slot_ReadCoils\0"
    "slot_WriteCoils\0reConnectDevice\0"
    "slot_OpCl_Device\0com\0baudBit\0dataBit\0"
    "stopBits\0parityBit\0slot_ReadInputRegisters\0"
    "_WR_OnReadReady\0_RD_OnReadReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mModbusRtu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       4,    2,   76,    2, 0x06 /* Public */,
       7,    2,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    5,   90,    2, 0x0a /* Public */,
      20,    0,  101,    2, 0x0a /* Public */,
      21,    0,  102,    2, 0x08 /* Private */,
      22,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   15,   16,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mModbusRtu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mModbusRtu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_setled((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sign_setled_cicular((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->Sign_COMStyleSheet((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->slot_ReadDiscreteInputs(); break;
        case 4: _t->slot_ReadCoils(); break;
        case 5: _t->slot_WriteCoils(); break;
        case 6: _t->reConnectDevice(); break;
        case 7: _t->slot_OpCl_Device((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 8: _t->slot_ReadInputRegisters(); break;
        case 9: _t->_WR_OnReadReady(); break;
        case 10: _t->_RD_OnReadReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mModbusRtu::*)(QLabel * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mModbusRtu::sign_setled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mModbusRtu::*)(QLabel * , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mModbusRtu::sign_setled_cicular)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mModbusRtu::*)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mModbusRtu::Sign_COMStyleSheet)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mModbusRtu::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_mModbusRtu.data,
    qt_meta_data_mModbusRtu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mModbusRtu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mModbusRtu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mModbusRtu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mModbusRtu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void mModbusRtu::sign_setled(QLabel * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mModbusRtu::sign_setled_cicular(QLabel * _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mModbusRtu::Sign_COMStyleSheet(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'MForm_ModeBusRtu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ModbusRtu/MForm_ModeBusRtu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MForm_ModeBusRtu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MForm_ModeBusRtu_t {
    QByteArrayData data[24];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MForm_ModeBusRtu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MForm_ModeBusRtu_t qt_meta_stringdata_MForm_ModeBusRtu = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MForm_ModeBusRtu"
QT_MOC_LITERAL(1, 17, 23), // "sign_ReadDiscreteInputs"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 14), // "sign_ReadCoils"
QT_MOC_LITERAL(4, 57, 15), // "sign_WriteCoils"
QT_MOC_LITERAL(5, 73, 17), // "sign_WriteCoils_2"
QT_MOC_LITERAL(6, 91, 23), // "sign_ReadInputRegisters"
QT_MOC_LITERAL(7, 115, 18), // "sign_reConnect_Rtu"
QT_MOC_LITERAL(8, 134, 15), // "sign_OpenComBSM"
QT_MOC_LITERAL(9, 150, 3), // "com"
QT_MOC_LITERAL(10, 154, 7), // "baudBit"
QT_MOC_LITERAL(11, 162, 7), // "dataBit"
QT_MOC_LITERAL(12, 170, 8), // "stopBits"
QT_MOC_LITERAL(13, 179, 9), // "parityBit"
QT_MOC_LITERAL(14, 189, 13), // "Slot_AddBtnID"
QT_MOC_LITERAL(15, 203, 2), // "id"
QT_MOC_LITERAL(16, 206, 12), // "slot_Timeout"
QT_MOC_LITERAL(17, 219, 19), // "on_Btn_Save_clicked"
QT_MOC_LITERAL(18, 239, 25), // "on_Btn_Updata_Com_clicked"
QT_MOC_LITERAL(19, 265, 20), // "on_Btn_RS485_clicked"
QT_MOC_LITERAL(20, 286, 23), // "on_Btn_loadfile_clicked"
QT_MOC_LITERAL(21, 310, 22), // "on_Btn_board_1_toggled"
QT_MOC_LITERAL(22, 333, 7), // "checked"
QT_MOC_LITERAL(23, 341, 22) // "on_Btn_board_2_toggled"

    },
    "MForm_ModeBusRtu\0sign_ReadDiscreteInputs\0"
    "\0sign_ReadCoils\0sign_WriteCoils\0"
    "sign_WriteCoils_2\0sign_ReadInputRegisters\0"
    "sign_reConnect_Rtu\0sign_OpenComBSM\0"
    "com\0baudBit\0dataBit\0stopBits\0parityBit\0"
    "Slot_AddBtnID\0id\0slot_Timeout\0"
    "on_Btn_Save_clicked\0on_Btn_Updata_Com_clicked\0"
    "on_Btn_RS485_clicked\0on_Btn_loadfile_clicked\0"
    "on_Btn_board_1_toggled\0checked\0"
    "on_Btn_board_2_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MForm_ModeBusRtu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    5,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  106,    2, 0x0a /* Public */,
      16,    0,  109,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,
      21,    1,  114,    2, 0x08 /* Private */,
      23,    1,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    9,   10,   11,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,

       0        // eod
};

void MForm_ModeBusRtu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MForm_ModeBusRtu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_ReadDiscreteInputs(); break;
        case 1: _t->sign_ReadCoils(); break;
        case 2: _t->sign_WriteCoils(); break;
        case 3: _t->sign_WriteCoils_2(); break;
        case 4: _t->sign_ReadInputRegisters(); break;
        case 5: _t->sign_reConnect_Rtu(); break;
        case 6: _t->sign_OpenComBSM((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 7: _t->Slot_AddBtnID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_Timeout(); break;
        case 9: _t->on_Btn_Save_clicked(); break;
        case 10: _t->on_Btn_Updata_Com_clicked(); break;
        case 11: _t->on_Btn_RS485_clicked(); break;
        case 12: _t->on_Btn_loadfile_clicked(); break;
        case 13: _t->on_Btn_board_1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_Btn_board_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_ReadDiscreteInputs)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_ReadCoils)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_WriteCoils)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_WriteCoils_2)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_ReadInputRegisters)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_reConnect_Rtu)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MForm_ModeBusRtu::*)(QString , uint , uint , uint , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MForm_ModeBusRtu::sign_OpenComBSM)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MForm_ModeBusRtu::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MForm_ModeBusRtu.data,
    qt_meta_data_MForm_ModeBusRtu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MForm_ModeBusRtu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MForm_ModeBusRtu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MForm_ModeBusRtu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MForm_ModeBusRtu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MForm_ModeBusRtu::sign_ReadDiscreteInputs()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MForm_ModeBusRtu::sign_ReadCoils()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MForm_ModeBusRtu::sign_WriteCoils()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MForm_ModeBusRtu::sign_WriteCoils_2()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MForm_ModeBusRtu::sign_ReadInputRegisters()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MForm_ModeBusRtu::sign_reConnect_Rtu()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MForm_ModeBusRtu::sign_OpenComBSM(QString _t1, uint _t2, uint _t3, uint _t4, uint _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

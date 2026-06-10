/****************************************************************************
** Meta object code from reading C++ file 'MFormMysql.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MMYSQL/MFormMysql.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MFormMysql.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MFormMysql_t {
    QByteArrayData data[24];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MFormMysql_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MFormMysql_t qt_meta_stringdata_MFormMysql = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MFormMysql"
QT_MOC_LITERAL(1, 11, 19), // "sign_update_JLDatas"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "MST_MYSQL_Datas"
QT_MOC_LITERAL(4, 48, 9), // "mst_datas"
QT_MOC_LITERAL(5, 58, 26), // "sign_MYSQL_queryDatas_rfid"
QT_MOC_LITERAL(6, 85, 4), // "rfid"
QT_MOC_LITERAL(7, 90, 29), // "sign_MYSQL_updateRealQuantity"
QT_MOC_LITERAL(8, 120, 5), // "value"
QT_MOC_LITERAL(9, 126, 34), // "sign_MYSQL_updateRemainingQua..."
QT_MOC_LITERAL(10, 161, 36), // "sign_MYSQL_updateTheoreticalQ..."
QT_MOC_LITERAL(11, 198, 22), // "sign_MYSQL_model_query"
QT_MOC_LITERAL(12, 221, 9), // "queryKind"
QT_MOC_LITERAL(13, 231, 10), // "queryTable"
QT_MOC_LITERAL(14, 242, 10), // "queryInfos"
QT_MOC_LITERAL(15, 253, 7), // "allPage"
QT_MOC_LITERAL(16, 261, 10), // "pageOffset"
QT_MOC_LITERAL(17, 272, 21), // "slot_Display_OP_Datas"
QT_MOC_LITERAL(18, 294, 12), // "list_hlabels"
QT_MOC_LITERAL(19, 307, 10), // "list_datas"
QT_MOC_LITERAL(20, 318, 23), // "on_Btn_SavePars_clicked"
QT_MOC_LITERAL(21, 342, 26), // "on_BTN_query_datas_clicked"
QT_MOC_LITERAL(22, 369, 31), // "on_BTN_query_datas_Date_clicked"
QT_MOC_LITERAL(23, 401, 26) // "on_BTN_Export_Data_clicked"

    },
    "MFormMysql\0sign_update_JLDatas\0\0"
    "MST_MYSQL_Datas\0mst_datas\0"
    "sign_MYSQL_queryDatas_rfid\0rfid\0"
    "sign_MYSQL_updateRealQuantity\0value\0"
    "sign_MYSQL_updateRemainingQuantity\0"
    "sign_MYSQL_updateTheoreticalQuantity\0"
    "sign_MYSQL_model_query\0queryKind\0"
    "queryTable\0queryInfos\0allPage\0pageOffset\0"
    "slot_Display_OP_Datas\0list_hlabels\0"
    "list_datas\0on_Btn_SavePars_clicked\0"
    "on_BTN_query_datas_clicked\0"
    "on_BTN_query_datas_Date_clicked\0"
    "on_BTN_Export_Data_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MFormMysql[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       7,    1,   75,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,
      11,    5,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,   95,    2, 0x0a /* Public */,
      20,    0,  100,    2, 0x08 /* Private */,
      21,    0,  101,    2, 0x08 /* Private */,
      22,    0,  102,    2, 0x08 /* Private */,
      23,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList, QMetaType::UInt, QMetaType::UInt,   12,   13,   14,   15,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MFormMysql::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MFormMysql *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_update_JLDatas((*reinterpret_cast< MST_MYSQL_Datas(*)>(_a[1]))); break;
        case 1: _t->sign_MYSQL_queryDatas_rfid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sign_MYSQL_updateRealQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 3: _t->sign_MYSQL_updateRemainingQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 4: _t->sign_MYSQL_updateTheoreticalQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 5: _t->sign_MYSQL_model_query((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const uint(*)>(_a[4])),(*reinterpret_cast< const uint(*)>(_a[5]))); break;
        case 6: _t->slot_Display_OP_Datas((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 7: _t->on_Btn_SavePars_clicked(); break;
        case 8: _t->on_BTN_query_datas_clicked(); break;
        case 9: _t->on_BTN_query_datas_Date_clicked(); break;
        case 10: _t->on_BTN_Export_Data_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MFormMysql::*)(MST_MYSQL_Datas );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_update_JLDatas)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MFormMysql::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_MYSQL_queryDatas_rfid)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MFormMysql::*)(const uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_MYSQL_updateRealQuantity)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MFormMysql::*)(const uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_MYSQL_updateRemainingQuantity)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MFormMysql::*)(const uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_MYSQL_updateTheoreticalQuantity)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MFormMysql::*)(const QString , const QString , const QStringList , const uint , const uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MFormMysql::sign_MYSQL_model_query)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MFormMysql::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MFormMysql.data,
    qt_meta_data_MFormMysql,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MFormMysql::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MFormMysql::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MFormMysql.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MFormMysql::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MFormMysql::sign_update_JLDatas(MST_MYSQL_Datas _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MFormMysql::sign_MYSQL_queryDatas_rfid(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MFormMysql::sign_MYSQL_updateRealQuantity(const uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MFormMysql::sign_MYSQL_updateRemainingQuantity(const uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MFormMysql::sign_MYSQL_updateTheoreticalQuantity(const uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MFormMysql::sign_MYSQL_model_query(const QString _t1, const QString _t2, const QStringList _t3, const uint _t4, const uint _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_MMYSQLDatas_t {
    QByteArrayData data[33];
    char stringdata0[458];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MMYSQLDatas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MMYSQLDatas_t qt_meta_stringdata_MMYSQLDatas = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MMYSQLDatas"
QT_MOC_LITERAL(1, 12, 21), // "sign_Display_OP_Datas"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "list_hlabels"
QT_MOC_LITERAL(4, 48, 10), // "list_datas"
QT_MOC_LITERAL(5, 59, 11), // "sign_setled"
QT_MOC_LITERAL(6, 71, 7), // "QLabel*"
QT_MOC_LITERAL(7, 79, 5), // "label"
QT_MOC_LITERAL(8, 85, 5), // "color"
QT_MOC_LITERAL(9, 91, 17), // "sign_setled_Frame"
QT_MOC_LITERAL(10, 109, 7), // "QFrame*"
QT_MOC_LITERAL(11, 117, 19), // "sign_setled_cicular"
QT_MOC_LITERAL(12, 137, 9), // "sign_Tips"
QT_MOC_LITERAL(13, 147, 3), // "mes"
QT_MOC_LITERAL(14, 151, 8), // "color_id"
QT_MOC_LITERAL(15, 160, 15), // "sign_OEEDisplay"
QT_MOC_LITERAL(16, 176, 4), // "list"
QT_MOC_LITERAL(17, 181, 16), // "slot_searchDatas"
QT_MOC_LITERAL(18, 198, 36), // "slot_MYSQL_updateTheoreticalQ..."
QT_MOC_LITERAL(19, 235, 5), // "value"
QT_MOC_LITERAL(20, 241, 29), // "slot_MYSQL_updateRealQuantity"
QT_MOC_LITERAL(21, 271, 26), // "slot_MYSQL_queryDatas_rfid"
QT_MOC_LITERAL(22, 298, 4), // "rfid"
QT_MOC_LITERAL(23, 303, 34), // "slot_MYSQL_updateRemainingQua..."
QT_MOC_LITERAL(24, 338, 19), // "slot_update_JLDatas"
QT_MOC_LITERAL(25, 358, 15), // "MST_MYSQL_Datas"
QT_MOC_LITERAL(26, 374, 9), // "mst_datas"
QT_MOC_LITERAL(27, 384, 22), // "slot_MYSQL_model_query"
QT_MOC_LITERAL(28, 407, 9), // "queryKind"
QT_MOC_LITERAL(29, 417, 10), // "queryTable"
QT_MOC_LITERAL(30, 428, 10), // "queryInfos"
QT_MOC_LITERAL(31, 439, 7), // "allPage"
QT_MOC_LITERAL(32, 447, 10) // "pageOffset"

    },
    "MMYSQLDatas\0sign_Display_OP_Datas\0\0"
    "list_hlabels\0list_datas\0sign_setled\0"
    "QLabel*\0label\0color\0sign_setled_Frame\0"
    "QFrame*\0sign_setled_cicular\0sign_Tips\0"
    "mes\0color_id\0sign_OEEDisplay\0list\0"
    "slot_searchDatas\0slot_MYSQL_updateTheoreticalQuantity\0"
    "value\0slot_MYSQL_updateRealQuantity\0"
    "slot_MYSQL_queryDatas_rfid\0rfid\0"
    "slot_MYSQL_updateRemainingQuantity\0"
    "slot_update_JLDatas\0MST_MYSQL_Datas\0"
    "mst_datas\0slot_MYSQL_model_query\0"
    "queryKind\0queryTable\0queryInfos\0allPage\0"
    "pageOffset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MMYSQLDatas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       9,    2,   94,    2, 0x06 /* Public */,
      11,    2,   99,    2, 0x06 /* Public */,
      12,    2,  104,    2, 0x06 /* Public */,
      12,    1,  109,    2, 0x26 /* Public | MethodCloned */,
      15,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  115,    2, 0x0a /* Public */,
      18,    1,  116,    2, 0x0a /* Public */,
      20,    1,  119,    2, 0x0a /* Public */,
      21,    1,  122,    2, 0x0a /* Public */,
      23,    1,  125,    2, 0x0a /* Public */,
      24,    1,  128,    2, 0x0a /* Public */,
      27,    5,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UChar,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::UChar,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UChar,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::UChar,   13,   14,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QStringList,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   19,
    QMetaType::Void, QMetaType::UInt,   19,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::UInt,   19,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList, QMetaType::UInt, QMetaType::UInt,   28,   29,   30,   31,   32,

       0        // eod
};

void MMYSQLDatas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MMYSQLDatas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_Display_OP_Datas((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->sign_setled((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 2: _t->sign_setled_Frame((*reinterpret_cast< QFrame*(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 3: _t->sign_setled_cicular((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 4: _t->sign_Tips((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 5: _t->sign_Tips((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->sign_OEEDisplay((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 7: _t->slot_searchDatas(); break;
        case 8: _t->slot_MYSQL_updateTheoreticalQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 9: _t->slot_MYSQL_updateRealQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 10: _t->slot_MYSQL_queryDatas_rfid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->slot_MYSQL_updateRemainingQuantity((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 12: _t->slot_update_JLDatas((*reinterpret_cast< MST_MYSQL_Datas(*)>(_a[1]))); break;
        case 13: _t->slot_MYSQL_model_query((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const uint(*)>(_a[4])),(*reinterpret_cast< const uint(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFrame* >(); break;
            }
            break;
        case 3:
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
            using _t = void (MMYSQLDatas::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_Display_OP_Datas)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MMYSQLDatas::*)(QLabel * , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_setled)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MMYSQLDatas::*)(QFrame * , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_setled_Frame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MMYSQLDatas::*)(QLabel * , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_setled_cicular)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MMYSQLDatas::*)(const QString , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_Tips)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MMYSQLDatas::*)(const QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMYSQLDatas::sign_OEEDisplay)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MMYSQLDatas::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MMYSQLDatas.data,
    qt_meta_data_MMYSQLDatas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MMYSQLDatas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MMYSQLDatas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MMYSQLDatas.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MMYSQLDatas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MMYSQLDatas::sign_Display_OP_Datas(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MMYSQLDatas::sign_setled(QLabel * _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MMYSQLDatas::sign_setled_Frame(QFrame * _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MMYSQLDatas::sign_setled_cicular(QLabel * _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MMYSQLDatas::sign_Tips(const QString _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void MMYSQLDatas::sign_OEEDisplay(const QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

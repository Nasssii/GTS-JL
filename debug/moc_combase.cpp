/****************************************************************************
** Meta object code from reading C++ file 'combase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MATEQ/combase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mComThread_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mComThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mComThread_t qt_meta_stringdata_mComThread = {
    {
QT_MOC_LITERAL(0, 0, 10) // "mComThread"

    },
    "mComThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mComThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void mComThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mComThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_mComThread.data,
    qt_meta_data_mComThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mComThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mComThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mComThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mComThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_COMLeakHunting_t {
    QByteArrayData data[24];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_COMLeakHunting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_COMLeakHunting_t qt_meta_stringdata_COMLeakHunting = {
    {
QT_MOC_LITERAL(0, 0, 14), // "COMLeakHunting"
QT_MOC_LITERAL(1, 15, 11), // "Sign_Setled"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "QLabel*"
QT_MOC_LITERAL(4, 36, 5), // "label"
QT_MOC_LITERAL(5, 42, 5), // "color"
QT_MOC_LITERAL(6, 48, 19), // "sign_setled_cicular"
QT_MOC_LITERAL(7, 68, 9), // "sign_tips"
QT_MOC_LITERAL(8, 78, 4), // "mesg"
QT_MOC_LITERAL(9, 83, 7), // "colorid"
QT_MOC_LITERAL(10, 91, 18), // "Sign_COMStyleSheet"
QT_MOC_LITERAL(11, 110, 4), // "name"
QT_MOC_LITERAL(12, 115, 7), // "b_value"
QT_MOC_LITERAL(13, 123, 20), // "sign_MYSQL_Update_JL"
QT_MOC_LITERAL(14, 144, 6), // "p_rfid"
QT_MOC_LITERAL(15, 151, 4), // "p_en"
QT_MOC_LITERAL(16, 156, 7), // "p_datas"
QT_MOC_LITERAL(17, 164, 17), // "sign_ATEQ_Display"
QT_MOC_LITERAL(18, 182, 6), // "device"
QT_MOC_LITERAL(19, 189, 8), // "pressure"
QT_MOC_LITERAL(20, 198, 7), // "leakage"
QT_MOC_LITERAL(21, 206, 11), // "Init_Port_1"
QT_MOC_LITERAL(22, 218, 10), // "ReadData_1"
QT_MOC_LITERAL(23, 229, 12) // "ReadFinish_1"

    },
    "COMLeakHunting\0Sign_Setled\0\0QLabel*\0"
    "label\0color\0sign_setled_cicular\0"
    "sign_tips\0mesg\0colorid\0Sign_COMStyleSheet\0"
    "name\0b_value\0sign_MYSQL_Update_JL\0"
    "p_rfid\0p_en\0p_datas\0sign_ATEQ_Display\0"
    "device\0pressure\0leakage\0Init_Port_1\0"
    "ReadData_1\0ReadFinish_1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_COMLeakHunting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,
      10,    2,   74,    2, 0x06 /* Public */,
      13,    3,   79,    2, 0x06 /* Public */,
      17,    3,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,   93,    2, 0x0a /* Public */,
      22,    0,   94,    2, 0x0a /* Public */,
      23,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UChar,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   18,   19,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void COMLeakHunting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<COMLeakHunting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sign_Setled((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->sign_setled_cicular((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->sign_tips((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 3: _t->Sign_COMStyleSheet((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->sign_MYSQL_Update_JL((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->sign_ATEQ_Display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->Init_Port_1(); break;
        case 7: _t->ReadData_1(); break;
        case 8: _t->ReadFinish_1(); break;
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
            using _t = void (COMLeakHunting::*)(QLabel * , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::Sign_Setled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting::*)(QLabel * , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::sign_setled_cicular)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting::*)(const QString & , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::sign_tips)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting::*)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::Sign_COMStyleSheet)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting::*)(const QString , const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::sign_MYSQL_Update_JL)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting::*)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting::sign_ATEQ_Display)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject COMLeakHunting::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_COMLeakHunting.data,
    qt_meta_data_COMLeakHunting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *COMLeakHunting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *COMLeakHunting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_COMLeakHunting.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int COMLeakHunting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void COMLeakHunting::Sign_Setled(QLabel * _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void COMLeakHunting::sign_setled_cicular(QLabel * _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void COMLeakHunting::sign_tips(const QString & _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void COMLeakHunting::Sign_COMStyleSheet(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void COMLeakHunting::sign_MYSQL_Update_JL(const QString _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void COMLeakHunting::sign_ATEQ_Display(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_COMLeakHunting_2_t {
    QByteArrayData data[24];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_COMLeakHunting_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_COMLeakHunting_2_t qt_meta_stringdata_COMLeakHunting_2 = {
    {
QT_MOC_LITERAL(0, 0, 16), // "COMLeakHunting_2"
QT_MOC_LITERAL(1, 17, 11), // "Sign_Setled"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "QLabel*"
QT_MOC_LITERAL(4, 38, 5), // "label"
QT_MOC_LITERAL(5, 44, 5), // "color"
QT_MOC_LITERAL(6, 50, 19), // "sign_setled_cicular"
QT_MOC_LITERAL(7, 70, 9), // "sign_tips"
QT_MOC_LITERAL(8, 80, 4), // "mesg"
QT_MOC_LITERAL(9, 85, 7), // "colorid"
QT_MOC_LITERAL(10, 93, 18), // "Sign_COMStyleSheet"
QT_MOC_LITERAL(11, 112, 4), // "name"
QT_MOC_LITERAL(12, 117, 7), // "b_value"
QT_MOC_LITERAL(13, 125, 20), // "sign_MYSQL_Update_JL"
QT_MOC_LITERAL(14, 146, 6), // "p_rfid"
QT_MOC_LITERAL(15, 153, 4), // "p_en"
QT_MOC_LITERAL(16, 158, 7), // "p_datas"
QT_MOC_LITERAL(17, 166, 17), // "sign_ATEQ_Display"
QT_MOC_LITERAL(18, 184, 6), // "device"
QT_MOC_LITERAL(19, 191, 8), // "pressure"
QT_MOC_LITERAL(20, 200, 7), // "leakage"
QT_MOC_LITERAL(21, 208, 11), // "Init_Port_2"
QT_MOC_LITERAL(22, 220, 10), // "ReadData_2"
QT_MOC_LITERAL(23, 231, 12) // "ReadFinish_2"

    },
    "COMLeakHunting_2\0Sign_Setled\0\0QLabel*\0"
    "label\0color\0sign_setled_cicular\0"
    "sign_tips\0mesg\0colorid\0Sign_COMStyleSheet\0"
    "name\0b_value\0sign_MYSQL_Update_JL\0"
    "p_rfid\0p_en\0p_datas\0sign_ATEQ_Display\0"
    "device\0pressure\0leakage\0Init_Port_2\0"
    "ReadData_2\0ReadFinish_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_COMLeakHunting_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,
      10,    2,   74,    2, 0x06 /* Public */,
      13,    3,   79,    2, 0x06 /* Public */,
      17,    3,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,   93,    2, 0x0a /* Public */,
      22,    0,   94,    2, 0x0a /* Public */,
      23,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UChar,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   18,   19,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void COMLeakHunting_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<COMLeakHunting_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sign_Setled((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->sign_setled_cicular((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->sign_tips((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const uchar(*)>(_a[2]))); break;
        case 3: _t->Sign_COMStyleSheet((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->sign_MYSQL_Update_JL((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->sign_ATEQ_Display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->Init_Port_2(); break;
        case 7: _t->ReadData_2(); break;
        case 8: _t->ReadFinish_2(); break;
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
            using _t = void (COMLeakHunting_2::*)(QLabel * , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::Sign_Setled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting_2::*)(QLabel * , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::sign_setled_cicular)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting_2::*)(const QString & , const uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::sign_tips)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting_2::*)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::Sign_COMStyleSheet)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting_2::*)(const QString , const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::sign_MYSQL_Update_JL)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (COMLeakHunting_2::*)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&COMLeakHunting_2::sign_ATEQ_Display)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject COMLeakHunting_2::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_COMLeakHunting_2.data,
    qt_meta_data_COMLeakHunting_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *COMLeakHunting_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *COMLeakHunting_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_COMLeakHunting_2.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int COMLeakHunting_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void COMLeakHunting_2::Sign_Setled(QLabel * _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void COMLeakHunting_2::sign_setled_cicular(QLabel * _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void COMLeakHunting_2::sign_tips(const QString & _t1, const uchar _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void COMLeakHunting_2::Sign_COMStyleSheet(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void COMLeakHunting_2::sign_MYSQL_Update_JL(const QString _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void COMLeakHunting_2::sign_ATEQ_Display(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

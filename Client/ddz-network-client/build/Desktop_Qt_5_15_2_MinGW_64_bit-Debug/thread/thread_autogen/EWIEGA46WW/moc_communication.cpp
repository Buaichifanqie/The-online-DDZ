/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../thread/communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communication_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_t qt_meta_stringdata_Communication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Communication"
QT_MOC_LITERAL(1, 14, 13), // "connectFailed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "loginOk"
QT_MOC_LITERAL(4, 37, 10), // "registerOk"
QT_MOC_LITERAL(5, 48, 9), // "failedMsg"
QT_MOC_LITERAL(6, 58, 3), // "msg"
QT_MOC_LITERAL(7, 62, 11), // "playerCount"
QT_MOC_LITERAL(8, 74, 6), // "number"
QT_MOC_LITERAL(9, 81, 9) // "startGame"

    },
    "Communication\0connectFailed\0\0loginOk\0"
    "registerOk\0failedMsg\0msg\0playerCount\0"
    "number\0startGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QByteArray,    6,

       0        // eod
};

void Communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectFailed(); break;
        case 1: _t->loginOk(); break;
        case 2: _t->registerOk(); break;
        case 3: _t->failedMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->playerCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->startGame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Communication::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::connectFailed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Communication::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::loginOk)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Communication::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::registerOk)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Communication::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::failedMsg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Communication::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::playerCount)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Communication::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::startGame)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Communication::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Communication.data,
    qt_meta_data_Communication,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Communication.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int Communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Communication::connectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Communication::loginOk()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Communication::registerOk()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Communication::failedMsg(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communication::playerCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communication::startGame(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

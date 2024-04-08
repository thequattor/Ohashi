/****************************************************************************
** Meta object code from reading C++ file 'tcp_server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tcp_server.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASStcp_serverENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASStcp_serverENDCLASS = QtMocHelpers::stringData(
    "tcp_server",
    "user_client_connected_0",
    "",
    "user_client_connected_1",
    "send_to_remote_server",
    "QByteArray&",
    "msg",
    "client_closed_the_connection",
    "on_new_connection",
    "on_closed_connection_0",
    "on_ready_read_0",
    "on_closed_connection_1",
    "on_ready_read_1",
    "on_recv_from_remote_server",
    "on_server_closed_the_connection"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASStcp_serverENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    1,   82,    2, 0x06,    3 /* Public */,
       7,    0,   85,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   86,    2, 0x08,    6 /* Private */,
       9,    0,   87,    2, 0x08,    7 /* Private */,
      10,    0,   88,    2, 0x08,    8 /* Private */,
      11,    0,   89,    2, 0x08,    9 /* Private */,
      12,    0,   90,    2, 0x08,   10 /* Private */,
      13,    1,   91,    2, 0x08,   11 /* Private */,
      14,    0,   94,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject tcp_server::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASStcp_serverENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASStcp_serverENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASStcp_serverENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<tcp_server, std::true_type>,
        // method 'user_client_connected_0'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'user_client_connected_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_to_remote_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>,
        // method 'client_closed_the_connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_new_connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_closed_connection_0'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ready_read_0'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_closed_connection_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ready_read_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recv_from_remote_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>,
        // method 'on_server_closed_the_connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void tcp_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tcp_server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->user_client_connected_0(); break;
        case 1: _t->user_client_connected_1(); break;
        case 2: _t->send_to_remote_server((*reinterpret_cast< std::add_pointer_t<QByteArray&>>(_a[1]))); break;
        case 3: _t->client_closed_the_connection(); break;
        case 4: _t->on_new_connection(); break;
        case 5: _t->on_closed_connection_0(); break;
        case 6: _t->on_ready_read_0(); break;
        case 7: _t->on_closed_connection_1(); break;
        case 8: _t->on_ready_read_1(); break;
        case 9: _t->on_recv_from_remote_server((*reinterpret_cast< std::add_pointer_t<QByteArray&>>(_a[1]))); break;
        case 10: _t->on_server_closed_the_connection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tcp_server::*)();
            if (_t _q_method = &tcp_server::user_client_connected_0; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tcp_server::*)();
            if (_t _q_method = &tcp_server::user_client_connected_1; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (tcp_server::*)(QByteArray & );
            if (_t _q_method = &tcp_server::send_to_remote_server; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (tcp_server::*)();
            if (_t _q_method = &tcp_server::client_closed_the_connection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *tcp_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcp_server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASStcp_serverENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tcp_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void tcp_server::user_client_connected_0()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void tcp_server::user_client_connected_1()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tcp_server::send_to_remote_server(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tcp_server::client_closed_the_connection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'traymenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../traymenu/traymenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traymenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrayMenu_t {
    QByteArrayData data[15];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrayMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrayMenu_t qt_meta_stringdata_TrayMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TrayMenu"
QT_MOC_LITERAL(1, 9, 22), // "signalIsShowMainWindow"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "isOk"
QT_MOC_LITERAL(4, 38, 24), // "signalIsTransparentMouse"
QT_MOC_LITERAL(5, 63, 12), // "signalIsQuit"
QT_MOC_LITERAL(6, 76, 16), // "signalIsIncrease"
QT_MOC_LITERAL(7, 93, 3), // "str"
QT_MOC_LITERAL(8, 97, 12), // "signalUpdate"
QT_MOC_LITERAL(9, 110, 15), // "actionClickShow"
QT_MOC_LITERAL(10, 126, 27), // "actionClickTransparentMouse"
QT_MOC_LITERAL(11, 154, 19), // "actionClickPlayList"
QT_MOC_LITERAL(12, 174, 17), // "actionClickUpdate"
QT_MOC_LITERAL(13, 192, 20), // "actionClickUpdateApp"
QT_MOC_LITERAL(14, 213, 15) // "actionClickQuit"

    },
    "TrayMenu\0signalIsShowMainWindow\0\0isOk\0"
    "signalIsTransparentMouse\0signalIsQuit\0"
    "signalIsIncrease\0str\0signalUpdate\0"
    "actionClickShow\0actionClickTransparentMouse\0"
    "actionClickPlayList\0actionClickUpdate\0"
    "actionClickUpdateApp\0actionClickQuit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrayMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    0,   75,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      12,    1,   91,    2, 0x0a /* Public */,
      13,    1,   94,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void TrayMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrayMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalIsShowMainWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signalIsTransparentMouse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signalIsQuit(); break;
        case 3: _t->signalIsIncrease((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signalUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->actionClickShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->actionClickTransparentMouse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->actionClickPlayList((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->actionClickUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->actionClickUpdateApp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->actionClickQuit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrayMenu::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrayMenu::signalIsShowMainWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrayMenu::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrayMenu::signalIsTransparentMouse)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrayMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrayMenu::signalIsQuit)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TrayMenu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrayMenu::signalIsIncrease)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TrayMenu::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrayMenu::signalUpdate)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrayMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_TrayMenu.data,
    qt_meta_data_TrayMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TrayMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrayMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrayMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int TrayMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
void TrayMenu::signalIsShowMainWindow(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrayMenu::signalIsTransparentMouse(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrayMenu::signalIsQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TrayMenu::signalIsIncrease(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TrayMenu::signalUpdate(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

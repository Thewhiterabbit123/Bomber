/****************************************************************************
** Meta object code from reading C++ file 'graphicsactor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/game/person/graphicsactor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsactor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicsActor_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsActor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsActor_t qt_meta_stringdata_GraphicsActor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GraphicsActor"
QT_MOC_LITERAL(1, 14, 10), // "processKey"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "ActorActions"
QT_MOC_LITERAL(4, 39, 3), // "key"
QT_MOC_LITERAL(5, 43, 10), // "setSprites"
QT_MOC_LITERAL(6, 54, 7), // "sprites"
QT_MOC_LITERAL(7, 62, 5), // "force"
QT_MOC_LITERAL(8, 68, 19) // "onAnimationFinished"

    },
    "GraphicsActor\0processKey\0\0ActorActions\0"
    "key\0setSprites\0sprites\0force\0"
    "onAnimationFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsActor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,

       0        // eod
};

void GraphicsActor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsActor *_t = static_cast<GraphicsActor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processKey((*reinterpret_cast< ActorActions(*)>(_a[1]))); break;
        case 1: _t->setSprites((*reinterpret_cast< ActorActions(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->setSprites((*reinterpret_cast< ActorActions(*)>(_a[1]))); break;
        case 3: _t->onAnimationFinished(); break;
        default: ;
        }
    }
}

const QMetaObject GraphicsActor::staticMetaObject = {
    { &AnimatedGraphicsItem::staticMetaObject, qt_meta_stringdata_GraphicsActor.data,
      qt_meta_data_GraphicsActor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphicsActor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsActor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsActor.stringdata0))
        return static_cast<void*>(const_cast< GraphicsActor*>(this));
    return AnimatedGraphicsItem::qt_metacast(_clname);
}

int GraphicsActor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AnimatedGraphicsItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

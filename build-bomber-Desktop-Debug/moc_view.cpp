/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/game/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_View_t {
    QByteArrayData data[23];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 0, 4), // "View"
QT_MOC_LITERAL(1, 5, 12), // "clientAction"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "action"
QT_MOC_LITERAL(4, 26, 13), // "keyPressEvent"
QT_MOC_LITERAL(5, 40, 10), // "QKeyEvent*"
QT_MOC_LITERAL(6, 51, 5), // "event"
QT_MOC_LITERAL(7, 57, 6), // "setMap"
QT_MOC_LITERAL(8, 64, 21), // "std::vector<ImageBox>"
QT_MOC_LITERAL(9, 86, 3), // "map"
QT_MOC_LITERAL(10, 90, 17), // "std::map<int,int>"
QT_MOC_LITERAL(11, 108, 9), // "playerPos"
QT_MOC_LITERAL(12, 118, 25), // "std::map<std::string,int>"
QT_MOC_LITERAL(13, 144, 6), // "player"
QT_MOC_LITERAL(14, 151, 14), // "playerMoveSlot"
QT_MOC_LITERAL(15, 166, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(16, 185, 7), // "setBomb"
QT_MOC_LITERAL(17, 193, 2), // "id"
QT_MOC_LITERAL(18, 196, 5), // "coord"
QT_MOC_LITERAL(19, 202, 9), // "playerDie"
QT_MOC_LITERAL(20, 212, 8), // "idPlayer"
QT_MOC_LITERAL(21, 221, 11), // "bombExplode"
QT_MOC_LITERAL(22, 233, 6) // "idBomb"

    },
    "View\0clientAction\0\0action\0keyPressEvent\0"
    "QKeyEvent*\0event\0setMap\0std::vector<ImageBox>\0"
    "map\0std::map<int,int>\0playerPos\0"
    "std::map<std::string,int>\0player\0"
    "playerMoveSlot\0std::pair<int,int>\0"
    "setBomb\0id\0coord\0playerDie\0idPlayer\0"
    "bombExplode\0idBomb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x09 /* Protected */,
       7,    3,   55,    2, 0x0a /* Public */,
      14,    1,   62,    2, 0x0a /* Public */,
      16,    2,   65,    2, 0x0a /* Public */,
      19,    1,   70,    2, 0x0a /* Public */,
      21,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12,    9,   11,   13,
    QMetaType::Void, 0x80000000 | 15,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        View *_t = static_cast<View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->setMap((*reinterpret_cast< std::vector<ImageBox>(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2])),(*reinterpret_cast< std::map<std::string,int>(*)>(_a[3]))); break;
        case 3: _t->playerMoveSlot((*reinterpret_cast< std::pair<int,int>(*)>(_a[1]))); break;
        case 4: _t->setBomb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->playerDie((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->bombExplode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (View::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&View::clientAction)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject View::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_View.data,
      qt_meta_data_View,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(const_cast< View*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void View::clientAction(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

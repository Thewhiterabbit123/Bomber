/****************************************************************************
** Meta object code from reading C++ file 'Game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/connection/client/Game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[25];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 9), // "startGame"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 21), // "std::vector<ImageBox>"
QT_MOC_LITERAL(4, 38, 3), // "map"
QT_MOC_LITERAL(5, 42, 17), // "std::map<int,int>"
QT_MOC_LITERAL(6, 60, 9), // "playerPos"
QT_MOC_LITERAL(7, 70, 25), // "std::map<std::string,int>"
QT_MOC_LITERAL(8, 96, 6), // "player"
QT_MOC_LITERAL(9, 103, 10), // "playerMove"
QT_MOC_LITERAL(10, 114, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(11, 133, 5), // "event"
QT_MOC_LITERAL(12, 139, 7), // "setBomb"
QT_MOC_LITERAL(13, 147, 2), // "id"
QT_MOC_LITERAL(14, 150, 3), // "pos"
QT_MOC_LITERAL(15, 154, 9), // "playerDie"
QT_MOC_LITERAL(16, 164, 8), // "idPlayer"
QT_MOC_LITERAL(17, 173, 10), // "explodeBox"
QT_MOC_LITERAL(18, 184, 11), // "bombExplode"
QT_MOC_LITERAL(19, 196, 6), // "idBomb"
QT_MOC_LITERAL(20, 203, 8), // "gameOver"
QT_MOC_LITERAL(21, 212, 11), // "std::string"
QT_MOC_LITERAL(22, 224, 8), // "nickname"
QT_MOC_LITERAL(23, 233, 10), // "getMessage"
QT_MOC_LITERAL(24, 244, 12) // "buttonAction"

    },
    "Game\0startGame\0\0std::vector<ImageBox>\0"
    "map\0std::map<int,int>\0playerPos\0"
    "std::map<std::string,int>\0player\0"
    "playerMove\0std::pair<int,int>\0event\0"
    "setBomb\0id\0pos\0playerDie\0idPlayer\0"
    "explodeBox\0bombExplode\0idBomb\0gameOver\0"
    "std::string\0nickname\0getMessage\0"
    "buttonAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       9,    1,   66,    2, 0x06 /* Public */,
      12,    2,   69,    2, 0x06 /* Public */,
      15,    1,   74,    2, 0x06 /* Public */,
      17,    1,   77,    2, 0x06 /* Public */,
      18,    1,   80,    2, 0x06 /* Public */,
      20,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,   86,    2, 0x0a /* Public */,
      24,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, 0x80000000 | 21,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startGame((*reinterpret_cast< std::vector<ImageBox>(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2])),(*reinterpret_cast< std::map<std::string,int>(*)>(_a[3]))); break;
        case 1: _t->playerMove((*reinterpret_cast< std::pair<int,int>(*)>(_a[1]))); break;
        case 2: _t->setBomb((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->playerDie((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->explodeBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->bombExplode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->gameOver((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->getMessage(); break;
        case 8: _t->buttonAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game::*_t)(std::vector<ImageBox> , std::map<int,int> , std::map<std::string,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::startGame)) {
                *result = 0;
            }
        }
        {
            typedef void (Game::*_t)(std::pair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::playerMove)) {
                *result = 1;
            }
        }
        {
            typedef void (Game::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::setBomb)) {
                *result = 2;
            }
        }
        {
            typedef void (Game::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::playerDie)) {
                *result = 3;
            }
        }
        {
            typedef void (Game::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::explodeBox)) {
                *result = 4;
            }
        }
        {
            typedef void (Game::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::bombExplode)) {
                *result = 5;
            }
        }
        {
            typedef void (Game::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::gameOver)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(const_cast< Game*>(this));
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Game::startGame(std::vector<ImageBox> _t1, std::map<int,int> _t2, std::map<std::string,int> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::playerMove(std::pair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Game::setBomb(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Game::playerDie(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Game::explodeBox(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Game::bombExplode(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Game::gameOver(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

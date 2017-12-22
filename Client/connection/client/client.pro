QT -= network
QT += core
QT -= gui

TARGET = client
CONFIG += console
CONFIG -= app_bundle

CONFIG += c++11

TEMPLATE = app

INCLUDEPATH += "/usr/include"

LIBS += \
       -lboost_system\

SOURCES += \
    Client.cc \
    Parser.cpp \
    Game.cpp \
    main.cpp

HEADERS += \
    Client.h \
    Game.h \
    Header.h \
    Parser.h

DISTFILES += \
    client.pro.user




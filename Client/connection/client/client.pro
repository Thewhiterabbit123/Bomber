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
    main.cpp \
    Client.cc \
    Parser.cpp

HEADERS += \
    Client.h \
    Parse.h \
    Position.h

DISTFILES += \
    client.pro.user



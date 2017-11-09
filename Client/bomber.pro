#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T15:52:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bomber
TEMPLATE = app


SOURCES += main.cpp \
    bombergame.cpp \
    game/gameWidget.cpp \
    menu/menuWidget.cpp

HEADERS  += \
    bombergame.h \
    game/gameWidget.h \
    menu/menuWidget.h

FORMS    +=

#unix|win32: LIBS += -lshell32

RESOURCES +=

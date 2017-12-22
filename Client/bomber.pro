#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T15:52:28
#
#-------------------------------------------------

QT       += core gui widgets


CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bomber
TEMPLATE = app


SOURCES += main.cpp \
    bombergame.cpp \
    game/gameWidget.cpp \
    menu/menuWidget.cpp \
    game/person/animatedgraphicsitem.cpp \
    game/person/graphicsactor.cpp \
    game/view.cpp \
    game/person/bombactor.cpp

HEADERS  += \
    bombergame.h \
    game/gameWidget.h \
    menu/menuWidget.h \
    game/box/boxwidget.h \
    shared/imagePool/imagepool.h \
    game/box/imagebox.h \
    game/person/animations_enum.h \
    shared/animationPool/animationpool.h \
    singleton.h \
    game/person/animatedgraphicsitem.h \
    game/person/graphicsactor.h \
    game/view.h \
    game/person/bombactor.h

FORMS    += \
    menuwidgetui.ui \
    gamewidgetui.ui

#unix|win32: LIBS += -lshell32

RESOURCES += \
    qgameres.qrc \
    resources.qrc

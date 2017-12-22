#ifndef APPTHREAD_H
#define APPTHREAD_H

#include <QtGui>
#include <QApplication>
#include "bombergame.h"


class AppThread: public QThread {
public:
    virtual void run(){
        int zatknis = 0;
        QApplication a(zatknis, nullptr);
        BomberGame gameui;
        gameui.initGame();
        gameui.show();
        a.exec();
        return ;
    }
};

#endif // APPTHREAD_H

#include <QApplication>
#include <QThread>
#include <iostream>
#include "connection/client/Game.h"
#include "bombergame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BomberGame gameUI;
    gameUI.show();

    return a.exec();
}

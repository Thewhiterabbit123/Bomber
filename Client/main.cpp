#include <QApplication>
#include <QThread>
#include "bombergame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BomberGame game;

    QApplication::processEvents();
    QThread dmasta, nadya;
    game.moveToThread(&dmasta);
    game.show();
    //dmasta.run();
    return a.exec();
}

#include <QApplication>
#include "bombergame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BomberGame game;
    game.show();
    QApplication::processEvents();
    return a.exec();
}

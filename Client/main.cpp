#include <QApplication>
#include <QThread>
#include <iostream>
#include "connection/client/Game.h"
#include "appthread.h"

int main(int argc, char *argv[])
{

    Game gameNetwork;
    //QApplication::processEvents();
    QThread network;
    AppThread ui;
    ui.start();
    network.start();
    gameNetwork.moveToThread(&network);
    //gameNetwork.play();
    while( ui.isRunning() ) {
            //sleep( 1 );
        }
    std::cout << "here";
    //a.exec();
    //dmasta.run();
    return 0;
}

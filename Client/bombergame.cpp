#include "bombergame.h"
#include "iostream"

BomberGame::BomberGame(QWidget* parent): QGraphicsView(parent)
{
    allScreens = new QStackedLayout();
    std::cerr<< "menu widget" << std::endl;
    menu = new MenuWidget();
    std::cerr<< "game widget" << std::endl;
    game = new GameWidget();
    allScreens -> addWidget(menu);
    allScreens -> addWidget(game);
    setLayout(allScreens);


    connect(menu, SIGNAL(setScreen(int)), allScreens, SLOT(setCurrentIndex(int)));
    connect(game, SIGNAL(setScreen(int)), allScreens, SLOT(setCurrentIndex(int)));

}

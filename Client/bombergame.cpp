#include "bombergame.h"
#include "iostream"

BomberGame::BomberGame(QWidget* parent): QGraphicsView(parent){
    gameNetwork = new Game;
    initGame();
}

void BomberGame::initGame(){
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
    connect(menu, SIGNAL(setScreen(int)), this, SLOT(startNetworking()));

}

void BomberGame::startNetworking(){
    std::string nickName = menu->menuUi->nickNameLineEdit->text().toStdString();
    gameNetwork->play(nickName);
    connect(gameNetwork, SIGNAL(startGame(std::vector<ImageBox>,std::map<int,int>,std::map<std::string,int>)),
            game, SLOT(setMap(std::vector<ImageBox>,std::map<int,int>,std::map<std::string,int>)));
    connect(gameNetwork, SIGNAL(startGame(std::vector<ImageBox>,std::map<int,int>,std::map<std::string,int>)),
            game->view, SLOT(setMap(std::vector<ImageBox>,std::map<int,int>,std::map<std::string,int>)));
}

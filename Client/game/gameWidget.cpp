#include "gameWidget.h"

GameWidget::GameWidget(QWidget* parent): QWidget(parent), gameUi(new Ui::game()){

    gameUi->setupUi(this);

    connect(gameUi->goToMenuButton, SIGNAL(clicked(bool)), this, SLOT(menuScreen()));
}


void GameWidget::menuScreen(){
    emit setScreen(0); // go to menu screen
}

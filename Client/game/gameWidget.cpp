#include "gameWidget.h"

GameWidget::GameWidget(QWidget* parent): QWidget(parent){
    setFixedSize(800, 600);
    gameLayout = new QVBoxLayout();
    backButton = new QPushButton("Back");
    gameLayout -> addWidget(backButton);
    setLayout(gameLayout);

    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(menuScreen()));

}


void GameWidget::menuScreen(){
    emit setScreen(0); // go to menu screen
}

#include "menuWidget.h"

MenuWidget::MenuWidget(QWidget* parent): QWidget(parent){
    setFixedSize(800, 600);
    //setStyleSheet("background-image: url(:/images/mysteryboom2.jpg)");
    menuLayout = new QVBoxLayout();
    //menuLayout->SetFixedSize(50, 100);
    goToGameButton = new QPushButton("Search game");
    quitButton = new QPushButton("Quit");
    menuLayout -> addWidget(goToGameButton);
    menuLayout -> addWidget(quitButton);
    setLayout(menuLayout);

    connect(goToGameButton, SIGNAL(clicked(bool)), this, SLOT(gameScreen()));
    connect(quitButton, SIGNAL(clicked(bool)), this, SLOT(quitAll()));
}

void MenuWidget::gameScreen(){
    emit setScreen(1); // go to game screen
}

void MenuWidget::quitAll(){
    exit(0);
}

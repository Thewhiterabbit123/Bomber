#include "menuWidget.h"



MenuWidget::MenuWidget(QWidget* parent): QWidget(parent), menuUi(new Ui::menu()){
    //setFixedSize(800, 600);
    menuUi->setupUi(this);

    connect(menuUi->goToGameButton, SIGNAL(clicked(bool)), this, SLOT(gameScreen()));
    connect(menuUi->quitButton, SIGNAL(clicked(bool)), this, SLOT(quitAll()));
}

void MenuWidget::gameScreen(){
    std::string nickName = menuUi->nickNameLineEdit->text().toStdString();
    //startServer(nickName);
    emit setScreen(1); // go to game screen
}

void MenuWidget::quitAll(){
    exit(0);
}

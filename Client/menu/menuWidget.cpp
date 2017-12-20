#include "menuWidget.h"



MenuWidget::MenuWidget(QWidget* parent): QWidget(parent), menuUi(new Ui::menu()){
    //setFixedSize(800, 600);
    menuUi->setupUi(this);
/*
    QPalette*  menuPalette   = new QPalette();
    QPixmap* menuPixmap = new QPixmap(":/images/background.png");
    QBrush*   menuBrush    = new QBrush(*menuPixmap);
    menuPalette->setBrush(QPalette::Background, *menuBrush);
    setAutoFillBackground(true);
    setPalette(*menuPalette);*/

    //setStyleSheet("background-color: red ;");
    //setAutoFillBackground(true);
/*
    menuLayout = new QGridLayout();

    goToGameButton = new QPushButton();
    QPixmap* goToGamePixmap = new QPixmap(":/images/nameEnter.png");
    goToGameButton->setFixedSize(goToGamePixmap -> size());
    goToGameButton->setStyleSheet("QPushButton{ background-image: url(:/images/nameEnter.png); border: none; background-repeat: no-repeat }");
    quitButton = new QPushButton();
    QPixmap* quitPixmap = new QPixmap(":/images/exit.png");
    quitButton->setFixedSize(quitPixmap -> size());
    quitButton -> setStyleSheet("QPushButton{ background-image: url(:/images/exit.png); background-position: center; border: none; background-repeat: no-repeat }");


    menuLayout -> addWidget(goToGameButton, 2, 1);
    menuLayout -> addWidget(quitButton, 0, 0);

    setLayout(menuLayout);

    connect(goToGameButton, SIGNAL(clicked(bool)), this, SLOT(gameScreen()));
    connect(quitButton, SIGNAL(clicked(bool)), this, SLOT(quitAll()));

    */
    connect(menuUi->goToGameButton, SIGNAL(clicked(bool)), this, SLOT(gameScreen()));
    connect(menuUi->quitButton, SIGNAL(clicked(bool)), this, SLOT(quitAll()));
}

void MenuWidget::gameScreen(){
    emit setScreen(1); // go to game screen
}

void MenuWidget::quitAll(){
    exit(0);
}

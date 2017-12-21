#include "gameWidget.h"
#include "game/box/boxwidget.h"
#include "game/box/imagebox.h"
#include "shared/imagePool/imagepool.h"
#include <memory>
#include <QTextEdit>
#include <QGridLayout>
#include <iostream>

GameWidget::GameWidget(QWidget* parent): QWidget(parent), gameUi(new Ui::game()){

    std::cerr << "before ui" << std::endl;
    gameUi->setupUi(this);
    std::cerr << "before field" << std::endl;

    QGridLayout* game = new QGridLayout();

    ImagePool<ImageBox>* boxPool = new ImagePool<ImageBox>;
    boxPool->load(ImageBox::Box, ":/images/box.png", 38, 38);
    boxPool->load(ImageBox::Ground, ":/images/pass.png", 38, 38);
    boxPool->load(ImageBox::Wall, ":/images/notPass.png", 38, 38);
    for(int i = 0; i < 13; i++)
        for(int j = 0; j < 20; j++){
            BoxWidget* box = new BoxWidget(ImageBox::Ground, std::make_shared<ImagePool<ImageBox>>(boxPool));
            field.push_back(box);
            game->addWidget(box, i, j);
        }
    field[0]->setImage(ImageBox::Box);

    gameUi->field->setLayout(game);

    connect(gameUi->goToMenuButton, SIGNAL(clicked(bool)), this, SLOT(menuScreen()));
}


void GameWidget::menuScreen(){
    emit setScreen(0); // go to menu screen
}

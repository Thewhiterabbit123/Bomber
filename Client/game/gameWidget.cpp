#include "gameWidget.h"
#include "game/box/boxwidget.h"
#include "game/box/imagebox.h"
#include "shared/imagePool/imagepool.h"

#include <memory>
#include <QTextEdit>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>


GameWidget::GameWidget(QWidget* parent): QWidget(parent), gameUi(new Ui::game()){

    std::cerr << "before ui" << std::endl;
    gameUi->setupUi(this);
    std::cerr << "before field" << std::endl;



    ACTOR_ANIMATION_POOL.load(ActorActions::Down, ":/resources/hedgehog_down.png", 11, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::Up, ":/resources/hedgehog_up.png", 11, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::Left, ":/resources/hedgehog_left.png", 11, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::Right, ":/resources/hedgehog_right.png", 11, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::Stay, ":/resources/hedgehog_stay.png", 31, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::BombStay, ":/resources/bomb_sprite.png", 11, 246, 280);
    ACTOR_ANIMATION_POOL.load(ActorActions::BombExplode, ":/resources/bomb_explosion.png", 11, 246, 280);


    view = new View();
    view->setStyleSheet("border: 0; background: rgba(255, 255, 255, 0);");
    view->setParent(gameUi->widgetPlayer);
    //view->setParent(gameUi->field);

    connect(gameUi->goToMenuButton, SIGNAL(clicked(bool)), this, SLOT(menuScreen()));
}


void GameWidget::menuScreen(){
    emit setScreen(0); // go to menu screen
}

void GameWidget::setMap(std::vector<ImageBox> map, std::map<int, int> playerPos, std::map<std::string, int> player){
    std::cerr << "setMap" << std::endl;
    gameLayout = new QGridLayout();

    ImagePool<ImageBox>* boxPool = new ImagePool<ImageBox>;
    boxPool->load(ImageBox::Box, ":/images/box.png", 38, 38);
    boxPool->load(ImageBox::Ground, ":/images/pass.png", 38, 38);
    boxPool->load(ImageBox::Wall, ":/images/notPass.png", 38, 38);
    for(int i = 0; i < 13*20; i++){
            BoxWidget* box = new BoxWidget(map[i], std::make_shared<ImagePool<ImageBox>>(boxPool));
            field.push_back(box);
            gameLayout->addWidget(box, i/20, i%20);
        }

    gameUi->field->setLayout(gameLayout);
}

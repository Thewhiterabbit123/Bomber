#include "view.h"
#include <QKeyEvent>
#include <iostream>

View::View(QWidget *parent)
    : QGraphicsView(parent) {
    setScene(&m_scene);


    m_scene.setSceneRect(0, 0, 20*38, 13*38);
    setSceneRect(0, 0, 20*38, 13*38);
    /*
    for(int i = 0; i < 4; i++)
        v_actor.push_back(new GraphicsActor(i));
    m_scene.addItem(v_actor[0]);

    v_actor[0]->setPos(0, 0);
    m_scene.addItem(v_actor[1]);
    v_actor[1]->setPos(50, 0);
    m_scene.addItem(v_actor[2]);
    v_actor[2]->setPos(100, 0);
    m_scene.addItem(v_actor[3]);
    v_actor[3]->setPos(150, 0);
    */
    //m_scene.addItem(&m_actor);
}


void View::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Left:
        emit clientAction(4);
        break;
    case Qt::Key_Down:
        emit clientAction(2);
        break;
    case Qt::Key_Right:
        emit clientAction(6);
        break;
    case Qt::Key_Up:
        emit clientAction(8);
        break;
    case Qt::Key_Space:
        emit clientAction(5);
        break;
    }
}


void View::playerMoveSlot(std::pair<int,int> event){
    for(int i = 0; i < v_actor.size(); i++){
        switch(event.second) {
        case LEFT_EVENT:
            v_actor[i]->processKey(event.first, ActorActions::Left);
            break;
        case DOWN_EVENT:
            v_actor[i]->processKey(event.first, ActorActions::Down);
            break;
        case RIGHT_EVENT:
            v_actor[i]->processKey(event.first, ActorActions::Right);
            break;
        case UP_EVENT:
            v_actor[i]->processKey(event.first, ActorActions::Up);
            break;
        }
    }
}

void View::setBomb(int id, int coord){
    BombActor* bombtest;
    std::cerr << "setBomb: id = " << id << " coord = " << coord << std::endl;
    bombtest = new BombActor(id);
    l_bomb.push_back(bombtest);
    m_scene.addItem(bombtest);
    bombtest->setPos((coord%20)*37 - 10, (coord/20)*37 - 12);
}

void View::playerDie(int idPlayer){
    for(auto v_actorIt = v_actor.begin(); v_actorIt != v_actor.end(); v_actorIt++)
        (*v_actorIt)->playerDie(idPlayer);
}


void View::bombExplode(int idBomb){
    for(auto l_bombIt = l_bomb.begin(); l_bombIt != l_bomb.end(); l_bombIt++)
        (*l_bombIt)->bombExplode(idBomb);
}


/*
void View::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Left:
        v_actor[0]->processKey(ActorActions::Left);
        break;
    case Qt::Key_Down:
        v_actor[0]->processKey(ActorActions::Down);
        break;
    case Qt::Key_Right:
        v_actor[0]->processKey(ActorActions::Right);
        break;
    case Qt::Key_Up:
        v_actor[0]->processKey(ActorActions::Up);
        break;
    }
}*/

void View::setMap(std::vector<ImageBox> map, std::map<int, int> playerPos, std::map<std::string, int> player){
    for(auto playerIt = player.begin(); playerIt != player.end(); playerIt++){
        v_actor.push_back(new GraphicsActor(playerIt->second));
    }
    for(auto playerPosIt = playerPos.begin(); playerPosIt != playerPos.end(); playerPosIt++){
        for(int i = v_actor.size() - 1; i >= 0; i--){
            v_actor[i]->setPosById(playerPosIt->second, playerPosIt->first);
        }
    }
    for(auto v_actorIt = v_actor.begin(); v_actorIt != v_actor.end(); v_actorIt++)
        m_scene.addItem(*v_actorIt);
}

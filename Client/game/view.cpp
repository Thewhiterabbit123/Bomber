#include "view.h"
#include <QKeyEvent>

View::View(QWidget *parent)
    : QGraphicsView(parent) {
    setScene(&m_scene);

    BombActor* bombtest;
    bombtest = new BombActor;
    m_scene.addItem(bombtest);
    bombtest->setPos(100, 100);
    for(int i = 0; i < 4; i++)
        v_actor.push_back(new GraphicsActor);
    m_scene.addItem(v_actor[0]);
    m_scene.setSceneRect(0, 0, 20*38, 13*38);
    setSceneRect(0, 0, 20*38, 13*38);
    v_actor[0]->setPos(0, 0);
    m_scene.addItem(v_actor[1]);
    v_actor[1]->setPos(50, 0);
    m_scene.addItem(v_actor[2]);
    v_actor[2]->setPos(100, 0);
    m_scene.addItem(v_actor[3]);
    v_actor[3]->setPos(150, 0);
    //m_scene.addItem(&m_actor);
}

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
}

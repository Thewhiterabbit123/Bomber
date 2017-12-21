#include "view.h"
#include <QKeyEvent>

View::View(QWidget *parent)
    : QGraphicsView(parent) {
    setScene(&m_scene);
    m_scene.addItem(&m_actor);
    m_scene.setSceneRect(0, 0, 20*38, 13*38);
    setSceneRect(0, 0, 20*38, 13*38);
    m_actor.setPos(0, 0);
    m_scene.addItem(&m_actor);
}

void View::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Left:
        m_actor.processKey(ActorActions::Left);
        break;
    case Qt::Key_Down:
        m_actor.processKey(ActorActions::Down);
        break;
    case Qt::Key_Right:
        m_actor.processKey(ActorActions::Right);
        break;
    case Qt::Key_Up:
        m_actor.processKey(ActorActions::Up);
        break;
    }
}
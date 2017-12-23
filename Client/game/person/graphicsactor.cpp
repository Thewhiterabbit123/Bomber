#include "game/person/graphicsactor.h"
#include "game/person/animations_enum.h"
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QDebug>

GraphicsActor::GraphicsActor(int idPlayer, QObject *parent)
    : idActor(idPlayer), AnimatedGraphicsItem(parent),
      m_moveAnimation(nullptr), m_currectAction(ActorActions::Stay) {
    setScale(0.13);
    setSprites(m_currectAction, true);
}

void GraphicsActor::setSprites(ActorActions sprites, bool force) {
    if (force || sprites != m_currectAction) {
        animation(sprites, Mode::Once, false);
    }
}


void GraphicsActor::processKey(int idPlayer, ActorActions action) {
    // sprites:
    if(idPlayer != idActor)
        return;

    if(m_currectAction == action)
        return;
/*
    if ((m_currectAction == ActorActions::Left && action == ActorActions::Right) ||
        (m_currectAction == ActorActions::Right && action == ActorActions::Left) ||
        (m_currectAction == ActorActions::Up && action == ActorActions::Down) ||
        (m_currectAction == ActorActions::Down && action == ActorActions::Up)) {
        action = ActorActions::Stay;
    }
*/
    /*
    if ((m_currectAction != ActorActions::Stay)) {
        return;
    }*/
    setSprites(action);

    // moving
    if (m_moveAnimation) {
        m_moveAnimation->deleteLater();
        m_moveAnimation = nullptr;
    }
    if (action != ActorActions::Stay) {
        QTimeLine *timer = new QTimeLine(AnimationPeriodMS, this);
        m_moveAnimation = new QGraphicsItemAnimation(timer);

        connect(timer, SIGNAL(finished()), this, SLOT(onAnimationFinished()));

        m_moveAnimation->setItem(this);
        m_moveAnimation->setTimeLine(timer);

        switch (action) {
        case ActorActions::Right:
            m_moveAnimation->setPosAt(1.0, pos() + QPointF(SpeedPx, 0));
            break;
        case ActorActions::Left:
            m_moveAnimation->setPosAt(1.0, pos() + QPointF(-SpeedPx, 0));
            break;
        case ActorActions::Up:
            m_moveAnimation->setPosAt(1.0, pos() + QPointF(0, -SpeedPx));
            break;
        case ActorActions::Down:
            m_moveAnimation->setPosAt(1.0, pos() + QPointF(0, SpeedPx));
            break;
        }
        timer->start();
    }

    m_currectAction = action;
}

void GraphicsActor::onAnimationFinished() {
    //processKey(m_currectAction);
    processKey(idActor, ActorActions::Stay);
}

void GraphicsActor::playerDie(int idPlayer) {
    if (idPlayer != idActor)
        return;
    hide();
}

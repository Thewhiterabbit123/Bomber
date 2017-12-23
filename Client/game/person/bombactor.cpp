#include "bombactor.h"

#include "game/person/animations_enum.h"
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QDebug>

BombActor::BombActor(int idBomb, QObject *parent): idBomb(idBomb), AnimatedGraphicsItem(parent), m_moveAnimation(nullptr), m_currectAction(ActorActions::BombStay){
    setScale(0.2);
    setSprites(m_currectAction, true);
}


void BombActor::setSprites(ActorActions sprites, bool force) {
    if (force || sprites != m_currectAction) {
        animation(sprites, Mode::Once, false);
    }
}

void BombActor::explode(int idBombGet){
    if (idBomb != idBombGet)
        return;
    setSprites(ActorActions::BombExplode);
    QTimeLine *timer = new QTimeLine(AnimationPeriodMS, this);
    connect(timer, SIGNAL(finished()), this, SLOT(hideself()));
    timer->start();
}

void BombActor::hideself(){
    hide();
    deleteLater();
}


void BombActor::bombExplode(int idBombGet){
    explode(idBombGet);
}



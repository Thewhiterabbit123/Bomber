#ifndef BOMBACTOR_H
#define BOMBACTOR_H

#include "game/person/animatedgraphicsitem.h"
#include "game/person/animations_enum.h"

class QGraphicsItemAnimation;

class BombActor: public AnimatedGraphicsItem {
    Q_OBJECT
public:
    explicit BombActor(int idBomb, QObject *parent = 0);
    void bombExplode(int idBombGet);
public slots:

    void setSprites(ActorActions sprites, bool force = false);


protected:
    const int AnimationPeriodMS = 1000;
    ActorActions m_currectAction;
    QGraphicsItemAnimation *m_moveAnimation;
    void hideself();

private:
    int idBomb;
    void explode(int idBomb);


};

#endif // BOMBACTOR_H


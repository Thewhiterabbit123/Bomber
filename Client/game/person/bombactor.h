#ifndef BOMBACTOR_H
#define BOMBACTOR_H

#include "game/person/animatedgraphicsitem.h"
#include "game/person/animations_enum.h"

class QGraphicsItemAnimation;

class BombActor: public AnimatedGraphicsItem {
    Q_OBJECT
public:
    explicit BombActor(QObject *parent = 0);
public slots:
    void explode(int idBomb);
    void setSprites(ActorActions sprites, bool force = false);

    void hideself();
protected:
    const int AnimationPeriodMS = 1000;
    ActorActions m_currectAction;
    QGraphicsItemAnimation *m_moveAnimation;

private:
    int id;
};

#endif // BOMBACTOR_H


#ifndef GRAPHICSACTOR_H
#define GRAPHICSACTOR_H

#include "game/person/animatedgraphicsitem.h"
#include "game/person/animations_enum.h"

class QGraphicsItemAnimation;

class GraphicsActor : public AnimatedGraphicsItem {
    Q_OBJECT
public:
    explicit GraphicsActor(int idPlayer, QObject *parent = 0);

    void setPosById(int pos, int idPlayer){
        if (idPlayer != idActor)
            return;
        setPos((pos%20)*37, (pos/20)*37);
    }

    void playerDie(int idPlayer);

public slots:
    void processKey(int idPlayer, ActorActions key);
    void setSprites(ActorActions sprites, bool force = false);
    void onAnimationFinished();


protected:
    const int AnimationPeriodMS = 1000;
    const int SpeedPx = 37;
    ActorActions m_currectAction;
    QGraphicsItemAnimation *m_moveAnimation;


private:
    int idActor;
};

#endif // GRAPHICSACTOR_H

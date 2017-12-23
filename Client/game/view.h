#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <vector>
#include "connection/client/Header.h"
#include "game/person/graphicsactor.h"
#include "game/person/bombactor.h"
#include "game/box/imagebox.h"

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
    std::vector<GraphicsActor*> v_actor;
    std::list<BombActor*> l_bomb;
protected slots:
    void keyPressEvent(QKeyEvent *event);
private:
    QGraphicsScene m_scene;
public slots:
    void setMap(std::vector<ImageBox> map, std::map<int, int> playerPos, std::map<std::string, int> player);
    void playerMoveSlot(std::pair<int, int> event);
    void setBomb(int id, int coord);
    void playerDie(int idPlayer);
    //void bombExplode(int idBomb);

signals:
    void clientAction(int action);
};

#endif // VIEW_H

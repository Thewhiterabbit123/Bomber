#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <vector>
#include "game/person/graphicsactor.h"
#include "game/person/bombactor.h"
#include "game/box/imagebox.h"

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
protected slots:
    void keyPressEvent(QKeyEvent *event);
private:
    QGraphicsScene m_scene;
    std::vector<GraphicsActor*> v_actor;
public slots:
    void setMap(std::vector<ImageBox> map, std::map<int, int> playerPos, std::map<std::string, int> player);
};

#endif // VIEW_H

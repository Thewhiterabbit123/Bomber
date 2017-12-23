#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H


#include <QWidget>
#include <vector>

#include "game/box/boxwidget.h"
#include "ui_gamewidgetui.h"

class GameWidget: public QWidget{
    Q_OBJECT
public:
    explicit GameWidget(QWidget* parent = NULL);

private:

    Ui::game* gameUi;
    std::vector<BoxWidget*> field;
    QGridLayout* gameLayout;

signals:
    void setScreen(int);

public slots:
    void setMap(std::vector<int> map, std::map<int, int> playerPos, std::map<std::string, int> player);
    void menuScreen();
};


#endif

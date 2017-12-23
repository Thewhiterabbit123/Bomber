#ifndef MENUWIDGET_H
#define MENUWIDGET_H


#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>

#include "ui_menuwidgetui.h"

class MenuWidget: public QWidget{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget* parent = NULL);

private:
    QGridLayout* menuLayout;
    QPushButton* goToGameButton;
    QPushButton* quitButton;
    QComboBox* pageComboBox;

public:
    Ui::menu* menuUi;

signals:
    void setScreen(int);

public slots:
    void gameScreen();
    void quitAll();

};


#endif

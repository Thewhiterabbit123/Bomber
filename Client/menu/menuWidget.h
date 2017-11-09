#ifndef MENUWIDGET_H
#define MENUWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

class MenuWidget: public QWidget{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget* parent = NULL);

private:
    QVBoxLayout* menuLayout;
    QPushButton* goToGameButton;
    QPushButton* quitButton;
    QComboBox* pageComboBox;

signals:
    void setScreen(int);

public slots:
    void gameScreen();
    void quitAll();

};


#endif

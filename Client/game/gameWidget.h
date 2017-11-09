#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class GameWidget: public QWidget{
    Q_OBJECT
public:
    explicit GameWidget(QWidget* parent = NULL);

private:
    QVBoxLayout* gameLayout;
    QPushButton* backButton;

signals:
    void setScreen(int);

public slots:
    void menuScreen();
};


#endif

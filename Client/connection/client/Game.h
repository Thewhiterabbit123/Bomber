#ifndef GAME_H
#define GAME_H
#include "Client.h"
#include <QObject>

class Game : public QObject {
    Q_OBJECT

    public:
      //  Game(QObject* parent = 0): QObject(parent) {connect(this, SIGNAL(allReady()), client-> )};
        ~Game();
        void play();
    signals:
        void startGame(std::vector<int> map, std::map<int, int> playerPos, std::map<std::string, int> player);

    public slots:
       // void Ready();

    private:
        Client *client;

};

#endif // GAME_H

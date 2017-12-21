#ifndef GAME_H
#define GAME_H
#include "Client.h"
#include <QObject>
#include "Header.h"

class Game : public QObject {
    Q_OBJECT

    public:
         Game(QObject* parent = 0): QObject(parent) {};
        ~Game();
        void play();
    signals:
        void startGame(std::vector<int> map, std::map<int, int> playerPos, std::map<std::string, int> player);

    public slots:
       // void Ready();

    private:
        Client *client;
        Parser *parser;

};

#endif // GAME_H

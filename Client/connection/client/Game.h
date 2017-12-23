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
        void play(std::string name);
        void eventSwitcher(int);

    signals:
        void startGame(std::vector<int> map, std::map<int, int> playerPos, std::map<std::string, int> player);
        void playerMove(std::pair<int, int> event);
        void playerSetBomb(std::pair<int, int> bombEvent);
        void playerDie(int idPlayer);
        void explodeBox(int pos);
        void gameOver(std::string nickname);

    public slots:
        void getMessage();
        //void allReady();
        void buttonAction(int);

    private:
        Client *client;
        Parser *parser;

};

#endif // GAME_H

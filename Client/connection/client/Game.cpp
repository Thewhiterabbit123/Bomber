#include "Game.h"

void Game::play(std::string name) {
    client = new Client(name);
    parser = new Parser();
    connect(client, SIGNAL(socketGetMessage()), this, SLOT(getMessage()));
}

void Game::eventSwitcher(int event)  {

    switch(event) {

        case SEND_ID: {            //this packet need to get my id
            client->setMyId(parser->getMyId());
            break;
        }

        case START_GAME: {          //typeofpacket - map - [id - name - id - position]x4
            std::cerr << "mapsize on parser" << parser->getMap().size();
            emit startGame(parser->getMap(), parser->getPosOfPlayer(), parser->getNickname());
            std::cerr << "emit startgame";
            break;
        }

        case MOVE_PLAYER: {
            std::cerr << "I GET MOVE EVENT" << std::endl;
            emit playerMove(parser->getEvent());
            std::cout << "PrisheL" << std::endl;
            break;
        }

        case BOMB_PLANTED: {
            std::pair<int, int> event = parser->getBombEvent();
            std::cerr << "BOMBPLANTED 1" << std::endl;
            emit setBomb(event.first, event.second);
            std::cerr << "BOMBPLANTED 2" << std::endl;
            break;
        }

        case BOMB_EXPLODE: {
            emit bombExplode(parser->getBombId());
            break;
        }

        case END_GAME: {
            parser->getWinnerName();
            break;
        }
        case BOX_EXPLODE: {
            emit explodeBox(parser->getBoxId());
            break;
        }
        case PLAYER_DEAD: {
            emit playerDie(parser->getDeadId());
            break;
        }
    }
}

Game::~Game() {
    delete client;
    delete parser;
}

void Game::buttonAction(int event) {
    std::string msg = client->prepareMessageToServer(event);
    client->sendMessage(msg);
}

void Game::getMessage() {
    int event = parser->parseLine(client->getInputMessage());
    eventSwitcher(event);
}

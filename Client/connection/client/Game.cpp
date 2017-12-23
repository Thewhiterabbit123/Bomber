#include "Game.h"

void Game::play(std::string name) {
    client = new Client(name);
    parser = new Parser();
    connect(client, SIGNAL(socketGetMessage()), this, SLOT(getMessage()));
}

void Game::eventSwitcher(int event)  {
    std::cerr << START_GAME << std::endl;
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
            parser->getEvent();
            break;
        }

        case BOMB_PLANTED: {
            parser->getBombEvent();
            break;
        }

        case BOMB_EXPLODE: {
            parser->getBombId();
            break;
        }

        case END_GAME: {
            parser->getWinnerName();
            break;
        }
        case BOX_EXPLODE: {
            parser->getBoxId();
            break;
        }
        case PLAYER_DEAD: {
            parser->getDeadId();
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

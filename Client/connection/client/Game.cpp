#include "Game.h"

void Game::play(std::string name) {
    client = new Client(name);
    parser = new Parser();
}

void Game::eventSwitcher(int event)  {

    switch(event) {

        case SEND_ID: {            //this packet need to get my id
            client->setMyId(parser->getMyId());
            break;
        }

        case START_GAME: {          //typeofpacket - map - [id - name - id - position]x4
            parser->getMap();
            parser->getPosOfPlayer();
            parser->getNickname();
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

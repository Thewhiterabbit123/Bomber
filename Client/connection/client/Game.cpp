#include "Game.h"

void Game::play() {
    client = new Client();
    parser = new Parser();
    client->Connect();
    std::string name = "naDYa";
    client->sendMessage(name);
    std::string messageFromServer = client->getMessage();
    int happens = parser->parseLine(messageFromServer);

    switch(happens) {
        case 00: {
            client->setMyId(parser->getMyId());
            break;
        }
        case 01: {
            parser->getMap();
            parser->getPosOfPlayer();
            break;
            //call signal for Dima
        }
        case 02: {
            break;
        }

    }
}

Game::~Game() {
    delete client;
    delete parser;
}

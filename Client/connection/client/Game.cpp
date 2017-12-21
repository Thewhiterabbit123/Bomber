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
        case IDPACKET: {
            client->setMyId(parser->getMyId());
            logfile << "I'VE GOT MY ID. THIS IS IT - " << parser->getMyId() << std::endl;
            break;
        }
        case INITPACKET: {
            parser->getMap();
            parser->getPosOfPlayer();
            parser->getNickname();
            break;
            //call signal for Dima
        }
        case EVENTPACKET: {
            parser->getEvent();
            logfile << "SOME SHIT HAPPENS" << std::endl;
            break;
        }
    }
}

Game::~Game() {
    delete client;
    delete parser;
}

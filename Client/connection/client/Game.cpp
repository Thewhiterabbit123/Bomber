#include "Game.h"

void Game::play() {
    client = new Client();
    parser = new Parser();
    client->Connect();
    std::string name = "naDYa";
    client->sendMessage(name);
    while(true) {
        std::string messageFromServer = client->getMessage();
        int event = parser->parseLine(messageFromServer);
        eventSwitcher(event);
        //тут отправить сообщение серверу
    }
}

void Game::eventSwitcher(int event)  {

    switch(event) {
//        case IDPACKET: {
//            client->setMyId(parser->getMyId());
//            break;
//        }
//        case INITPACKET: {
//            parser->getMap();
//            parser->getPosOfPlayer();
//            parser->getNickname();
//            break;
//            //call signal for Dima
//        }
//        case EVENTPACKET: {
//            parser->getEvent();
//            break;
//        }
//        case EVENTBOMBPACKET: {
//            parser->getBombEvent();
//            break;
//        }
    }
}

Game::~Game() {
    delete client;
    delete parser;
}

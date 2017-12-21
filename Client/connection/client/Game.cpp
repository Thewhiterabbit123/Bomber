#include "Game.h"

void Game::play() {
    client = new Client();
    client->Connect();
    std::string name = "naDYa";
    client->sendMessage(name);
    client->getMessage();
//    while(true) {

//    }

}

Game::~Game() {
    delete client;
}

//Game::Ready() {
//    std::cout << "lol\n";
//}

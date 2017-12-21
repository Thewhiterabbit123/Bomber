#include "Game.h"

void Game::play() {
    client = new Client();
    client->Connect();
}

Game::~Game() {
    delete client;
}

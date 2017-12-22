#include "Game.h"
#include "Player.h"
#include "Field.h"

using namespace std;

Game::Game() {
	player.reserve(PLAYER_COUNT);
}

int Game::CreatePlayer(const std::string & name) {
    Player currentPlayer(field, name);
    player.push_back(currentPlayer);
    return currentPlayer.GetId();
}

Player & Game::FindPlayer(const unsigned int id) {
    for (int i = 0; i < PLAYER_COUNT; i++)
        if (player[i].GetId() == id)
            return player[i];
}

string Game::GetPlayerNameById(const unsigned int id) {
    return FindPlayer(id).GetName();
}

void Game::KillCharacter() {	//kills player who has 0 hp
	/* Передача всем игрокам
	сигнала о том, что персонаж
	умер. Удаление игрока из
	вектора. */
}

void Game::DestroyBomb() {

}


void Game::EndGame() {

}

void Game::CreateBomb(const Bomb &_bomb) {
	bomb.push(_bomb);
}

void Game::GetTime() {

}

void Game::PushClientAction(ClientAction & action) {
    clientAction.push(action);
}

void Game::Step() {
    while (true) {
        ClientAction currentChange = clientAction.front();  //  get Change from queue
        clientAction.pop();   //  delete Change from queue
        Event currentEvent = currentChange.eventInfo.eventType;
        unsigned int currentId = currentChange.id;
        Coordinate currentCoordinate = currentChange.eventInfo.changePosition;

        //  Player movement
        if (currentEvent >= UP_EVENT && currentEvent <= RIGHT_EVENT) {
            Player currentPlayer = FindPlayer(currentId);
            currentPlayer.MakeMovement(currentCoordinate, currentEvent);
        }

    }
}

std::string Game::GetMap() {
    return field.FieldToString();
}

void Game::StartMenu() {

}

void GetField() {

}

void ParsePacket() {

}

void Pause() {

}

void StartMenu() {

}

void Update() {

}


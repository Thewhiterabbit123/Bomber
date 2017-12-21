#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <vector>
#include <string>
using namespace std;

Game::Game(const vector<string> & name, const Field & _field)
{
    player.reserve(PLAYER_COUNT);
    bomb.reserve(BOMB_COUNT);
	field = _field;
	for (int i = 0; i < PLAYER_COUNT; i++) {
		Player _player(name[i], i);
		player.push_back(_player);
	}
}

Game::Game() {
	player.reserve(PLAYER_COUNT);
    bomb.reserve(BOMB_COUNT);
    field = globalField;
}

int Game::CreatePlayer(const std::string & name) {
    static int skinNum = 0;
    Player currentPlayer(name, skinNum);
    player.push_back(currentPlayer);
    skinNum++;
    return currentPlayer.GetId();
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
	bomb.push_back(_bomb);
}

void Game::GetTime() {

}

void Game::Step() {

}

void Game::GetField() {

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


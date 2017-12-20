#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <vector>
#include <string>
using namespace std;

Game::Game(const &vector<string> name, const & Field _field)
{
	field = _field;
	for (int i = 0; i < PLAYER_COUNT; i++) {
		Player _player(name[i]);
		player.push(_player, i);
	}
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


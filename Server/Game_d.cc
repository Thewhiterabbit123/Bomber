#include "Game_d.h"

Game::Game(const vector<string> & name, const Field & _field)
{
	field = _field;
	for (int i = 0; i < PLAYER_COUNT; i++) {
		Player _player(name[i], i);
		player.push_back(_player);
	}
}

void Game::Step() {
	while (player.size() != 1) {
		
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
	bomb.push_back(_bomb);
}

void Game::GetTime() {

}

void Game::GetField() {

}

void Game::StartMenu() {

}

int main () {
	Game *game;
	std::vector<string> playersNames = {"Rustam", "Timur", "Kirill", "Nadya"};
	Field field;
	game = new Game(playersNames, field);
	game->Step();
	std::cout << "Develop" << std::endl;

}


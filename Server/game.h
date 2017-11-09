#include <iostream>
#include <vector>

class Game {
private:
	vector<Player> player; 
	vector<Bomb> bomb;
	Field field;
	Time time;
	EventManager *eventManager;
	StateManager *stateManager;
	ResolveManager *resolveManager;
public:
	Game(){};
	void StartGame();
	void KillCharacter();
	void DestroyBomb();


};

void Game::KillCharacter() {	//kills player who has 0 hp
	/* Передача всем игрокам
	сигнала о том, что персонаж
	умер. Удаление игрока из
	вектора. */


}

void Game::DestroyBomb() {

}








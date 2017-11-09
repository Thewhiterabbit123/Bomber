#include <iostream>
#include <vector>
#include "Define.h"

class Game {
private:
	vector<Player> player(PLAYER_COUNT); 
	vector<Bomb> bomb(BOMB_COUNT);
	Field field;
	Time time;
	EventManager *eventManager;
	StateManager *stateManager;
	ResolveManager *resolveManager;
public:
	Game(Field &_field,
		 Time &_time,
		 EventManager *_eventManager, 
		 StateManager *_stateManager,
		 ResolveManager *_resolveManager):
		field(_field),
		time(_time),
		eventManager(_eventManager),
		stateManager(_stateManager),
		resolveManager(_resolveManager) {};
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








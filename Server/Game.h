#ifndef GAME_H
#define GAME_H

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

	void KillCharacter();
	void DestroyBomb();
	void StartGame();
	void EndGame();
	void CreateCharacter();
	void CreateBomb();
	void GetTime();
	void GetField();
	void ParsePacket();
	void Pause();
	void StartMenu();
	void Update();
};

#endif





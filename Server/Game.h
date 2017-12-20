#ifndef GAME_H
#define GAME_H

#include "../Define.h"
#include "Field.h"
#include "Player.h"
#include "Bomb.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Game {
	private:
		vector<Player> player; 
		vector<Bomb> bomb;
		Field field;
		Time time;
		queue<Event> eventContainer;
	public:
		Game(const & vector<string> name, const & Field _field);
		AYE
		void Step();
		void KillCharacter();
		void DestroyBomb();
		void EndGame();
		void CreateBomb(const Bomb &_bomb);
		void GetTime();
		void GetField();
		void StartMenu();
};

#endif





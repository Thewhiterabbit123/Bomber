#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "../Define.h"

class Game {
	private:
		vector<Player> player; 
		vector<Bomb> bomb;
		Field field;
		Time time;
		EventContainer eventContainer;
	public:
		Game(const & vector<string> name, const & Field _field);

		void Step();
		void KillCharacter();
		void DestroyBomb();
		void EndGame();
		void CreateBomb();
		void GetTime();
		void GetField();
		void StartMenu();
};

#endif





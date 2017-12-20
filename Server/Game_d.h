#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "../Define.h"

using namespace std;

class Object {
	public:
		Object() {};
};

class Player: public Object {
	public:
		Player(std::string playerName, int playerSkin): 
			Object(), name(playerName), skin(playerSkin), 
			hp(MAX_PLAYER_HP), bomb(BOMB_COUNT_ONE_PLAYER) {};
	private:
		std::string name;
		int bomb;
		int hp;
		int skin;
};

class Bomb {

};

class Field {

};

class Time {

};

class EventContainer {

};


class Game {
	private:
		vector<Player> player; 
		vector<Bomb> bomb;
		Field field;
		Time time;
		EventContainer eventContainer;
	public:
		Game(const vector<string> & name, const  Field & _field);

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





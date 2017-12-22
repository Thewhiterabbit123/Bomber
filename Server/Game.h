#pragma once

#include "../Define.h"
#include "Field.h"
#include "Player.h"
#include "Bomb.h"
#include <boost/asio.hpp>

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Game {
	private:
        Field field;
		vector<Player> player; 
		queue<Bomb> bomb;
		Time time;
		queue<Change> eventContainer;
	public:
		Game();
		int CreatePlayer(const std::string & name);
        Player & FindPlayer(const unsigned int id);
        string GetPlayerNameById(const unsigned int id);
		void Step();
		void KillCharacter();
		static void DestroyBomb(const boost::system::error_code&, Game&);
		void EndGame();
		void CreateBomb(const Bomb &_bomb);
		void GetTime();
		void GetField();
		void StartMenu();
};

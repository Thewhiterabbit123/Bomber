#pragma once
#include "../Define.h"
#include "Field.h"
#include "Player.h"
#include "Bomb.h"

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

using namespace std;

class Game {
	private:
        int clientCount;
        Field field;
		vector<Player> player; 
		list<Bomb> bomb;
		Time time;
		queue<ClientAction> clientAction;
	public:
		Game();
		Game(const Game &_game) {};

        static void DestroyBomb(Game *game);
        void Step();
        void PushClientAction(ClientAction & action);
        void CreateBomb(const Bomb &_bomb);
        void GetTime();
        void MakeMovement(Coordinate, Player *, Event);

		int CreatePlayer(const std::string & name);
        int GetPlayerPositionById(const unsigned int id);
        Player * FindPlayer(const unsigned int id);
        string GetPlayerNameById(const unsigned int id);
        std::string GetMap();
        Coordinate GetNextPosition(Coordinate, Event);
};

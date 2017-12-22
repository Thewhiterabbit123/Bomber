#pragma once

#include "Define.h"

struct Coordinate {
	int x;
	int y;
    Coordinate(): x(0), y(0) {};
	Coordinate(const int &_x, const int &_y): x(_x), y(_y) {};
	Coordinate(const Coordinate & coordinate): x(coordinate.x), y(coordinate.y) {};
    int ToInt() { return (MAP_COLUMN_SIZE * y + x); }
	const Coordinate& operator = (const Coordinate& rhs) { x = rhs.x; y = rhs.y; return *this; }
    bool operator == (const Coordinate & rhs) { return (x == rhs.x && y ==rhs.y); }
	bool operator != (const Coordinate & rhs) { return !(x == rhs.x && y ==rhs.y); }
};

struct PlayerInfo {
	char nickName[NICK_SIZE];
	Coordinate place;
	short hp;
	short bombCount;
};

//  change on map
struct ClientAction {
    unsigned int id;
    Event event; //сделать структуру event

    ClientAction(unsigned int _id, Event _event): id(_id), event(_event) {};
};

struct BombInfo {
	int bombId; //нельзя присваивать нулю
	Coordinate place;
};

struct BlockInfo {
	int blockId;
	int type; 
};

struct NewBomb {
	int newBombId;
	Coordinate place;
};

struct Medicine {
	int medicineId;
	Coordinate place;
};

//Запрос от клиента к серверу
struct InitRequest {
	int type;
	char nickName[NICK_SIZE];
};

struct InitAnswer {
	int type;
	unsigned int clientId;
};

struct IsReadyRequest {
	int type;
	unsigned int clientId;
};

struct IsReadyAnswer {
	int type;
	bool ready;
};

struct MapNowRequest {
	int type;
	unsigned int clientId;
};

struct MapNowAnswer {
	int type;

	PlayerInfo player[PLAYER_COUNT + 1];
	BombInfo bomb[BOMB_COUNT + 1];
	BlockInfo block[BLOCK_COUNT + 1]; 
	NewBomb newBomb[BLOCK_COUNT + 1];
	Medicine medicine[BLOCK_COUNT + 1];
};


struct Time {

};

#pragma once

#include "Define.h"

struct Coordinate {
	int x;
	int y;
    Coordinate(): x(0), y(0) {};
	Coordinate(const int &_x, const int &_y): x(_x), y(_y) {};
	Coordinate(const Coordinate & coordinate): x(coordinate.x), y(coordinate.y) {};
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

struct EventInfo {
	Event eventType;
	Coordinate changePosition;

    EventInfo(Event _event, int _x, int _y): eventType(_event), changePosition(_x, _y) {};
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

struct PlayerEventRequest {
	int type;
	unsigned int clientId;
	EventInfo event; 
};

//  change on map
struct ClientAction {
	unsigned int id;
	EventInfo eventInfo; //сделать структуру event

    ClientAction(Event _event, unsigned int _id,  int _x, int _y): eventInfo(_event, _x, _y) {};
};

struct Time {

};

#ifndef STRUCT_H
#define STRUCT_H

struct Coordinate {
	int x;
	int y;
	Coordinate(int _x, int _y): x(_x), y(_y) {};
	Coordinate& operator = (Coordinate& rhs) { return Coordinate(this->x = rhs.x, this->y = rhs.y); };
};

struct PlayerInfo {
	char nickName[NICK_SIZE];
	Coordinate place;
	short hp;
	short bombCount;
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
	s_coordinate place;
};

struct Medicine {
	int medicineId;
	s_coordinate place; 
};

//Запрос от клиента к серверу
struct initRequest {
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
	unsigned int event; 
};

//  change on map
struct Change {
	unsigned int id;
	struct EventInfo; //сделать структуру event
}

struct EventInfo {
	int eventType;
	Coordinate place;
};

#endif STRUCT_H

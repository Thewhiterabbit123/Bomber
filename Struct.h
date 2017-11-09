<<<<<<< HEAD

struct s_coordinate {
	int x;
	int y;
};

struct s_player {
	char nickName[NICK_SIZE];
	s_coordinate place;
=======
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
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	short hp;
	short bombCount;
};

<<<<<<< HEAD
struct s_bomb {
	int bombId; //нельзя присваивать нулю
	s_coordinate place;
};

struct s_block {
=======
struct BombInfo {
	int bombId; //нельзя присваивать нулю
	Coordinate place;
};

struct BlockInfo {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int blockId;
	int type; 
};

<<<<<<< HEAD
struct s_newBomb {
=======
struct NewBomb {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int newBombId;
	s_coordinate place;
};

<<<<<<< HEAD
struct s_medicine {
=======
struct Medicine {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int medicineId;
	s_coordinate place; 
};

//Запрос от клиента к серверу
<<<<<<< HEAD
struct s_initRequest {
=======
struct initRequest {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	char nickName[NICK_SIZE];
};

<<<<<<< HEAD
struct s_initAnswer {
=======
struct InitAnswer {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	unsigned int clientId;
};

<<<<<<< HEAD
struct s_isReadyRequest {
=======
struct IsReadyRequest {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	unsigned int clientId;
};

<<<<<<< HEAD
struct s_isReadyAnswer {
=======
struct IsReadyAnswer {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	bool ready;
};

<<<<<<< HEAD
struct s_mapNowRequest {
=======
struct MapNowRequest {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	unsigned int clientId;
};

<<<<<<< HEAD
struct s_mapNowAnswer {
	int type;

	s_player player[PLAYER_COUNT + 1];
	s_bomb bomb[BOMB_COUNT + 1];
	s_block block[BLOCK_COUNT + 1]; 
	s_newBomb newBomb[BLOCK_COUNT + 1];
	s_medicine medicine[BLOCK_COUNT + 1];
};

struct s_playerEventRequest {
=======
struct MapNowAnswer {
	int type;

	PlayerInfo player[PLAYER_COUNT + 1];
	BombInfo bomb[BOMB_COUNT + 1];
	BlockInfo block[BLOCK_COUNT + 1]; 
	NewBomb newBomb[BLOCK_COUNT + 1];
	Medicine medicine[BLOCK_COUNT + 1];
};

struct PlayerEventRequest {
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55
	int type;
	unsigned int clientId;
	unsigned int event; 
};

//  change on map
<<<<<<< HEAD
struct s_change {
	unsigned int id;
	struct event; //сделать структуру event
}

struct s_event {
	int eventType;
	s_coordinate place;
};
=======
struct Change {
	unsigned int id;
	struct EventInfo; //сделать структуру event
}

struct EventInfo {
	int eventType;
	Coordinate place;
};

#endif STRUCT_H
>>>>>>> 4b28d23504986373cf4beb7c1af5323c9a970a55

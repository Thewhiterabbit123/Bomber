
struct s_coordinate {
	int x;
	int y;
};

struct s_player {
	char nickName[NICK_SIZE];
	s_coordinate place;
	short hp;
	short bombCount;
};

struct s_bomb {
	int bombId; //нельзя присваивать нулю
	s_coordinate place;
};

struct s_block {
	int blockId;
	int type; 
};

struct s_newBomb {
	int newBombId;
	s_coordinate place;
};

struct s_medicine {
	int medicineId;
	s_coordinate place; 
};

//Запрос от клиента к серверу
struct s_initRequest {
	int type;
	char nickName[NICK_SIZE];
};

struct s_initAnswer {
	int type;
	unsigned int clientId;
};

struct s_isReadyRequest {
	int type;
	unsigned int clientId;
};

struct s_isReadyAnswer {
	int type;
	bool ready;
};

struct s_mapNowRequest {
	int type;
	unsigned int clientId;
};

struct s_mapNowAnswer {
	int type;

	s_player player[PLAYER_COUNT + 1];
	s_bomb bomb[BOMB_COUNT + 1];
	s_block block[BLOCK_COUNT + 1]; 
	s_newBomb newBomb[BLOCK_COUNT + 1];
	s_medicine medicine[BLOCK_COUNT + 1];
};

struct s_playerEventRequest {
	int type;
	unsigned int clientId;
	unsigned int event; 
};

//  change on map
struct s_change {
	unsigned int id;
	struct event; //сделать структуру event
}

struct s_event {
	int eventType;
	s_coordinate place;
};
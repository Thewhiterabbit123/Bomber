#pragma once

enum Event { 
	NO_EVENT,
	UP_EVENT,
	DOWN_EVENT,
	LEFT_EVENT,
	RIGHT_EVENT,
	SET_BOMB_EVENT,
	EXPLODE_BOMB_EVENT,
	SET_NEWBOMB_EVENT,
	PICK_NEWBOMB_EVENT,
	SET_MEDICINE_EVENT,
	PICK_MEDICINE_EVENT,
	KILL_BOMBER
};

//  BlockType

enum BlockType {
	EMPTY, //пустой игровой блок
	BOX, //взрываемый бокс
	WALL //невзрываемая стена
};

////
//  map

#define MAP_ROW_SIZE 13
#define MAP_COLUMN_SIZE 20
#define MAP_SIZE MAP_ROW_SIZE*MAP_COLUMN_SIZE

//  nickSize

#define NICK_SIZE 20

//  player

#define PLAYER_COUNT 4
#define MAX_PLAYER_HP 3

//  bomb

#define BOMB_COUNT_ONE_PLAYER 3
#define BOMB_COUNT_ONE_PLAYER_MAX 5
#define BOMB_COUNT BOMB_COUNT_ONE_PLAYER_MAX*PLAYER_COUNT

//  block

#define BLOCK_COUNT MAP_SIZE-PLAYER_COUNT

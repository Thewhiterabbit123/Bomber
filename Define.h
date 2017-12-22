#pragma once

enum Event {
	SEND_ID, // 0
	START_GAME, //  1
	UP_EVENT, //  2
	DOWN_EVENT,  //  3
	LEFT_EVENT, //  4
	RIGHT_EVENT, //  5
	SET_BOMB_EVENT,
	BOMB_EVENT,
	MOVE_PLAYER,
	BOMB_PLANTED,
	BOMB_EXPLODE,
	PLAYER_DEAD,
	PLUS_HP,
	MINUS_HP,
	BOX_EXPLODE,
	END_GAME
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

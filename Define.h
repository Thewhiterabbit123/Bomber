#pragma once

enum Event {
	SEND_ID, // 0
	START_GAME, //  1
	UP_EVENT, //  2
	DOWN_EVENT,  //  3
	LEFT_EVENT, //  4
	RIGHT_EVENT, //  5
	SET_BOMB_EVENT, // 6
	BOMB_EVENT, // 7
	MOVE_PLAYER, // 8
	BOMB_PLANTED, // 9
	BOMB_EXPLODE, // 10
	PLAYER_DEAD, //  11
	PLUS_HP, //  12
	MINUS_HP,  //  13
	BOX_EXPLODE, //  14
	END_GAME  //  15
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
#define BOMB_TIMER 4
#define BOMB_DAMAGE 1
#define BOMB_RADIUS

//  block

#define BLOCK_COUNT MAP_SIZE-PLAYER_COUNT




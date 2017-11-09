//  map

#define MAP_ROW_SIZE 20
#define MAP_COLUMN_SIZE 20
#define MAP_SIZE MAP_ROW_SIZE*MAP_COLUMN_SIZE

// dick size

#define MAX_DICK_SIZE 350

//  event

#define NO_EVENT 0
#define UP_EVENT 1
#define DOWN_EVENT 2
#define LEFT_EVENT 3
#define RIGHT_EVENT 4
#define SET_BOMB_EVENT 5
#define EXPLODE_BOMB_EVENT 6
#define SET_NEWBOMB_EVENT 7
#define PICK_NEWBOMB_EVENT 8
#define SET_MEDICINE_EVENT 9
#define PICK_MEDICINE_EVENT 10
#define KILL_BOMBER 11

//  event masks сделать структуру event

#define EVENT_MASK(Z) ((Z)&65535)
#define X_MASK(Z) ((Z)>>24)
#define Y_MASK(Z) (((Z)>>16)&255)

//  s_block type

#define BOX 0
#define WALL 1

//  nickSize

#define NICK_SIZE 20

//  player

#define PLAYER_COUNT 4

// bomb

#define BOMB_COUNT_ONE_PLAYER 3
#define BOMB_COUNT_ONE_PLAYER_MAX 5
#define BOMB_COUNT BOMB_COUNT_ONE_PLAYER_MAX*PLAYER_COUNT

//  block

#define BLOCK_COUNT MAP_SIZE-PLAYER_COUNT

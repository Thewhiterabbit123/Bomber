#ifndef HEADER_H
#define HEADER_H

#define NUMBEROFPLAYERS  4
#define MAPWIDTH        20
#define MAPHEIGHT       13


enum Event {
    SEND_ID,
    START_GAME,
    UP_EVENT,
    DOWN_EVENT,
    LEFT_EVENT,
    RIGHT_EVENT,
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

#endif // HEADER_H


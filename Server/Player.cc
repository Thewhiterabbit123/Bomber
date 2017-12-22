#include "Player.h"

Player::Player(const Field &_field, const std::string _name): field(_field), Object(), name(_name), bomb(BOMB_COUNT_ONE_PLAYER), hp(MAX_PLAYER_HP) {
    static int skinId = 0;
    skin = skinId;
    skinId++;
}

Coordinate Player::PositionAfterMovement(const Coordinate &coordinate, Event move) {
    switch(move) {
        case UP_EVENT:
            coordinate.y++;
            break;
        case DOWN_EVENT:
            coordinate.y--;
            break;
        case RIGHT_EVENT:
            coordinate.x++;
            break;
        case LEFT_EVENT:
            coordinate.x--;
            break;
    }
}

int Player::ToVectorCoordinate(const Coordinate &coordinate) {
    return (MAP_COLUMN_SIZE * coordinate.y + coordinate.x);
}

void Player::MakeMovement(const Coordinate &coordinate, Event move) {
    Coordinate nextCoordinate;
    int vectCoordinate;
    if (position != coordinate) {
        nextCoordinate = PositionAfterMovement(position, move);
        vectCoordinate = ToVectorCoordinate(nextCoordinate);

    }
    else {
        nextCoordinate = PositionAfterMovement(coordinate, move);
        vectCoordinate = ToVectorCoordinate(nextCoordinate);
    }
    if (field.field[vectCoordinate] == BOX || field.field[vectCoordinate] == WALL)
        return;
    position = nextCoordinate;
    SendMovePlayer(GetId(), vectCoordinate);
}

void Player::PutBomb() {
    if (bomb > 0)
	    bomb--;
}

void Player::GetDamage() {
	hp--;
}

void Player::Heal() {
	if(hp < MAX_PLAYER_HP) {
		hp++;
	}
}

int Player::GetHp() {
	return hp;
}

int Player::GetBomb() {
	return bomb;
}

std::string Player::GetName() {
    return name;
}



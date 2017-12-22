#include "Player.h"

Player::Player(const Field &_field, const std::string _name): field(_field), Object(), name(_name), bomb(BOMB_COUNT_ONE_PLAYER), hp(MAX_PLAYER_HP) {
    static int skinId = 0;
    skin = skinId;
    isActive = true;
    skinId++;
}

Coordinate Player::PositionAfterMovement(const Coordinate &coordinate, Event move) {
    switch(move) {
        case UP_EVENT:
            return Coordinate(coordinate.x, coordinate.y + 1);
        case DOWN_EVENT:
            return Coordinate(coordinate.x, coordinate.y - 1);
        case RIGHT_EVENT:
            return Coordinate(coordinate.x + 1, coordinate.y);
        case LEFT_EVENT:
            return Coordinate(coordinate.x - 1, coordinate.y);
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
    BlockType block = (BlockType)field.GetField()[vectCoordinate].GetType();
    if (block == BOX || block == WALL)
        return;
    position = nextCoordinate;
    SendMovePlayer(GetId(), vectCoordinate);
}

void Player::PutBomb() {
    if (bomb > 0)
	    bomb--;
}

bool Player::GetDamage() {
	if(hp > 1) {
        hp--;
        return true;
    } else {
        isActive = false;
        return false;
    }
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



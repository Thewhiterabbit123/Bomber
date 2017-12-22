#include "Player.h"

Player::Player(Field &_field, std::string _name, Coordinate _coordinate): Object(_coordinate), field(_field), name(_name), bomb(BOMB_COUNT_ONE_PLAYER), hp(MAX_PLAYER_HP) {
    static int skinId = 0;
    skin = skinId;
    isActive = true;
    skinId++;
}

Coordinate Player::PositionAfterMovement(Event move) {
    switch(move) {
        case UP_EVENT:
            return Coordinate(position.x, position.y - 1);
        case DOWN_EVENT:
            return Coordinate(position.x, position.y + 1);
        case RIGHT_EVENT:
            return Coordinate(position.x + 1, position.y);
        case LEFT_EVENT:
            return Coordinate(position.x - 1, position.y);
    }
}

bool Player::MakeMovement(Event move, Coordinate & coordinate) {
    Coordinate nextCoordinate = PositionAfterMovement(move);
    int vectCoordinate = nextCoordinate.ToInt();
    BlockType block = (BlockType)field.GetField()[vectCoordinate].GetType();
    if (block == BOX || block == WALL)
        return false;
    position = coordinate = nextCoordinate;
    return true;
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



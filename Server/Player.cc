#include "Player.h"

Player::Player(const Field &_field, const std::string _name): field(_field), Object(), name(_name), bomb(BOMB_COUNT_ONE_PLAYER), hp(MAX_PLAYER_HP) {
    static int skinId = 0;
    skin = skinId;
    skinId++;
}

void Player::SetPosition(Event move) {
	switch(move) {
        case UP_EVENT:
			position.y++;
			break;
		case DOWN_EVENT: 
			position.y--;
			break;
		case RIGHT_EVENT: 
			position.x++;
			break;
		case LEFT_EVENT: 
			position.x--;
			break;
	}
}

void Player::CheckPosition(const Coordinate &coordinate) {
    if (position == coordinate)
        return;
    // обработать
    position.x = coordinate.x;
    position.y = coordinate.y;
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



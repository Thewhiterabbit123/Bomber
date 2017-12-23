#include "Player.h"

Player::Player(std::string _name, Coordinate _coordinate): Object(_coordinate), name(_name), bomb(BOMB_COUNT_ONE_PLAYER), hp(MAX_PLAYER_HP) {
    static int skinId = 0;
    skin = skinId;
    isActive = true;
    skinId++;
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

bool Player::IsActive() {
    return isActive;
}



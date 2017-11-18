#include "Player.h"

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

void Player::PutBomb() {
	bomb--;
}

void Player::GetDamage() {
	hp--;
}

void Player::Heal() {
	if(hp < 3) {
		hp++;
	}
}

int Player::GetHp() {
	return hp;
}

int Player::GetBomb() {
	return bomb;
}


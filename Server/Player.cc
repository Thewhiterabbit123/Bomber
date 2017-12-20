#include "Player.h"

Player::Player(): Object(), name("Default"), bomb(BOMB_COUNT_ONE_PLAYER) {

}

Player::Player(std::string playerName, int playerSkin):
        Object(), name(playerName), skin(playerSkin), hp(MAX_PLAYER_HP), bomb(BOMB_COUNT_ONE_PLAYER) {

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

void Player::PutBomb() {
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


#include "Player.h"
#include "struct.h"

Player::Player(Coordinate startpos, int skinId): bomb(3), hp(3) {
	position = startpos;
	skin = skinId;
}

void Player::Move(int x, int y) {
	position.x += x;
	position.y += y;
}

void Player::PutBomb() {

}

void Player::GetDamage(int amount) {
	hp -= amount;
}

void Player::Heal(int amount) {
	hp += amount;
}

int Player::GetHp() {
	return hp;
}

int Player::GetBomb() {
	return bomb;
}

Coordinate GetPosition() {
	return position;
}
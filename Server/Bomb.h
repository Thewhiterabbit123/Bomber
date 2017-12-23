#pragma once
#include "Object.h"
#include "../Define.h"

class Bomb : public Object {
	public:
		Bomb(Coordinate startPosition): Object(startPosition), damage(BOMB_DAMAGE), timeToLive(BOMB_TIMER), radius(BOMB_RADIUS) {};
		int GetRadius();
		int GetDamage();
		double GetTimeToLive();
	private:
		int damage;
		int radius;
		double timeToLive;
};
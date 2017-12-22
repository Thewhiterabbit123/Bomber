#pragma once
#include "Object.h"

class Bomb : public Object {
	public:
		Bomb(): Object(), damage(1), timeToLive(10), radius(3) {};
		Bomb(Coordinate startPosition): Object(startPosition), damage(1), timeToLive(10), radius(3) {};
		int GetRadius();
		int GetDamage();
		double GetTimeToLive();
	private:
		int damage;
		int radius;
		double timeToLive;
};
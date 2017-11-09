#ifndef BOMB_H
#define BOMB_H
#include "struct.h"

class Bomb {
	private:
		int id;
		int damage;
		int timeToLive;
		int radius;
		Coordinate position;
	public:
		Bomb(): id(0), damage(0), timeToLive(0), position(0, 0), radius(0) {};
		void Explode();
		int GetDamage();
		int GetTimeToLive();
		Coordinate GetPosition();	
};

#endif BOMB_H
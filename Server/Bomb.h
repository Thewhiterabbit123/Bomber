#pragma once
#include "Object.h"
#include "../Define.h"

class Bomb : public Object {
	public:
		Bomb(Coordinate startPosition, int _playerId): Object(startPosition), playerId(_playerId), damage(BOMB_DAMAGE), timeToLive(BOMB_TIMER), radius(BOMB_RADIUS) {};
		int GetRadius();
		int GetDamage();
        int GetPlayerId();
		double GetTimeToLive();
	private:
		int damage;
		int radius;
		double timeToLive;
		int playerId;
};
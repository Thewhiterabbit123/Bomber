#ifndef PLAYER_H
#define PLAYER_H
#include "struct.h"

class Player {
public:
	Player(Coordinate startpos, int skinId);
	void Move(int x, int y);
	void PutBomb();
	void GetDamage(int amount);
	void Heal(int amount);
	int GetHp();
	int GetBomb();
	Coordinate GetPosition();
private:
	int bomb;
	int hp;
	Coordinate position;
	int skin;
};

#endif PLAYER_H
#pragma once

#include "Object.h"
#include "../Define.h"

#include <string>

class Player : public Object {
	public:
		Player();
		Player(std::string playerName, int playerSkin);
		void SetPosition(enum Event);
		void PutBomb();
		void GetDamage();
		void Heal();
		int GetHp();
		int GetBomb();
	private:
		std::string name;
		int bomb;
		int hp;
		int skin;
};
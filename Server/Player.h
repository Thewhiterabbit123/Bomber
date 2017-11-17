#pragma once
#include "Object.h"
#include "../Define.h"
#include <string>

class Player : public Object {
	public:
		Player(std::string playerName, int playerSkin): Object(), name(playerName), skin(playerSkin), hp(MAX_PLAYER_HP), bomb(BOMB_COUNT_ONE_PLAYER) {};
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
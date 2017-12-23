#pragma once
#include "Object.h"
#include "../Define.h"
#include "Field.h"
#include "ServerFuncs.h"
#include <string>

class Player : public Object {
	public:
        Player(std::string _name, Coordinate _coordinate);
		void PutBomb();
		bool GetDamage();
		void Heal();
		int GetHp();
		int GetBomb();
        std::string GetName();
		bool IsActive();
	private:
		std::string name;
        bool isActive;
		int bomb;
		int hp;
		int skin;
};
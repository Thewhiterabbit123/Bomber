#pragma once

#include "Object.h"
#include "../Define.h"
#include "Field.h"

#include <string>

class Player : public Object {
	public:
        Player(const Field & _field, const std::string _name);
		void SetPosition(enum Event);
        void CheckPosition(const Coordinate & coordinate);
		void PutBomb();
		void GetDamage();
		void Heal();
		int GetHp();
		int GetBomb();
        std::string GetName();
	private:
		std::string name;
		int bomb;
		int hp;
		int skin;
        const Field & field;
};
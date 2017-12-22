#pragma once
#include "Object.h"
#include "../Define.h"
#include "Field.h"
#include "ServerFuncs.h"
#include <string>

class Player : public Object {
	public:
        Player(Field & _field,  std::string _name, Coordinate _coordinate);
        bool MakeMovement(Event, Coordinate &);
		void PutBomb();
		void GetDamage();
		void Heal();
		int GetHp();
		int GetBomb();
        std::string GetName();
	private:
        Coordinate PositionAfterMovement(Event);
		std::string name;
		int bomb;
		int hp;
		int skin;
        Field & field;
};
#pragma once

#include "Object.h"
#include "../Define.h"

class Block: public Object {
	private:
		BlockType type;
	public:
		Block(const BlockType &_type = EMPTY, 
			  const Coordinate &_position): 
			  type(_type), position(&_position) { };
		int SetType(const BlockType &_type);
		int GetType();
		int ExplodeBlock();
};


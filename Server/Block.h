#pragma once

#include "Object.h"
#include "../Define.h"

class Block: public Object {
	private:
		BlockType type;
	public:
        Block();
		Block   (const Coordinate & _position,
                const BlockType & _type = EMPTY
			    );
		int SetType(const BlockType &_type);
		int GetType();
		int ExplodeBlock();
};

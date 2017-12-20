#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "../Define.h"

class Block: public Object {
	private:
		BlockType type;
	public:
        Block();
		Block(const BlockType & _type = EMPTY,
			  const Coordinate & _position);
		int SetType(const BlockType &_type);
		int GetType();
		int ExplodeBlock();
};

#endif

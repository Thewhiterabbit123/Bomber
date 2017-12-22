#pragma once

#include <string>

#include "Object.h"
#include "../Define.h"

class Block: public Object {
	private:
		BlockType type;
	public:
        Block(): Object(), type(EMPTY) {};
		Block (const Coordinate & _position,
			   const BlockType & _type = EMPTY
		);
		int SetType(const BlockType &_type);
		const BlockType & GetType() const;
		std::string GetTypeInString();
		int ExplodeBlock();
};

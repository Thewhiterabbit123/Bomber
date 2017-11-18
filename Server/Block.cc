#include "Block.h"

int Block::GetType() {
	return type;
}

int Block::ExplodeBlock() {
	if (type == BOX)
		type = WALL;
}

int Block::SetType(const BlockType &_type) {
	type = _type;
}



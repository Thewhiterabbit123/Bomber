#include "Block.h"

Block::Block(const Coordinate &_position, const BlockType &_type):
		Object(), type(_type) {
	position = _position;
}

int Block::GetType() {
	return type;
}

int Block::ExplodeBlock() {
	if (type == BOX)
		type = EMPTY;
}

int Block::SetType(const BlockType &_type) {
	type = _type;
}



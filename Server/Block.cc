#include "Block.h"

Block::Block(const Coordinate &_position, const BlockType &_type):
		Object(), type(_type) {
	position = _position;
}

BlockType Block::GetType()  {
	return type;
}

std::string Block::GetTypeInString() {
	std::string str;
	str = std::to_string(GetType());
	return str;
}

int Block::ExplodeBlock() {
	if (type == BOX)
		type = EMPTY;
}

int Block::SetType(const BlockType &_type) {
	type = _type;
}



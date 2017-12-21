#include "Block.h"

Block::Block(): Object(), type(EMPTY) {

}

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

Block::Block(const Coordinate &_position, const BlockType &_type):
		Object(), type(_type) {
    position = _position;
}



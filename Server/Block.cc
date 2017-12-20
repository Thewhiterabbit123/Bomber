#include "Block.h"

Block::Block(const BlockType & _type = EMPTY,
             const Coordinate & _position):
             Object(), type(_type), position(_position) {
}

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



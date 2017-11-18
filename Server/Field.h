#pragma once

#include "Block.h"

class Field {
	private:
		vector<vector<Block>> field;
	public:
		vector<vector<Block>> & GetField();
};


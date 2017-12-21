#pragma once

#include "Block.h"
#include "../Define.h"

#include <vector>

using namespace std;

class Field {
	private:
		vector< vector<Block> > field;
	public:
		Field();
		vector< vector<Block> > & GetField();
};


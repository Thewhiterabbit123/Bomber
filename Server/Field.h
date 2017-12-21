#pragma once

#include "Block.h"
#include "../Define.h"
#include "../Struct.h"

#include <vector>
#include <string>

using namespace std;

class Field {
	private:
		vector<Block> field;
	public:
		Field();
		vector<Block>& GetField();
		string& fieldToString();
};


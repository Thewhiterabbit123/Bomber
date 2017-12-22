#pragma once

#include "Block.h"
#include "../Define.h"
#include "../Struct.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Field {
	private:
		vector<Block> field;
	public:
		Field();
		Field(Field & _field);
        Field & operator = (Field & rhs);
		vector<Block>& GetField();
		string FieldToString();
};


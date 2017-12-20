#ifndef FIELD_H
#define FIELD_H

#include "Block.h"

#include <vector>
using namespace std;

class Field {
	private:
		vector< vector<Block> > field;
	public:
		vector< vector<Block> > & GetField();
};

#endif


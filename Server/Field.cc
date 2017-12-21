#include "Field.h"

Field::Field() {
    field.reserve(MAP_COLUMN_SIZE);
    for (int i = 0; i < MAP_COLUMN_SIZE; i++) {
        field[i].reserve(MAP_ROW_SIZE);
    }
}

vector< vector<Block> > & Field::GetField() {
	return field;
}
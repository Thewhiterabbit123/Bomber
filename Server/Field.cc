#include "Field.h"

Field::Field() {
    field.reserve(MAP_COLUMN_SIZE * MAP_ROW_SIZE);
    std::string line;
    std::ifstream fieldConfig;
    fieldConfig.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        fieldConfig.open("../fieldConf");
        getline(fieldConfig, line);
        for (int i = 0; i < line.size(); i++) {
            Coordinate curCoord(i % MAP_ROW_SIZE, (int) i / MAP_ROW_SIZE);
            Block curBlock(curCoord, (BlockType)line[i]);
            field.push_back(curBlock);
        }
    } catch (std::ifstream::failure e) {

        std::cerr << " cant open conf fieldConfig";
    }
    fieldConfig.close();
}

Field::Field(Field &_field) {
    for (std::vector<Block>::iterator i = _field.field.begin(); i != field.end(); i++) {
        field.push_back(*i);
    }
}

Field & Field::operator=(Field &rhs) {
    for (std::vector<Block>::iterator i = rhs.field.begin(); i != rhs.field.end(); i++) {
        field.push_back(*i);
    }
    return *this;
}

vector<Block>& Field::GetField() {
	return field;
}

const vector<Block>& Field::GetField() const {
    return field;
}

string Field::FieldToString() {
    std::string output;
    for(std::vector<Block>::iterator i = field.begin(); i != field.end(); i++) {
        output += (*i).GetTypeInString();
    }
    return output;
}
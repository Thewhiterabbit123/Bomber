#include "Field.h"
#include <fstream>

Field::Field() {
    field.reserve(MAP_COLUMN_SIZE * MAP_ROW_SIZE);
    std::string line;
    std::ifstream fieldConfig;
    fieldConfig.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        fieldConfig.open("../fieldConf");
        getline(fieldConfig, line);
        for(int i = 0; i < line.size(); i++) {
            Coordinate curCoord(i % MAP_ROW_SIZE, (int) i / MAP_ROW_SIZE);
            Block curBlock(curCoord, line[i]);
            field.push_back(curBlock);
        }
    } catch (std::ifstream::failure e) {
        std::cerr << " cant open conf fieldConfig";
    }
    fieldConfig.close();
}

vector<Block>& Field::GetField() {
	return field;
}

string& Field::fieldToString() {
    std::string output;
    for(std::vector<Block>::iterator i = field.begin(); i!= field.end(); i++) {
        output += *i;
    }
    return output;
}
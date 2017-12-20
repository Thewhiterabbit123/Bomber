#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Position.h"

class Parser {
    public:
        void parseLine(std::string);
        int getMyId(std::string);
        void makeMapFromString(std::string);
    private:
        int _id;
        int what;
        int typeOfPacket;
        std::vector<int> parseMap;
        std::map<int, int> posOfPlayer;
        std::map<std::string, int> nickname;
};

#endif // PARSER_H

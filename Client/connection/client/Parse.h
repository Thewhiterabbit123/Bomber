#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Position.h"
//#include <QObject>

class Parser {
    public:
        Parser(): _id(0), what(0), typeOfPacket(0), myId(0) {};
        void parseLine(std::string);
        int  getMyId(std::string);
        void makeMapFromString(std::string);
        std::vector<int> getParseMap();
    private:
        int _id;
        int what;
        int typeOfPacket;
        int myId;
        std::string myName;
        std::vector<int> parseMap;
        std::map<int, int> posOfPlayer;
        std::map<std::string, int> nickname;
};

#endif // PARSER_H

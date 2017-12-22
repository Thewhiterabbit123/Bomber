#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Header.h"

class Parser {
    public:
        int  parseLine(std::string);
        void makeMapFromString(std::string);
        std::string getNameById(int);

        int  getMyId();
        std::map<std::string, int> getNickname();
        std::vector<int> getParseMap();
        std::vector<int> getMap();
        std::map<int, int> getPosOfPlayer();
        std::pair<int, int> getEvent();
        std::pair<int, int> getBombEvent();

    private:
        int myId;
        std::pair<int, int> event;
        std::vector<int> parseMap;
        std::map<int, int> posOfPlayer;
        std::map<std::string, int> nickname;
        std::pair<int, int> bombEvent;
};

#endif // PARSER_H

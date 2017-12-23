#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Header.h"
#include "../../game/box/imagebox.h"

class Parser {
    public:
        int  parseLine(std::string);
        void makeMapFromString(std::string);
        std::string getNameById(int);

        int  getMyId();
        std::map<std::string, int> getNickname();
        std::vector<ImageBox> getMap();
        std::map<int, int>  getPosOfPlayer();
        std::pair<int, int> getEvent();
        std::pair<int, int> getBombEvent();
        std::string getWinnerName();
        int getBoxId();
        int getDeadId();
        int getBombId();

    private:
        int myId;
        std::pair<int, int> event;
        std::vector<ImageBox> parseMap;
        std::map<int, int> posOfPlayer;
        std::map<std::string, int> nickname;
        std::pair<int, int> bombEvent;
        std::string winnerName;
        int boxId;
        int deadId;
        int bombId;
};

#endif // PARSER_H

#include "Parse.h"
#include <sstream>
#include <iostream>

#define NUMBEROFPLAYERS 4
#define MAPWIDTH 20
#define MAPHEIGHT 13

int Parser::parseLine(std::string line) {
    std::stringstream stream(line);
    int typeOfPacket = 0;
    stream >> typeOfPacket;

    switch (typeOfPacket) {
        case 00: { //this packet need to get my id
            stream >> myId;
            return 00;
            break;
        }
    //init packet - type 1, id and clients's name
        case 01: {
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                int id = 0;
                std::string name;

                stream >> id;
                stream >> name;
                nickname[name] = id;
                return 01;
            }
            break;
        }
    //init packet with position of game entity. type - 2. map - first, then for id-position
        case 02: {
            int localId = 0;
            int posOnVector = 0;
            std::string _map;
            stream >> _map; //get map from packet
            makeMapFromString(_map);
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                stream >> localId >> posOnVector;  //get coordinat's of players
                posOfPlayer[localId] = posOnVector;
            }
            return 02;
            break;
        }
        case 03: {
            int id = 0;
            int what = 0;
            stream >> id;
            stream >> what;
            return 03;
            break;
        }
    }
}

void Parser::makeMapFromString(std::string _map) {
    for(int i = 0; i < MAPHEIGHT; i++) {
        for(int j = 0; j < MAPWIDTH; j++) {
            parseMap.push_back(_map[i]);
        }
    }
}
std::vector<int> Parser::getParseMap() {
    return parseMap;
}

int Parser::getMyId() {
    return myId;
}

std::map<std::string, int> Parser::getNickname() {
    return nickname;
}

std::vector<int> Parser::getMap() {
    return parseMap;
}

std::map<int, int> Parser::getPosOfPlayer() {
    return posOfPlayer;
}

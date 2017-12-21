#include "Parse.h"
#include <sstream>
#include <iostream>

#define NUMBEROFPLAYERS 4
#define MAPWIDTH 20
#define MAPHEIGHT 13

void Parser::parseLine(std::string line) {
    std::stringstream stream(line);
    stream >> typeOfPacket;

    switch (typeOfPacket) {
    //init packet - type 1, id and clients's name
        case 1: {
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                stream >> _id;
                std::string name;
                stream >> name;
                nickname[name] = _id;
            }
            break;
        }
    //init packet with position of game entity. type - 2. map - first, then for id-position
        case 2: {
            int localId = 0;
            int posOnVector = 0;
            Position pos;
            std::string _map;
            stream >> _map; //get map from packet
            makeMapFromString(_map);
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                stream >> localId >> pos;  //get coordinat's of players
                posOnVector = pos.x * MAPWIDTH + pos.y;
                posOfPlayer[localId] = posOnVector;
            }
            myId = getMyId(myName);
            break;
        }
        case 3: {
            stream >> _id;
            stream >> what;
        }
    }
}

int Parser::getMyId(std::string name) {
    std::map<std::string, int>::iterator  it = nickname.find(name);
    if( it != nickname.end() ) {
        return it->second;
    }
    return 0;
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

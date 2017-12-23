#include "Parse.h"
#include <sstream>
#include <iostream>

void Parser::parseLine(std::string line) {
    std::stringstream stream(line);
    stream >> typeOfPacket;

    switch (typeOfPacket) {
    //init packet - type 1, id and clients's name
        case 1: {
            for(int i = 0; i < 4; i++) {
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
            stream >> _map;
            makeMapFromString(_map);
            for(int i = 0; i < 4; i++) {
                stream >> localId >> pos;
                posOnVector = pos.x * 20 + pos.y;
                posOfPlayer[localId] = posOnVector;
            }
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
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 20; j++) {
            parseMap.push_back(_map[i]);
        }
    }
}

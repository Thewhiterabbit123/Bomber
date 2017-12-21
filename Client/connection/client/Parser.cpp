#include "Parser.h"
#include <sstream>
#include <iostream>

int Parser::parseLine(std::string line) {
    std::stringstream stream(line);
    int typeOfPacket = 0;
    stream >> typeOfPacket;

    switch (typeOfPacket) {
        case IDPACKET: {            //this packet need to get my id
            stream >> myId;
            return 00;
            break;
        }

        case INITPACKET: {          //typeofpacket - map - [id - name - id - position]x4
            std::string _map;
            stream >> _map;         //get map from packet
            makeMapFromString(_map);
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                int localId = 0;
                int posOnVector = 0;
                stream >> localId >> posOnVector;  //get coordinat's of players, posOnVector = x*MAPWIDTH + y
                posOfPlayer[localId] = posOnVector;
            }
            for(int i = 0; i < NUMBEROFPLAYERS; i++) {
                int id = 0;
                std::string name;

                stream >> id;
                stream >> name;
                nickname[name] = id;
            }
            return 01;
            break;
        }

        case EVENTPACKET: {
            int id = 0;
            int what = 0;
            stream >> id;
            stream >> what;
            event = std::make_pair(id, what);
            return 02;
            break;
        }
    }
}

void Parser::makeMapFromString(std::string _map) {
    for(int i = 0; i < MAPHEIGHT*MAPWIDTH; i++) {
            parseMap.push_back(_map[i]);
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

std::pair<int, int> Parser::getEvent() {
    return event;
}

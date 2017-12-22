#include "Parser.h"
#include <sstream>
#include <iostream>

int Parser::parseLine(std::string line) {
    std::stringstream stream(line);
    int typeOfPacket = 0;
    stream >> typeOfPacket;

    switch (typeOfPacket) {
        case SEND_ID: {            //this packet need to get my id
            stream >> myId;
            return SEND_ID;
            break;
        }

        case START_GAME: {          //typeofpacket - map - [id - name - id - position]x4
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
            return START_GAME;
            break;
        }

        case MOVE_PLAYER: {
            int id = 0;
            int position = 0;
            stream >> id;
            stream >> position;
            event = std::make_pair(id, position);
            return MOVE_PLAYER;
            break;
        }

        case BOMB_PLANTED: {
            int bombID = 0;
            int bombPosition = 0;
            stream >> bombID;
            stream >> bombPosition;
            bombEvent = std::make_pair(bombID, bombPosition);
            return BOMB_EVENT;
            break;
        }

        case BOMB_EXPLODE: {
            int bombId = 0;
            stream >> bombId;
            break;
        }

        case END_GAME: {
            int winnerId;
            stream >> winnerId;
            std::string winnerName = getNameById(winnerId);
            return END_GAME;
            break;
        }
        case BOX_EXPLODE: {
            int boxId = 0;
            stream >> boxId;
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

std::pair<int, int> Parser::getBombEvent() {
    return bombEvent;
}

std::string Parser::getNameById(int id) {
    for (std::map<std::string, int>::iterator  it = nickname.begin(); it != nickname.end(); it++) {
        if( it->second == id) {
            return it->first;
        }
    }
}


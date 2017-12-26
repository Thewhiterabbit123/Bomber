#include "Parser.h"

int Parser::parseLine(std::string line) {
    std::cout << line << std::endl;
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
                std::string name;

                stream >> localId >> name >> posOnVector;  //get coordinat's of players, posOnVector = x*MAPWIDTH + y
                posOfPlayer[localId] = posOnVector;
                nickname[name] = localId;
            }
            std::cout << "im in parser start game" << std::endl;
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
            return BOMB_PLANTED;
            break;
        }

        case BOMB_EXPLODE: {
            stream >> bombId;
            return BOMB_EXPLODE;
            break;
        }

        case END_GAME: {
            int winnerId;
            stream >> winnerId;
            winnerName = getNameById(winnerId);
            return END_GAME;
            break;
        }
        case BOX_EXPLODE: {
            stream >> boxId;
            return BOX_EXPLODE;
            break;
        }
        case PLAYER_DEAD: {
            stream >> deadId;
            return PLAYER_DEAD;
            break;
        }
    }
}

void Parser::makeMapFromString(std::string _map) {
    for(int i = 0; i < MAPHEIGHT*MAPWIDTH; i++) {
        switch (_map[i]) {
            case '0': {
                parseMap.push_back(ImageBox::Ground);
                break;
            }
            case '1': {
                parseMap.push_back(ImageBox::Box);
                break;
            }
            case '2': {
                parseMap.push_back(ImageBox::Wall);
                break;
            }
        }
    }
}

int Parser::getMyId() {
    return myId;
}

std::map<std::string, int> Parser::getNickname() {
    return nickname;
}

std::vector<ImageBox> Parser::getMap() {
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

std::string Parser::getWinnerName() {
    return winnerName;
}

int Parser::getBoxId() {
    return boxId;
}

int Parser::getDeadId() {
    return deadId;
}

int Parser::getBombId() {
    return bombId;
}

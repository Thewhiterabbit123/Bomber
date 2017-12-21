#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Position.h"
#include <QObject>

class Parser: public QObject {
    Q_OBJECT

    public:
        Parser(QObject* parent = 0): QObject(parent) { };
        void parseLine(std::string);
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
    signals:
        void allReady();
};

#endif // PARSER_H

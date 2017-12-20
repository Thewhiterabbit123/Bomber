#ifndef POSITION_H
#define POSITION_H
#include <iostream>

struct Position {
    int x;
    int y;
};

inline std::ostream& operator << (std::ostream& os, const Position& ts){
    return os << ts.x << " " << ts.y;
}

inline std::istream& operator >> (std::istream& is, Position& obj) {
    is >> obj.x >> obj.y;
    return is;
}

#endif // POSITION_H


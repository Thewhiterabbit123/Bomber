cmake_minimum_required(VERSION 3.6)
project(Bomber)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Client/game/gameWidget.cpp
        Client/game/gameWidget.h
        Client/menu/menuWidget.cpp
        Client/menu/menuWidget.h
        Client/bombergame.cpp
        Client/bombergame.h
        Client/main.cpp
        Server/Block.cc
        Server/Block.h
        Server/Bomb.cc
        Server/Bomb.h
        Server/Field.cc
        Server/Field.h
        Server/Game.cc
        Server/Game.h
        Server/Game_d.cc
        Server/Game_d.h
        Server/Object.cc
        Server/Object.h
        Server/Player.cc
        Server/Player.h
        define.cc
        Define.h
        struct.cc
        Struct.h Server/Server_functions.h.h Server/ServerFuncs.h)

add_executable(Bomber ${SOURCE_FILES})
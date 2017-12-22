#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <vector>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
using namespace std;

Game::Game() {
	player.reserve(PLAYER_COUNT);
    bomb.reserve(BOMB_COUNT);
}

int Game::CreatePlayer(const std::string & name) {
    Player currentPlayer(field, name);
    player.push_back(currentPlayer);
    return currentPlayer.GetId();
}

Player & Game::FindPlayer(const unsigned int id) {
    for (int i = 0; i < PLAYER_COUNT; i++)
        if (player[i].GetId() == id)
            return player[i];
}

string Game::GetPlayerNameById(const unsigned int id) {
    return FindPlayer(id).GetName();
}

void Game::KillCharacter() {	//kills player who has 0 hp
	/* Передача всем игрокам
	сигнала о том, что персонаж
	умер. Удаление игрока из
	вектора. */
}

void Game::DestroyBomb(const boost::system::error_code& e, Game& game) {
    
}


void Game::EndGame() {

}

void Game::CreateBomb(const Bomb &_bomb) {
	bomb.push_back(_bomb);
}

void Game::GetTime() {

}

void Game::Step() {
    while (true) {
        Change currentChange = eventContainer.front();  //  get Change from queue
        eventContainer.pop();   //  delete Change from queue
        Event currentEvent = currentChange.eventInfo.eventType;
        unsigned int currentId = currentChange.id;
        Coordinate currentCoordinate = currentChange.eventInfo.changePosition;

        //  Player movement
        if (currentEvent >= UP_EVENT && currentEvent <= RIGHT_EVENT) {
            Player currentPlayer = FindPlayer(currentId);
            currentPlayer.CheckPosition(currentCoordinate);
            currentPlayer.SetPosition(currentEvent);
        }

        // Bomb is set
        if (currentEvent == SET_BOMB_EVENT ) {
            boost::asio::io_service io;
            boost::system::error_code e;
            boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
            t.async_wait(boost::bind(&DestroyBomb, e, *this));
            Bomb newBomb(currentCoordinate);
            CreateBomb(newBomb);
            io.run();

        }



    }
}

void Game::GetField() {

}

void Game::StartMenu() {

}

void GetField() {

}

void ParsePacket() {

}

void Pause() {

}

void StartMenu() {

}

void Update() {

}


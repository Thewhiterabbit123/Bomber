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
}

int Game::CreatePlayer(const std::string & name) {
    static int positionNumber = 0;
    static Coordinate positions [4] = {Coordinate(0, 0), Coordinate(0, MAP_COLUMN_SIZE - 1), Coordinate(MAP_ROW_SIZE - 1, 0), Coordinate(MAP_ROW_SIZE - 1, MAP_COLUMN_SIZE - 1)};
    Player currentPlayer(field, name, positions[positionNumber]);
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
    Bomb bombToDestroy = game.bomb.front();
    game.bomb.pop();
    int bombDamage = bombToDestroy.GetDamage();
    int bombRadius = bombToDestroy.GetRadius();
    Coordinate bombPosition = bombToDestroy.GetPosition();
    std::vector<Block> currentField = game.field.GetField();
    for(int k = 0; k < 4; k++) {
        Coordinate currentPos = bombPosition;
        bool flag = false;
        for(int i = 0; i < bombRadius && !flag; i++) {
            for(std::vector<Player>::iterator j = game.player.begin(); j != game.player.end(); j++) {
                if(j -> GetPosition() == currentPos) {
                    if(!j -> GetDamage()) {
                        SendPlayerDead (j->GetId());
                    } else {
                        SendMinusHP(j->GetId());
                    }
                    flag = true;
                }
            }
            if(currentField[currentPos.ToInt()].GetType() == WALL) {
                flag = true;
            }

            if(currentField[currentPos.ToInt()].GetType() == BOX) {
                SendBoxExplode(currentField[currentPos.ToInt()].GetId(), (int) EMPTY);
                flag = true;
            }
            switch(k) {
                case 0:
                    currentPos.x++;
                    break;
                case 1:
                    currentPos.x--;
                    break;
                case 2:
                    currentPos.y++;
                    break;
                case 3:
                    currentPos.y--;
                    break;
            }
        }
    }

}


void Game::EndGame() {

}

void Game::CreateBomb(const Bomb &_bomb) {
	bomb.push(_bomb);
}

void Game::GetTime() {

}

void Game::PushClientAction(ClientAction & action) {
    clientAction.push(action);
}

void Game::Step() {
    while (true) {
        ClientAction currentChange = clientAction.front();  //  get Change from queue
        clientAction.pop();   //  delete Change from queue
        Event currentEvent = currentChange.event;
        unsigned int currentId = currentChange.id;
        Player currentPlayer = FindPlayer(currentId);
        //  Player movement
        if (currentEvent >= UP_EVENT && currentEvent <= RIGHT_EVENT) {
            Coordinate newPosition;
            bool IsMovement = currentPlayer.MakeMovement(currentEvent, newPosition);
            if (IsMovement)
                SendMovePlayer(currentId, newPosition.ToInt());
            boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
            continue;
        }



        // Bomb is set
        if (currentEvent == SET_BOMB_EVENT ) {
            boost::asio::io_service io;
            boost::system::error_code e;
            boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
            t.async_wait(boost::bind(&DestroyBomb, e, *this));
            Bomb newBomb(currentPlayer.GetPosition());
            CreateBomb(newBomb);
            io.run();
            boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
            continue;

        }



    }
}

std::string Game::GetMap() {
    return field.FieldToString();
}

int Game::GetPlayerPositionById(const unsigned int id) {
    Player player = FindPlayer(id);
    return player.GetPosition().ToInt();
}

void Game::StartMenu() {

}

void ParsePacket() {

}

void Pause() {

}

void StartMenu() {

}

void Update() {

}


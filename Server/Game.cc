#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <vector>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
using namespace std;

Game::Game(): clientCount(0) {
	player.reserve(PLAYER_COUNT);
}

int Game::CreatePlayer(const std::string & name) {
    static Coordinate positions [4] = {Coordinate(1, 1), Coordinate(MAP_COLUMN_SIZE - 2, 1), Coordinate(1, MAP_ROW_SIZE - 2), Coordinate(MAP_COLUMN_SIZE - 2, MAP_ROW_SIZE - 2)};
    Player currentPlayer(name, positions[clientCount++]);
    player.push_back(currentPlayer);
    return currentPlayer.GetId();
}

Player * Game::FindPlayer(const unsigned int id) {
    for (int i = 0; i < PLAYER_COUNT; i++)
        if (player[i].GetId() == id)
            return &player[i];
}

string Game::GetPlayerNameById(const unsigned int id) {
    return FindPlayer(id) -> GetName();
}

int Game::GetPlayerPositionById(const unsigned int id) {
    Player *player = FindPlayer(id);
    return player->GetPosition().ToInt();
}

void Game::DestroyBomb(Game *game) {
    boost::this_thread::sleep_for(boost::chrono::seconds(BOMB_TIMER));
    if (game->bomb.empty())
        return;
    Bomb bombToDestroy = game->bomb.front();
    game->bomb.pop_front();
    Player *currentPlayer = game->FindPlayer(bombToDestroy.GetPlayerId());
    currentPlayer->RespawnBomb();
    int bombDamage = bombToDestroy.GetDamage();
    int bombRadius = bombToDestroy.GetRadius();
    Coordinate bombPosition = bombToDestroy.GetPosition();
    std::vector<Block> & currentField = game->field.GetField();
    //  check player on bomb
    Coordinate currentPos = bombPosition;

    for (std::vector<Player>::iterator i = game->player.begin(); i != game->player.end(); i++) {
        if ((currentPos == i->GetPosition()) && i->IsActive()) {
            if (!i->GetDamage()) {
                game->clientCount--;
                SendPlayerDead(i->GetId());
            } else {
                SendMinusHP(i->GetId());
            }
        }
    }

    for(int k = 0; k < 4; k++) {
        bool flag = false;
        switch (k) {
            case 0: currentPos.x++;
                    break;
            case 1: currentPos.x--;
                    break;
            case 2: currentPos.y++;
                    break;
            case 3: currentPos.y--;
                    break;
        }
        for(int i = 1; i < bombRadius && !flag; i++) {
            for(std::vector<Player>::iterator j = game->player.begin(); j != game->player.end(); j++) {
                if ( (currentPos == j -> GetPosition()) && j -> IsActive()) {
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
                currentField[currentPos.ToInt()].SetType(EMPTY);
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
        currentPos = bombPosition;
    }

}

void Game::CreateBomb(const Bomb &_bomb) {
	bomb.push_back(_bomb);
}

void Game::GetTime() {

}

void Game::PushClientAction(ClientAction & action) {
    clientAction.push(action);
}

Coordinate Game::GetNextPosition(Coordinate coordinate, Event event) {
    switch(event) {
        case UP_EVENT: return Coordinate(coordinate.x, --(coordinate.y));
        case DOWN_EVENT: return Coordinate(coordinate.x, ++(coordinate.y));
        case RIGHT_EVENT: return Coordinate(++(coordinate.x), coordinate.y);
        case LEFT_EVENT: return Coordinate(--(coordinate.x), coordinate.y);
    }
}

void Game::MakeMovement(Coordinate nextCoordinate, Player *currentPlayer) {
    BlockType block = field.GetField()[nextCoordinate.ToInt()].GetType();
    if (block == WALL || block == BOX)
        return;
    for (std::vector<Player>::iterator i = player.begin(); i != player.end(); i++) {
        if ((i -> GetPosition() == nextCoordinate) && (i -> IsActive()))
            return;
    }
    for (std::list<Bomb>::iterator i = bomb.begin(); i != bomb.end(); i++) {
        if (i -> GetPosition() == nextCoordinate)
            return;
    }
    currentPlayer->SetPosition(nextCoordinate);
    SendMovePlayer(currentPlayer->GetId(), nextCoordinate.ToInt());
}

void Game::Step() {
    while (clientCount > 1) {
        if (!clientAction.empty()) {
            ClientAction currentChange = clientAction.front();  //  get Change from queue
            clientAction.pop();   //  delete Change from queue
            Event currentEvent = currentChange.event;
            unsigned int currentId = currentChange.id;
            Player *currentPlayer = FindPlayer(currentId);

            if (currentPlayer->IsActive()) {
                //  Player movement
                if (currentEvent >= UP_EVENT && currentEvent <= RIGHT_EVENT) {
                    Coordinate currentCoordinate = currentPlayer->GetPosition();
                    Coordinate nextCoordinate = GetNextPosition(currentCoordinate, currentEvent);
                    MakeMovement(nextCoordinate, currentPlayer);
                }
                // Bomb is set
                if (currentEvent == SET_BOMB_EVENT) {
                    if (currentPlayer->GetBomb() > 0) {
                        currentPlayer->PutBomb();
                        Bomb newBomb(currentPlayer->GetPosition(), currentId);
                        for (std::list<Bomb>::iterator i = bomb.begin(); i != bomb.end(); i++)
                            if (i -> GetPosition() == newBomb.GetPosition())
                                continue;
                        CreateBomb(newBomb);
                        SendBombPlanted(newBomb.GetId(), newBomb.GetPosition().ToInt());
                        boost::thread(boost::bind(DestroyBomb, this));
                        continue;
                    }
                }
            }
        }
        boost::this_thread::sleep_for(boost::chrono::microseconds(250));
    }
    boost::this_thread::sleep_for(boost::chrono::seconds(5));
    for(std::vector<Player>::iterator it = player.begin(); it != player.end(); it++) {
        if (it->IsActive()) {
            SendEndGame(it->GetId());
            break;
        }
    }
}

std::string Game::GetMap() {
    return field.FieldToString();
}


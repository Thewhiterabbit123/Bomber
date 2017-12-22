#include "Game.h"
#include "Player.h"
#include "Field.h"

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

void Game::DestroyBomb(const boost::system::error_code& e, const Game& game) {

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

        boost::this_thread::sleep_for(boost::chrono::milliseconds(1));

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


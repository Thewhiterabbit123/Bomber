#include "Server.h"


#define CLIENT_COUNT 4 

int portNum = 8001;
typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;
boost::asio::io_service service;
socket_ptr usersSockPtrs[CLIENT_COUNT];
int playersId [CLIENT_COUNT];

std::queue<std::string> sendQueues[CLIENT_COUNT];

Game game;




void client_session(socket_ptr sock, int threadNum)
 {
 	int clientId = playersId[threadNum];
 	std::cout << "thread: " << clientId << endl;
	Event startEvent = START_GAME;
	std::stringstream line;
   	line << startEvent << " " << game.GetMap();
	for (int i = 0; i < CLIENT_COUNT; i++) {
 		std::string nickName = game.GetPlayerNameById(playersId[i]);
 		line << " " << playersId[i] << " " << nickName << game.GetPlayerPositionById(playersId[i]);
 	}
	std::string msg = line.str(); 	
	try {
		sock->send(boost::asio::buffer(msg)); 
	}
	catch(boost::system::system_error e) {
		std::cout << e.code() << std::endl;
		return;
	}
 	msg.resize(0);

    while (true)
    {
    	if(sock->available()) {
    		char buff[512];
			int bytes = 0;
			try {
				bytes = sock->receive(boost::asio::buffer(buff));
			}
			catch(boost::system::system_error e) {
				std::cout << e.code() << std::endl;
				continue;
			}
			if (bytes > 0){
				std::string packetStr(buff, bytes);
			    std::stringstream stream(packetStr);
			    int typeOfPacket = 0;
				stream >> typeOfPacket;
				ClientAction action(clientId, (Event)typeOfPacket);
				game.PushClientAction(action);
			}
    	}

    	if (!sendQueues[threadNum].empty()) {
    		while(!sendQueues[threadNum].empty()) {
    			std::string msg = sendQueues[threadNum].front();
    			try {
					sock->send(boost::asio::buffer(msg)); 
					}
				catch(boost::system::system_error e) {
					std::cout << e.code() << std::endl;
					continue;
				}
				sendQueues[threadNum].pop();
    		}
    	}
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
    }
}





void server_loop() 
{
	int playersCount = 0;
	boost::asio::ip::tcp::acceptor acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),portNum));
	std::cout << "Server run on port: " << portNum << std::endl;
	while ( playersCount < CLIENT_COUNT) 
	{	
		char buff[512];
    	socket_ptr sock(new boost::asio::ip::tcp::socket(service));
	    acceptor.accept(*sock);
	    usersSockPtrs[playersCount] = sock;
	    int bytes = 0;
	    try {
		    	bytes = sock->receive(boost::asio::buffer(buff));
			}
		catch(boost::system::system_error e) {
			std::cout << e.code() << std::endl;
			continue;
		}

	    std::string nickName(buff, bytes);
	   	int playerId = game.CreatePlayer(nickName);
	   	playersId[playersCount] = playerId;

	   	Event event = SEND_ID;
		std::stringstream line;
	   	line << event << " " << playerId;
		std::string idPack = line.str();	    
	    try {
			sock->send(boost::asio::buffer(idPack)); 
			}
		catch(boost::system::system_error e) {
			std::cout << e.code() << std::endl;
			continue;
		}
		std::cout << "player: " << playerId << " conected" <<std::endl;   
	    playersCount++;
	}

	for (int i = 0; i < CLIENT_COUNT; i++){
		boost::thread(boost::bind(client_session, usersSockPtrs[i], i));
	}

	//game.

	while (true) 
    	boost::this_thread::sleep_for(boost::chrono::microseconds(250));

}



void SendMovePlayer(int idPlayer, int coord) {
	Event event = MOVE_PLAYER;
	std::stringstream line;
	line << event << " " << idPlayer << " " << coord;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
	
}

void SendBombPlanted (int id, int coord) {
	Event event = BOMB_EVENT;
	Event bombAction = BOMB_PLANTED;
	std::stringstream line;
	line << event << " " << id << " " << bombAction << " " << coord;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}

void SendBombExplode (int id, int radius=1) {
	Event event = BOMB_EVENT;
	Event bombAction = BOMB_EXPLODE;
	std::stringstream line;
	line << event << " " << id << " " << bombAction;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}

void SendPlayerDead (int idPlayer) {
	Event event = PLAYER_DEAD;
	std::stringstream line;
	line << event << " " << idPlayer;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}

void SendPlusHP(int idPlayer) {
	;
}

void SendMinusHP(int idPlayer) {
	;
}

void SendBoxExplode(int id, int newType=1) {
	Event event = BOX_EXPLODE;
	std::stringstream line;
	line << event << " " << id;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}

void SendEndGame(int idPlayer) {
	Event event = END_GAME;
	std::stringstream line;
	line << event << " " << idPlayer;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}



int main(int argc, char* argv[]) 
{	
	if (argc > 1) {
		int port = atoi(argv[1]);
		if(port > 2000){
			portNum = port;
		}
	}
	server_loop();

	return 0;
}

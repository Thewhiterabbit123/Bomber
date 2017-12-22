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
 	std::cout << "game: " << clientId << endl;
 	//  SEND MAP
 	std::string msg;
 	msg += "20"; // код пакета (можно даже не отправлять)
 	for (int i = 0; i < CLIENT_COUNT; i++) {
 		std::string nickName = game.GetPlayerNameById(playersId[i]);
 		msg += ' '; msg += playersId[i] + '0'; msg += ' '; msg += nickName;
 	}
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
				///
			}
    	}

    	if (!sendQueues[threadNum].empty()) {
    		;//while(!empty ) do send;
    		/////////
   //  		try {
			// 	sock->send(boost::asio::buffer(idPack)); 
			// }
			// catch(boost::system::system_error e) {
			// 	std::cout << e.code() << std::endl;
			// 	continue;
			// }
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
		std::string idPack;
		idPack += "00 ";
		idPack += '0' + playerId;
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
	while (true) 
    	boost::this_thread::sleep_for(boost::chrono::milliseconds(1));


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

void SendBombPlanted (int coord) {
	Event event = BOMB_PLANTED;
	std::stringstream line;
	line << event << " " << idPlayer << " " << coord;
	std::string msg = line.str();

	for (int i = 0; i < CLIENT_COUNT; i++) {
		sendQueues[i].push(msg);
	}
}

void SendBombExplode (int coord, int radius=1) {
	;
}

void SendPlayerDead (int idPlayer) {
	;
}

void SendPlusHP(int idPlayer) {
	;
}

void SendMinusHP(int idPlayer) {
	;
}

void SendBoxExplode(int coord, int newType) {
	;
}


int main(int argc, char* argv[]) 
{	
	// Event event = MOVE_PLAYER;
	// //char buf[10];
	// std::stringstream mystream;
	// mystream << event;
	// std::string str;
	// //mystream >> str;
	// std::cout << str << " " << str.size() << std::endl;
	// //mystream.seekp(0);
	// mystream << 458;
	// mystream >> str;
	// std::cout << str << " " << str.size() << std::endl;
	if (argc > 1) {
		int port = atoi(argv[1]);
		if(port > 2000){
			portNum = port;
		}
	}
	server_loop();
}

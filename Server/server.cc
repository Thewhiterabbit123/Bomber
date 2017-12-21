#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include <vector>
#include "Game.h"
#include "../Define.h"


#define CLIENT_COUNT 4 

int portNum = 8001;
typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;
boost::asio::io_service service;
socket_ptr usersSockPtrs[CLIENT_COUNT];
int playersId [CLIENT_COUNT];


Game game;

void client_session(socket_ptr sock, int clientId)
 {
 	std::cout << "game: " << clientId << endl;
 	//  SEND MAP
 	std::string msg;
 	msg += "20";
 	for (int i = 0; i < CLIENT_COUNT; i++) {
 		std::string nickName = game.
 		msg += ' '; msg += playersId[i] + '0'; msg += ' '; msg += nickName;
 	}
	try {
		sock->send(boost::asio::buffer(msg)); 
	}
	catch(boost::system::system_error e) {
		std::cout << e.code() << std::endl;
		continue;
	}
 	msg.resize(0);
 	//  GET NAMES
 	//  SEND NAMES + ID

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

    	if (0/*  EVENT  */) {;
    		/////////
   //  		try {
			// 	sock->send(boost::asio::buffer(idPack)); 
			// }
			// catch(boost::system::system_error e) {
			// 	std::cout << e.code() << std::endl;
			// 	continue;
			// }
    	}
   //   	if(sock->available()){
	  //       char buff[512];
	  //       // size_t len = sock->read_some(buffer(buff));
	  //       // if ( len > 0) 
	  //       // write(*sock, buffer("ok", 2));
	  //       int bytes = read(*sock, buffer(buff), boost::bind(read_complete,buff,_1,_2));
	  //       std::string msg(buff, bytes);
	  //       sock->write_some(buffer(msg));
	  //       std::string::size_type n = msg.find(std::string("exit"));
	  //       if (n != std::string::npos)
	  //       	return;
	  //   }
	  //   else {
	  //   	try{
		 //    	sock->write_some(buffer(std::string("WAIT\n")));
			// }
			// catch(boost::system::system_error e) 
			// {
			// 	std::cout << e.code() << std::endl;
			// 	return;
			// }
	  //   	//sleep(10);
	  //   }
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
		boost::thread(boost::bind(client_session, usersSockPtrs[i], playersId[i]));
	}
	while (true) ;

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
}

//  sock.available()
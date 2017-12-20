#pragma once
#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include "Game.h"

#define CLIENT_COUNT 4
using namespace boost::asio;
using namespace boost::system;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
io_service service;
socket_ptr usersSockPtrs[CLIENT_COUNT];
Game game;

size_t read_complete(char * buff, const error_code & err, size_t bytes) 
{
	if ( err) return 0;
	bool found = std::find(buff, buff + bytes, '\n') < buff + bytes;
	// we read one-by-one until we get to enter, no buffering
	return found ? 0 : 1;
}

void client_session(socket_ptr sock)
 {
    while (true)
     {
     	if(sock->available()){
	        char buff[512];
	        // size_t len = sock->read_some(buffer(buff));
	        // if ( len > 0) 
	        // write(*sock, buffer("ok", 2));
	        int bytes = read(*sock, buffer(buff), boost::bind(read_complete,buff,_1,_2));
	        std::string msg(buff, bytes);
	        sock->write_some(buffer(msg));
	        std::string::size_type n = msg.find(std::string("exit"));
	        if (n != std::string::npos)
	        	return;
	    }
	    else {
	    	sock->write_some(buffer(std::string("WAIT\n")));
	    	//sleep(10);
	    }
    }
}

void server_loop() 
{
	int playersCount = 0;
	ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(),8001));
	while ( playersCount < CLIENT_COUNT) 
	{	
		char buff[512];
    	socket_ptr sock(new ip::tcp::socket(service));
	    acceptor.accept(*sock);
	    usersSockPtrs[playersCount] = sock;
	    int bytes = read(*sock, buffer(buff), boost::bind(read_complete,buff,_1,_2));
	    std::string msg(buff, bytes);

	   	int playerId = game.CreateUser() 
	    
	    playersCount++;
    	//boost::thread(boost::bind(client_session, sock));
	}
	for (int i = 0; i < CLIENT_COUNT; i++){
		boost::thread(boost::bind(client_session, usersSockPtrs[i]));
	}
	while (true) ;

}

int main(int argc, char* argv[]) 
{
	server_loop();
}

//  sock.available()
#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include "Parse.h"
class Client {
	public:
        Client();
        ~Client();
		void disconnect();
        void Connect();
        std::string getMessage();
        void sendMessage(std::string);
        void setMyId(int);

	private: 
        std::ofstream logfile;

        int myId;
        int _port;

        std::string myName;
        std::string _host;

        boost::asio::io_service service;
        boost::asio::ip::tcp::socket *socket;

        void getParam();
};

#endif

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
        void getMessage();
        void sendMessage(std::string);
        std::string makeString(boost::asio::streambuf&);

	private: 
        std::ofstream logfile;

        int myId;
        int _port;
        Parser parse;

        std::string _host;
        std::string inputMessage;
        std::string outputMessage;

        boost::asio::io_service service;
        boost::asio::ip::tcp::socket *socket;

        void getParam();
};

#endif

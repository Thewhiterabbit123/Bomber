#include "Client.h"
#include <iostream>
#include <map>
#include <fstream>
#include "Parse.h"

Client::Client() {
    socket = new boost::asio::ip::tcp::socket(service);

    logfile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
    try {
        logfile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/client.log");
        this->getParam();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening/reading/closing log file\n";
    }
    std::cout << "THIS IS CONSTRUCTOR OF CLIENT\n";
}

void Client::Connect() {
     socket->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(_host), _port));
}

void Client::getParam() {
    std::ifstream configFile;
    configFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        configFile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/config.conf");
        configFile >> this->_host >> this->_port;
        std::cout << _host << " " << _port << '\n';
    } catch (std::ifstream::failure e) {
        logfile << " cant open conf configFile";
    }

    configFile.close();
}

void Client::disconnect() {
}

void Client::getMessage() {
    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;
    boost::asio::read(*socket, receive_buffer, boost::asio::transfer_all(), error);

    if(error && error != boost::asio::error::eof) {
        std::cout << "receive failed: " << error.message() << std::endl;
    } else {
        inputMessage = makeString(receive_buffer);
        parse.parseLine(inputMessage);
    }
}

void Client::sendMessage(std::string msg) {
     boost::system::error_code error;
     boost::asio::write(*socket, boost::asio::buffer(msg), error);

     if(error) {
       std::cout << "send failed: " << error.message() << std::endl;
     } else {
       std::cout << "send correct!" << std::endl;
   }
}

std::string Client::makeString(boost::asio::streambuf& streambuf) {
  return {boost::asio::buffers_begin(streambuf.data()),
          boost::asio::buffers_end(streambuf.data())};
}


Client::~Client() {
    logfile.close();
    delete socket;
}



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
     std::cout << "CONNECT\n";
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

std::string Client::getMessage() {
    char msg[1024];
    int len = socket->receive(boost::asio::buffer(msg));
    std::string inputMessage(msg, len);
    std::cout << inputMessage << std::endl;
    return inputMessage;
}

void Client::sendMessage(std::string msg) {
     boost::system::error_code error;
     boost::asio::write(*socket, boost::asio::buffer(msg), error);
     std::cout << "SEND\n";
     if(error) {
       std::cout << "send failed: " << error.message() << std::endl;
       logfile << "send failed: " << error.message() << std::endl;
     } else {
       std::cout << "send correct!" << std::endl;
       logfile << "send correct!" << std::endl;
   }
}


Client::~Client() {
    logfile.close();
    delete socket;
}


void Client::setMyId(int id) {
    myId = id;
}

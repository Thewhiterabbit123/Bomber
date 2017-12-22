#include "Client.h"
#include <iostream>
#include <map>
#include <fstream>
#include "Parser.h"

#define BUFFSIZE 1024

Client::Client() {
    socket = new boost::asio::ip::tcp::socket(service);

    logfile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
    try {
        logfile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/client.log");
        this->getParam();
    } catch (std::ofstream::failure e) {
        std::cerr << "EXEPTION LOGFILE" << std::endl;
    }
}

void Client::Connect() {
     socket->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(_host), _port));
     logfile << "I'VE BEEN CONNECTED TO " << _host << " ON PORT " << _port << std::endl;
}

void Client::getParam() {
    std::ifstream configFile;
    configFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        configFile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/config.conf");
        configFile >> this->_host >> this->_port;
        std::cout << _host << " " << _port << '\n';
    } catch (std::ifstream::failure e) {
        logfile << "EXEPTION CONFIGFILE" << std::endl;
    }

    configFile.close();
}

std::string Client::getMessage() {
    char msg[BUFFSIZE];
    int len = socket->receive(boost::asio::buffer(msg));
    std::string inputMessage(msg, len);
    std::cout << inputMessage << std::endl;
    return inputMessage;
}

void Client::sendMessage(std::string msg) {
     boost::system::error_code error;
     boost::asio::write(*socket, boost::asio::buffer(msg), error);

     if(error) {
       logfile << "send failed: " << error.message() << std::endl;
     }
}


Client::~Client() {
    boost::system::error_code err;
    socket->close(err);
    logfile.close();
    delete socket;
}


void Client::setMyId(int id) {
    myId = id;
}

std::string Client::prepareMessageToServer(int event) {
    std::string msg;
    msg += (myId + '0') + ' ' + (event + '0') + ' ';
    return msg;
}

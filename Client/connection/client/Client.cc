#include "Client.h"
#include <iostream>
#include <map>
#include <fstream>
#include "Parser.h"

#define BUFFSIZE 1024


void Client::Connect() {
     //socket->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(_host), _port));

    logfile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
    try {
        logfile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/client.log");
        this->getParam();
    } catch (std::ofstream::failure e) {
        std::cerr << "EXEPTION LOGFILE" << std::endl;
    }

    logfile << "I'VE BEEN CONNECTED TO " << _host << " ON PORT " << _port << std::endl;

    socket = new QTcpSocket(this);
    socket->connectToHost(QString::fromStdString(_host),_port);
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
    std::string inputMessage;
    while(socket->canReadLine()) {
        inputMessage = QString::fromUtf8(socket->readLine()).trimmed().toStdString();
    }

    return inputMessage;
}

void Client::sendMessage(std::string msg) {

     socket->write(QString::fromStdString(msg).toUtf8());
}


Client::~Client() {
    socket->disconnectFromHost();
    delete socket;
    logfile.close();
}


void Client::setMyId(int id) {
    myId = id;
}

std::string Client::prepareMessageToServer(int event) {
    std::string msg;
    msg += (myId + '0') + ' ' + (event + '0') + ' ';
    return msg;
}

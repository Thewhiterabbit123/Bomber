#include "Client.h"
#include <iostream>
#include <map>
#include <fstream>
#include <QDebug>
#include "Parser.h"
#include <sstream>

#define BUFFSIZE 1024

Client::Client( std::string name, QObject* parent): QObject(parent) {
    myName = name;
    logfile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
    try {
        logfile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/client.log");
        this->getParam();
    } catch (std::ofstream::failure e) {
        std::cerr << "EXEPTION LOGFILE" << std::endl;
    }

    logfile << "I'VE BEEN CONNECTED TO " << _host << " ON PORT " << _port << std::endl;

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(CloseClientConnection()));

    socket->connectToHost(QString::fromStdString(_host),_port);
    socket->waitForConnected(1000);
};


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

std::string Client::getInputMessage() {
    return inputMessage;
}

void Client::readyRead() {
    while(socket->bytesAvailable()) {
        inputMessage = QString::fromUtf8(socket->readLine()).trimmed().toStdString();
        std::cout << inputMessage << std::endl;
    }
    emit socketGetMessage();
}

void Client::sendMessage(std::string msg) {
     std::cout << "send message" << std::endl;
     socket->write(QString::fromStdString(msg).toUtf8());
     socket->flush();
     socket->waitForBytesWritten();
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
    std::stringstream stream;
    switch(event) {
        case 2: {
            stream << DOWN_EVENT;
            break;
        }
        case 8: {
            stream << UP_EVENT;
            break;
        }
        case 4: {
            stream << LEFT_EVENT;
            break;
        }
        case 6: {
            stream << RIGHT_EVENT;
            break;
        }
        case 5: {
            stream << SET_BOMB_EVENT;
            break;
        }
    }
    return stream.str();
}

void Client::connected() {
    std::cerr << "connected" << std::endl;
    if(myName.size() == 0) {
        myName = "USER!";
    }
    sendMessage(myName);
}

void Client::CloseClientConnection() {
    std::cout << "DISCONNECTED" << std::endl;
}

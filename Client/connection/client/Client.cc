#include "Client.h"
#include "Parser.h"

#define BUFFSIZE 1024

Client::Client(std::string name, QObject* parent): QObject(parent) {
    myName = name;
    getParam();
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
        //std::cout << _host << " " << _port << '\n';
    } catch (std::ifstream::failure e) {
        std::cerr << "EXEPTION CONFIGFILE" << std::endl;
    }

    configFile.close();
}

std::string Client::getInputMessage() {
    return inputMessage;
}

void Client::readyRead() {
    while(socket->bytesAvailable()) {
        inputMessage = QString::fromUtf8(socket->readLine()).trimmed().toStdString();
       // std::cout << inputMessage << std::endl;
    }
    std::string message;
    std::stringstream stream(inputMessage);
    while(std::getline(stream, message, '|')) {
        messageQueue.push(message);
        std::cout << messageQueue.front() << "ETTO IS READYREAD" << std::endl;
    }

    emit socketGetMessage();
}

void Client::sendMessage(std::string msg) {
     socket->write(QString::fromStdString(msg).toUtf8());
     socket->flush();
     socket->waitForBytesWritten();
}


Client::~Client() {
    socket->disconnectFromHost();
    delete socket;
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

std::queue<std::string> Client::getMessageQueue() {
    return messageQueue;
}

std::string Client::getOneMessageFromQueue() {
    std::string message = messageQueue.front();
    std::cout << messageQueue.front() << "this is gEtoNe..." << std::endl;
    messageQueue.pop();
    return message;
}

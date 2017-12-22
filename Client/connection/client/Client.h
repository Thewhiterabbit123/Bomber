#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <map>
#include <fstream>
#include <QTcpSocket>
#include "Parser.h"
#include <QObject>

class Client: public QObject {
    Q_OBJECT
	public:
        Client(QObject* parent = 0): QObject(parent) {};
        ~Client();
        void Connect();
        std::string getMessage();
        void sendMessage(std::string);
        void setMyId(int);
        std::string prepareMessageToServer(int);

	private: 
        std::ofstream logfile;

        int myId;
        int _port;

        std::string myName;
        std::string _host;

        QTcpSocket *socket;
        //boost::asio::io_service service;
        //boost::asio::ip::tcp::socket *socket;

        void getParam();
};

#endif

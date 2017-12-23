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
        Client(std::string name, QObject* parent = 0);
        ~Client();
        std::string getMessage();
        void sendMessage(std::string);
        void setMyId(int);
        std::string prepareMessageToServer(int);
        std::string getInputMessage();

    private slots:
        void readyRead();
        void connected();
        void CloseClientConnection();
    signals:
        void socketGetMessage();

	private: 
        std::ofstream logfile;

        int myId;
        int _port;

        std::string myName;
        std::string _host;
        std::string inputMessage;

        QTcpSocket *socket;

        void getParam();
};

#endif

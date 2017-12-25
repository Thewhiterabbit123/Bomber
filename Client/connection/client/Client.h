#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <map>
#include <fstream>
#include <QTcpSocket>
#include "Parser.h"
#include <QObject>
#include <queue>
#include <sstream>

class Client: public QObject {
    Q_OBJECT
	public:
        Client(std::string name, QObject* parent = 0);
        ~Client();
        void sendMessage(std::string);
        void setMyId(int);
        std::string getMessage();
        std::string prepareMessageToServer(int);
        std::string getInputMessage();
        std::string getOneMessageFromQueue();
        std::queue<std::string> getMessageQueue();

    private slots:
        void readyRead();
        void connected();
        void CloseClientConnection();

    signals:
        void socketGetMessage();

	private: 
        int myId;
        int _port;

        std::string myName;
        std::string _host;
        std::string inputMessage;

        std::queue<std::string> messageQueue;

        QTcpSocket *socket;

        void getParam();
};

#endif

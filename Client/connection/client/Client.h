#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <map>
#include <fstream>
#include "Parse.h"
class Client {
	public:
        Client();
		void disconnect();
        void doConnect();
		void getMessage();

	private: 
        std::ofstream logfile;

        int myId;
        int _port;
		std::string _host;
		//std::string _msg;
        Parser parse;

        void getParam();
};
//инициализация - мне отправляют std::string в формате: ай-ди сообщения и айди - имя клиента и его айди. 
//После этого можно удалять все имена на сервере
#endif

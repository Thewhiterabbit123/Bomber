#include "Client.h"
#include <iostream>
#include <map>
#include <fstream>
#include "Parse.h"

Client::Client() {
    logfile.exceptions (std::ofstream::failbit | std::ofstream::badbit);
    try {
        logfile.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/client.log");
        this->getParam();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening/reading/closing log file\n";
    }
}

void Client::doConnect() {

}

void Client::getParam() {
    std::ifstream file;
    file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        file.open("/home/nadia/Technopark/project/Bomber/Client/connection/client/config.conf");
        file >> this->_host >> this->_port;
        std::cout << _host << " " << _port << '\n';
    } catch (std::ifstream::failure e) {
        logfile << " cant open conf file";
    }

    file.close();
}

void Client::disconnect() {
}

void Client::getMessage() {
    parse.parseLine("2 kjnhpohpoihj 2 2 3 4 2 3 1 2 4 3 2 4");
    std::cout << parse.getMyId("lol");

}

//Client::~Client() {
//	logfile.close();
//}



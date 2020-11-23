#include <iostream>
#include <utility>
#include <sstream>
#include <cstring>
#include <string>
#include "client_processor.h"

#define BUFF_SIZE 64

ClientProcessor::ClientProcessor(Socket socket, const ResourceList &list) :
        socket(std::move(socket)), resourceList(list) {
    this->is_alive = true;
}

std::string ClientProcessor::getProtocolFromClient() {
    std::stringstream s;
    int cont = BUFF_SIZE;
    while (cont == BUFF_SIZE) {
        char buf[BUFF_SIZE];
        cont = this->socket.recv(buf, BUFF_SIZE);
        s.write(buf, cont);
    }
    return s.str();
}

Protocol ClientProcessor::createProtocol(std::string protocolStr) {
    std::stringstream stream(protocolStr);
    std::string line;
    std::getline(stream, line);

    bool body_start = false;
    std::string temp;
    std::stringstream body;
    long bodyLen = 0;


    while (std::getline(stream, temp)) {
        if (temp.find("Content-Length") != std::string::npos) {
            bodyLen = stol(temp.substr(temp.find(":") + 2));
        }
        if (body_start && body.tellp() != bodyLen) {
            body << temp << std::endl;
        }
        body_start = body_start || temp.empty();
    }

    Protocol protocol(line, body.str());
    return protocol;
}

void ClientProcessor::run() {
    std::string protocolStr = getProtocolFromClient();
    Protocol protocol = createProtocol(protocolStr);

    std::cout << protocol.getFirstLine() << std::endl;
    std::string resp = protocol.getMethod(resourceList)->process();

    char *my_argument = const_cast<char *> (resp.c_str());
    this->socket.send(my_argument, resp.length());
    this->socket.closeRead();
    this->socket.closeWrite();
    this->is_alive = false;
}

bool ClientProcessor::isAlive() {
    return this->is_alive;
}

ClientProcessor::~ClientProcessor() {
    this->join();
}

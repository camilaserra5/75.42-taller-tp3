#include <iostream>
#include <utility>
#include <sstream>
#include <cstring>
#include <string>
#include "client_processor.h"

ClientProcessor::ClientProcessor(Socket socket, const ResourceList &list) :
        socket(std::move(socket)), resourceList(list) {
    this->is_alive = true;
}

std::string ClientProcessor::getProtocolFromClient() {
    std::string protocolStr = "";
    int cont = 64;
    while (cont == 64) {
        char buf[64];
        memset(buf, 0, sizeof(buf));
        cont = this->socket.recv(buf, 64);
        for (unsigned int i = 0; i < sizeof(buf); i++)
            protocolStr.push_back(buf[i]);
    }
    return protocolStr;
}

Protocol ClientProcessor::createProtocol(std::string protocolStr) {
    std::stringstream stream(protocolStr);
    std::string line;
    std::getline(stream, line);

    bool body_start = false;
    std::string temp;
    std::stringstream body;

    while (std::getline(stream, temp)) {
        if (body_start) {
            body << temp << std::endl;
        }
        body_start = body_start || temp.empty();
    }

    std::string bodyStr = body_start ?
                          body.str().erase(body.str().size() - 1) : "";
    Protocol protocol(line, bodyStr);
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

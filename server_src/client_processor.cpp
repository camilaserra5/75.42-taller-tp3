#include "client_processor.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include "../common_src/protocol.h"

ClientProcessor::ClientProcessor(Socket socket) : socket(std::move(socket)) {
    this->is_alive = true;
}

void ClientProcessor::run() {
    std::string protocolStr;
    int cont = 64;
    while (cont == 64) {
        char buf[64];
        memset(buf, 0, sizeof(buf));
        cont = this->socket.recv(buf, 64);
        for (char ch: buf) {
            protocolStr.push_back(ch);
        }
    }

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

    Protocol protocol(line, body.str());
    // imprimir primera linea petitorio
    std::cerr << "prim" << protocol.getFirstLine() << std::endl;
    std::cerr << protocol.getMethodStr() << std::endl;
    std::cerr << protocol.getResource() << std::endl;
    std::cerr << protocol.getProtocol() << std::endl;
    std::cerr << "body" << protocol.getBody() << std::endl;

    // enviar response
    char buf[9] = "holahola";
    this->socket.send(buf, 10);
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

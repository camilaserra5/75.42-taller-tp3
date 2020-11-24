#include <iostream>
#include <string>
#include "client.h"
#include "../common_src/tcp_protocol.h"
#include <utility>

#define END_LINE "\n"

Client::Client(Socket socket) : socket(std::move(socket)) {}

void Client::sendStdInputToServer() {
    std::string std_input;
    while (getline(std::cin, std_input)) {
        TCPProtocol::send(this->socket, std_input + END_LINE);
    }
}

void Client::run() {
    sendStdInputToServer();
    this->socket.closeWrite();
    std::cout << TCPProtocol::receive(this->socket);
    this->socket.closeRead();
}

Client::~Client() {}

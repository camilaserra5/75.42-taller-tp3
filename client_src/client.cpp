#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include "client.h"

Client::Client(Socket socket) : socket(std::move(socket)) {}

void Client::run() {
    std::string std_input;
    std::stringstream stream;
    while (getline(std::cin, std_input)) {
        stream << std_input << std::endl;
    }

    while (stream.peek() != EOF) {
        char buf[64];
        memset(buf, 0, sizeof(buf));
        stream.read(buf, 64);
        this->socket.send(buf, 64);
    }
    this->socket.closeWrite();

    int cont = 64;
    while (cont == 64) {
        char buf[64];
        memset(buf, 0, sizeof(buf));
        cont = this->socket.recv(buf, 64);
        for (unsigned int i = 0; i < sizeof(buf); i++) {
            if (buf[i] != 0)
                std::cout << buf[i];
        }

    }

    std::cout << std::endl;

    this->socket.closeRead();
}

Client::~Client() {}

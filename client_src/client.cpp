#include <iostream>
#include <string>
#include "client.h"
#include <sstream>
#include <cstring>

Client::Client(Socket socket) : socket(std::move(socket)) {

}

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
    int offset = 0;
    while (cont == 64) {
        char buf[65];
        cont = this->socket.recv(buf, 64);
        if (cont > 0) {
            std::cout << buf << std::endl;
        }
        offset += cont;
    }
    this->socket.closeRead();
}

Client::~Client() {

}

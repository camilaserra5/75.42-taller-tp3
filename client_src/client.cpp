#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include "client.h"

Client::Client(Socket socket) : socket(std::move(socket)) {}

std::stringstream Client::getStreamFromStdin() {
    std::string std_input;
    std::stringstream stream;
    while (getline(std::cin, std_input)) {
        stream << std_input << std::endl;
    }
    return stream;
}

void Client::sendStreamToServer(std::string str) {
    std::stringstream stream(str);
    while (stream.peek() != EOF) {
        char buf[64];
        memset(buf, 0, sizeof(buf));
        stream.read(buf, 64);
        this->socket.send(buf, 64);
    }
}

std::string Client::getResponse() {
    std::stringstream stream;
    int cont = 64;
    while (cont == 64) {
        char buf[64];
        buf[0] = 0;
        memset(buf, 0, sizeof(buf));
        cont = this->socket.recv(buf, 64);
        for (unsigned int i = 0; i < sizeof(buf); i++) {
            if (buf[i] != 0) {
                stream << buf[i];
            }
        }
    }
    return stream.str();
}

void Client::run() {
    std::stringstream stream = getStreamFromStdin();
    sendStreamToServer(stream.str());
    this->socket.closeWrite();

    std::cout << getResponse();
    this->socket.closeRead();
}

Client::~Client() {}

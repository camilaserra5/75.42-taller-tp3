#include <iostream>
#include <string>
#include <utility>
#include "server.h"

Server::Server(Socket socket, const std::string &rootFile) :
        clientManager(std::move(socket), rootFile) {
    this->clientManager.start();
}

void Server::run() {
    while (std::cin.get() != 'q') {
    }
}

Server::~Server() {}

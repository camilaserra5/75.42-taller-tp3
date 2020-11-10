#include <vector>
#include <iostream>
#include "server.h"
#include <cstring>

Server::Server(Socket socket, std::string rootFile) : clientManager(std::move(socket), rootFile) {
    this->clientManager.start();
}

void Server::run() {
    while (std::cin.get() != 'q') {
    }
}

Server::~Server() {

}
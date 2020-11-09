#include <vector>
#include <iostream>
#include "server.h"

Server::Server(Socket &socket, std::string rootFile) : socket(std::move(socket)), rootFile(rootFile),
                                                       clientManager(socket) {
    this->clientManager.start();
}

void Server::run() {
    std::string input;
    while (input != "q") {
        std::cin >> input;
    }
}

Server::~Server() {

}
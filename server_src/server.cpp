#include <vector>
#include <iostream>
#include "server.h"
#include <cstring>

Server::Server(Socket socket, std::string rootFile) : rootFile(rootFile),
                                                      clientManager(std::move(socket)) {
    this->clientManager.start();
}

void Server::run() {
    while (std::cin.get() != 'q') {
    }
}

Server::~Server() {

}
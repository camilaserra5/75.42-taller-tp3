#include <vector>
#include <iostream>
#include "server.h"

Server::Server(Socket &socket, std::string rootFile) : socket(std::move(socket)), rootFile(rootFile) {
}


void Server::run() {
}

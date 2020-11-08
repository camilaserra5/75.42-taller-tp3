#include <vector>
#include <iostream>
#include "server.h"
#include "client_processor.h"

Server::Server(Socket &socket, std::string rootFile) : socket(std::move(socket)), rootFile(rootFile) {

}

void Server::run() {
    while (true) {
        Socket client = this->socket.accept();
        this->clients.push_back(new ClientProcessor(client));
        this->clients.back()->start();
        for (ClientProcessor *cli : this->clients) {
            if (!cli->isAlive()) {
                delete cli;
            }
        }
    }
}

Server::~Server() {
    for (ClientProcessor *cli : this->clients) {
        delete cli;
    }
    this->join();
}

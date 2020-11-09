#include "client_manager.h"
#include "client_processor.h"
#include <iostream>

ClientManager::ClientManager(Socket socket) : socket(std::move(socket)) {

}

void ClientManager::run() {
    Socket client;
    while ((client = this->socket.accept()).valid()) {
        std::cerr << "new cli!!";
        this->clients.push_back(new ClientProcessor(std::move(client)));
        this->clients.back()->start();

        for (unsigned int i = 0; i < this->clients.size(); i++) {
            if (!this->clients[i]->isAlive()) {
                delete this->clients[i];
                this->clients.erase(this->clients.begin() + i);
                std::cout << "remove client";
            }
        }
    }
}

ClientManager::~ClientManager() {
    std::cout << "cli man close";
    for (ClientProcessor *cli : this->clients) {
        delete cli;
    }
    this->socket.closeRead();
    this->socket.closeWrite();
    this->join();
}
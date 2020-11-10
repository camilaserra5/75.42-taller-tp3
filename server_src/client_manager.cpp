#include "client_manager.h"
#include "client_processor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../common_src/resource_list.h"
ClientManager::ClientManager(Socket socket, std::string rootFile) : socket(std::move(socket)), resourceList() {
    std::ifstream infile(rootFile);
    std::string line;
    std::stringstream content;
    while (std::getline(infile, line)) {
        content << line;
    }
    infile.close();
    this->resourceList.addResource("/", content.str());
}

void ClientManager::run() {
    Socket client;
    while ((client = this->socket.accept()).valid()) {
        this->clients.push_back(new ClientProcessor(std::move(client), this->resourceList));
        this->clients.back()->start();
        for (unsigned int i = 0; i < this->clients.size(); i++) {
            if (!this->clients[i]->isAlive()) {
                delete this->clients[i];
                this->clients.erase(this->clients.begin() + i);
            }
        }
    }
}

ClientManager::~ClientManager() {
    for (ClientProcessor *cli : this->clients) {
        delete cli;
    }
    this->socket.closeRead();
    this->socket.closeWrite();
    this->join();
}
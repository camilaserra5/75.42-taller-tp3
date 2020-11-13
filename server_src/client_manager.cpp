#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include "../common_src/resource_list.h"
#include "client_manager.h"
#include "client_processor.h"

ClientManager::ClientManager(Socket socket, std::string rootFile) :
        socket(std::move(socket)), resourceList() {
    std::ifstream infile(rootFile);
    std::string line;
    std::stringstream content;
    while (std::getline(infile, line)) {
        content << line;
    }
    content << std::endl;
    infile.close();
    this->resourceList("/", content.str());
}

void ClientManager::run() {
    Socket client;
    while ((client = this->socket.accept()).valid()) {
        this->clients.push_back(new ClientProcessor(std::move(client),
                                                    resourceList));
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

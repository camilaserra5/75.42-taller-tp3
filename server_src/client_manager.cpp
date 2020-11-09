#include "client_manager.h"
#include "client_processor.h"
#include <iostream>
ClientManager::ClientManager(Socket &socket) : socket(std::move(socket)) {

}

void ClientManager::run() {
    while (true) {
        Socket client = this->socket.accept();
        std::cout << "new cli!!";
        this->clients.push_back(new ClientProcessor(client));
        this->clients.back()->start();
        for (ClientProcessor *cli : this->clients) {
            if (!cli->isAlive()) {
                delete cli;
            }
        }
    }
}

ClientManager::~ClientManager() {
    for (ClientProcessor *cli : this->clients) {
        cli->join();
        //delete cli;
    }
   // this->join();
}
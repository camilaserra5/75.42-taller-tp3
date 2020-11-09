#include "client_manager.h"
#include "client_processor.h"
#include <iostream>

ClientManager::ClientManager(Socket socket) : socket(std::move(socket)) {


}

void ClientManager::run() {
    while (true) {
        Socket client = this->socket.accept();
        std::cerr << "new cli!!";
        this->clients.push_back(new ClientProcessor(std::move(client)));
        this->clients.back()->start();
        /*for (ClientProcessor *cli : this->clients) {
            if (!cli->isAlive()) {
                delete cli;
            }
        }*/
    }
}

ClientManager::~ClientManager() {
    std::cout << "cli man close";
    for (ClientProcessor *cli : this->clients) {
        //cli->join();
        delete cli;
    }
    this->socket.close();
    this->join();
}
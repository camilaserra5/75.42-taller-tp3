#include "client_manager.h"
#include "client_processor.h"

ClientManager::ClientManager(Socket &socket) : socket(std::move(socket)) {

}

void ClientManager::run() {
    while (true) {
        Socket client = this->socket.accept();
        this->clients.push_back(new ClientProcessor(client));
        this->clients.back()->start();
    }
}

int ClientManager::numberOfClients() {
    return this->clients.size();
}

ClientManager::~ClientManager() {

}
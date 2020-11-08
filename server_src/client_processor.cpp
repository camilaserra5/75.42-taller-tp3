#include "client_processor.h"
#include <iostream>
ClientProcessor::ClientProcessor(Socket &socket) : socket(std::move(socket)) {
    this->is_alive = true;
}

void ClientProcessor::run() {
}

bool ClientProcessor::isAlive() {
    return this->is_alive;
}

ClientProcessor::~ClientProcessor() {
    this->is_alive = false;
}

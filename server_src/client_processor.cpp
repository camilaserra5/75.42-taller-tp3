#include "client_processor.h"
#include <iostream>
ClientProcessor::ClientProcessor(Socket &socket) : socket(std::move(socket)) {
    this->is_alive = true;
}

void ClientProcessor::run() {
    std::cout << "cli proc run!";
    this->is_alive = false;
}

bool ClientProcessor::isAlive() {
    return this->is_alive;
}

ClientProcessor::~ClientProcessor() {
    this->is_alive = false;
   // this->join();
}

#include <iostream>
#include "client.h"

Client::Client(Socket &socket) : socket(std::move(socket)) {

}

void Client::run() {
}

Client::~Client() {
//    delete this->socket;
}

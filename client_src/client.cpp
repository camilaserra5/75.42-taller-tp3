#include <iostream>
#include "client.h"

Client::Client(Socket &socket) : socket(std::move(socket)) {

}

void Client::run() {

}

Client::~Client() {
    // todo should close socket ?
}

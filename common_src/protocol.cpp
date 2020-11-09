#include "protocol.h"
#include <iostream>
#include <cstring>

Protocol::Protocol(std::string line, std::string body) : line(line), body(body) {
    std::stringstream ss(this->line);
    std::string temp;
    while (ss >> temp) {
        this->tokens.push_back(temp);
    }
}

std::string Protocol::getFirstLine() {
    return line;
}

std::string Protocol::getMethod() {
    return this->tokens.at(0);
}

std::string Protocol::getResource() {
    return this->tokens.at(1);
}

std::string Protocol::getProtocol() {
    return this->tokens.at(2);
}

std::string Protocol::getBody() {
    return this->body;
}
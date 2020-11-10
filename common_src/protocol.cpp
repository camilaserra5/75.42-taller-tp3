#include "protocol.h"
#include <iostream>
#include <cstring>

#include "get.h"
#include "get_resource.h"
#include "post.h"
#include "post_resource.h"
#include "unknown_method.h"

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

std::string Protocol::getMethodStr() {
    return this->tokens.at(0);
}


std::unique_ptr <HTTPMethod> Protocol::getMethod() {
    if (getMethodStr() == "GET") {
        if (getResource() == "/") {
            return std::unique_ptr<HTTPMethod>(new Get());
        } else {
            return std::unique_ptr<HTTPMethod>(new GetResource(getResource(), getBody()));
        }
    }
    if (getMethodStr() == "POST") {
        if (getResource() == "/") {
            return std::unique_ptr<HTTPMethod>(new Post());
        } else {
            return std::unique_ptr<HTTPMethod>(new PostResource(getResource(), getBody()));
        }
    }
    return std::unique_ptr<HTTPMethod>(new UnknownMethod(getMethodStr()));
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
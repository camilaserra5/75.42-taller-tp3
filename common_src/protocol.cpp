#include "protocol.h"
#include <iostream>
#include <cstring>
#include <string>
#include "get.h"
#include "get_resource.h"
#include "post.h"
#include "post_resource.h"
#include "unknown_method.h"

Protocol::Protocol(const std::string &line, const std::string &body) :
        line(line), body(body) {
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

HTTPMethod *Protocol::createGetMethod(ResourceList resourceList) {
    if (getResource() == "/")
        return new Get(getMethodStr(), resourceList);
    return new GetResource(getResource(), getBody(), resourceList);
}

HTTPMethod *Protocol::createPostMethod(ResourceList resourceList) {
    if (getResource() == "/")
        return new Post(getMethodStr(), resourceList);
    return new PostResource(getResource(), getBody(), resourceList);
}

std::unique_ptr <HTTPMethod> Protocol::getMethod(ResourceList resourceList) {

    if (getMethodStr() == "GET") {
        return std::unique_ptr<HTTPMethod>(createGetMethod(resourceList));
    }
    if (getMethodStr() == "POST") {
        return std::unique_ptr<HTTPMethod>(createPostMethod(resourceList));
    }
    HTTPMethod *unknownMethod = new UnknownMethod(getMethodStr(), resourceList);
    return std::unique_ptr<HTTPMethod>(unknownMethod);
}

std::string Protocol::getResource() {
    return this->tokens.at(1);
}

std::string Protocol::getBody() {
    return this->body;
}

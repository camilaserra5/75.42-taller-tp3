#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <sstream>
#include <vector>
#include "http_method.h"
#include <memory>

class Protocol {
public:
    Protocol(const std::string &line, const std::string &body);

    std::string getFirstLine();

    std::string getMethodStr();

    std::unique_ptr <HTTPMethod> getMethod(ResourceList resourceList);

    std::string getResource();

    std::string getBody();

private:
    std::vector <std::string> tokens;
    std::string line;
    std::string body;
};


#endif //PROTOCOL_H

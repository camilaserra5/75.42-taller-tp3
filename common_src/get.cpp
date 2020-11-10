#include <sstream>
#include <iostream>
#include <string>
#include "get.h"

std::string Get::process(ResourceList resourceList) {
    std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    std::stringstream stream;
    stream << header << resourceList.getResource("/");
    return stream.str();
}

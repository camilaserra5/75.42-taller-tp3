#include "get_resource.h"
#include <sstream>
#include <iostream>
std::string GetResource::process(ResourceList resourceList) {
    std::string content = resourceList.getResource(this->resourceName);
    if (content.empty()) {
        return "HTTP/1.1 404 NOT FOUND\n\n”";
    }
    std::string header = "HTTP/1.1 200 OK\n\n";
    std::stringstream stream;
    stream << header << content;
    return stream.str();
}
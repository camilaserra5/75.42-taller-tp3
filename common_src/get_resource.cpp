#include <sstream>
#include <string>
#include "get_resource.h"

std::string GetResource::process() {
    std::string content = resourceList(this->resourceName);
    if (content.empty()) {
        return "HTTP/1.1 404 NOT FOUND\n\n”";
    }
    std::string header = "HTTP/1.1 200 OK\n\n";
    std::stringstream stream;
    stream << header << content;
    return stream.str();
}

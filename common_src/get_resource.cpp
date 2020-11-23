#include <sstream>
#include <string>
#include "get_resource.h"

#define OK_MSG "HTTP/1.1 200 OK\n\n"
#define ERROR_MSG "HTTP/1.1 404 NOT FOUND\n\n”"

std::string GetResource::process() {
    std::string content = resourceList(this->resourceName);
    if (content.empty()) {
        return ERROR_MSG;
    }
    return OK_MSG + content;
}

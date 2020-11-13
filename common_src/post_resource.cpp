#include <sstream>
#include <string>
#include "post_resource.h"

std::string PostResource::process() {
    resourceList(this->resourceName, this->body);
    std::string header = "HTTP/1.1 200 OK\n\n";

    std::stringstream stream;
    stream << header << this->body;
    return stream.str();
}

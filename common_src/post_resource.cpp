#include "post_resource.h"
#include <sstream>

std::string PostResource::process(ResourceList resourceList) {
    resourceList.addResource(this->resourceName, this->body);
    std::string header = "HTTP/1.1 200 OK\n\n";
    std::stringstream stream;
    stream << header << this->body;
    return stream.str();
}
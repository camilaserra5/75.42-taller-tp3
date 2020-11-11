#include <sstream>
#include <string>
#include "post_resource.h"
#include <iostream>
std::string PostResource::process() {
    resourceList.addResource(this->resourceName, this->body);
    std::string header = "HTTP/1.1 200 OK\n\n";
    std::stringstream stream;
    //std::cout <<  this->body;

    stream << header << this->body;

    return stream.str();
}

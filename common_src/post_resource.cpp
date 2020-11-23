#include <sstream>
#include <string>
#include "post_resource.h"

#define OK_MSG "HTTP/1.1 200 OK\n\n"

std::string PostResource::process() {
    resourceList(resourceName, body);
    return OK_MSG + this->body;
}

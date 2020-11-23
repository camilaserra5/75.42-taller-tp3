#include <sstream>
#include <string>
#include "get.h"

#define BASE_PATH "/"
#define OK_MSG "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"

std::string Get::process() {
    return OK_MSG + resourceList(BASE_PATH);
}

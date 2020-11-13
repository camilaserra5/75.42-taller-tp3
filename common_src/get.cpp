#include <sstream>
#include <string>
#include "get.h"

std::string Get::process() {
    std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    std::stringstream stream;
    stream << header << resourceList.getResource("/");
    return stream.str();
}

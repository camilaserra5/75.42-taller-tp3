#include <string>
#include "post.h"

#define ERROR_MSG "HTTP/1.1 403 FORBIDDEN\n\n"

std::string Post::process() {
    return ERROR_MSG;
}

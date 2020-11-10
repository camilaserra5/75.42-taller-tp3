#include <string>
#include "post.h"

std::string Post::process() {
    return "HTTP/1.1 403 FORBIDDEN\n\n";
}

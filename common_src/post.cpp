#include <string>
#include "post.h"

std::string Post::process(const ResourceList &resourceList) {
    return "HTTP/1.1 403 FORBIDDEN\n\n";
}

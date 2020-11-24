#ifndef POST_RESOURCE_H
#define POST_RESOURCE_H

#include "http_method.h"
#include <string>

/**
 * The PostResource Method. Handles a POST/<resource> HTTP method.
 * The resource with the given name is created with the body content.
 * If the resource already exists, it will be overriden.
 */
class PostResource : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //POST_RESOURCE_H

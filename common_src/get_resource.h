#ifndef GET_RESOURCE_H
#define GET_RESOURCE_H

#include "http_method.h"
#include <string>

/**
 * The GetResource Method. Handles a GET/<resource> HTTP method.
 * Returns the content for the given resource name.
 * 404 if the resource does not exist.
 */
class GetResource : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //GET_RESOURCE_H

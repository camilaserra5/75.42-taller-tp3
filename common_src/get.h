#ifndef GET_H
#define GET_H

#include "http_method.h"
#include <string>

/**
 * The Get Method. Handles a GET/ HTTP method.
 * Returns the content for the root resource.
 */
class Get : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //GET_H

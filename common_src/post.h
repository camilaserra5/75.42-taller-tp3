#ifndef POST_H
#define POST_H

#include "http_method.h"
#include <string>

/**
 * The Post Method. Handles a POST/ HTTP method.
 * Returns 403 forbidden operation.
 */
class Post : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //POST_H

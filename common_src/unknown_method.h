#ifndef UNKNOWN_METHOD_H
#define UNKNOWN_METHOD_H

#include "http_method.h"
#include <string>

/**
 * The Unknown Method. Handles an unknown HTTP method.
 */
class UnknownMethod : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //UNKNOWN_METHOD_H

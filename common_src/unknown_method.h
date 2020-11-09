#ifndef UNKNOWN_METHOD_H
#define UNKNOWN_METHOD_H

#include "http_method.h"
#include <string>

class UnknownMethod : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //UNKNOWN_METHOD_H

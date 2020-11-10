#ifndef GET_H
#define GET_H

#include "http_method.h"
#include <string>

class Get : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process(ResourceList resourceList) override;
};

#endif //GET_H

#ifndef GET_RESOURCE_H
#define GET_RESOURCE_H

#include "http_method.h"
#include <string>

class GetResource : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;


    std::string process(ResourceList resourceList) override;
};

#endif //GET_RESOURCE_H

#ifndef POST_RESOURCE_H
#define POST_RESOURCE_H

#include "http_method.h"
#include <string>

class PostResource : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //POST_RESOURCE_H

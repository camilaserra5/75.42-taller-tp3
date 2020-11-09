#ifndef POST_H
#define POST_H

#include "http_method.h"
#include <string>

class Post : public HTTPMethod {
public:
    using HTTPMethod::HTTPMethod;

    std::string process() override;
};

#endif //POST_H

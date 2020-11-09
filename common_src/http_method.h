#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <string>

class HTTPMethod {
public:
    explicit HTTPMethod();

    virtual std::string process() = 0;
};

#endif //HTTP_METHOD_H

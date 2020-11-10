#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <string>
#include "resource_list.h"

class HTTPMethod {
public:
    explicit HTTPMethod();

    explicit HTTPMethod(std::string methodName);

    explicit HTTPMethod(std::string resourceName, std::string body);

    virtual std::string process(ResourceList resourceList) = 0;

protected:
    std::string methodName;
    std::string resourceName;
    std::string body;
};

#endif //HTTP_METHOD_H

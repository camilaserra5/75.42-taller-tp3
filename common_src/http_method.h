#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <string>
#include "resource_list.h"

class HTTPMethod {
public:
    HTTPMethod();

    explicit HTTPMethod(const std::string &methodName);

    HTTPMethod(const std::string &resourceName, const std::string &body);

    virtual std::string process(ResourceList resourceList) = 0;

protected:
    std::string methodName;
    std::string resourceName;
    std::string body;
};

#endif //HTTP_METHOD_H

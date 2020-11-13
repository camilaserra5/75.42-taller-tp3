#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <string>
#include "resource_list.h"

class HTTPMethod {
public:
    explicit HTTPMethod(const std::string &methodName,
                        const ResourceList &resourceList);

    HTTPMethod(const std::string &resourceName,
               const std::string &body,
               const ResourceList &resourceList);

    virtual std::string process() = 0;

protected:
    std::string methodName;
    std::string resourceName;
    std::string body;
    ResourceList resourceList;
};

#endif //HTTP_METHOD_H

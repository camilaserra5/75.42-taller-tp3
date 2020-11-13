#include <string>
#include "http_method.h"

HTTPMethod::HTTPMethod(const std::string &methodName,
                       const ResourceList &resourceList) :
        methodName(methodName),
        resourceList(resourceList) {}

HTTPMethod::HTTPMethod(const std::string &resourceName,
                       const std::string &body,
                       const ResourceList &resourceList) :
        resourceName(resourceName),
        body(body),
        resourceList(resourceList) {}

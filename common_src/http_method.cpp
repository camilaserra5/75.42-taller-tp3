#include <string>
#include "http_method.h"

HTTPMethod::HTTPMethod() {}

HTTPMethod::HTTPMethod(const std::string &methodName) :
        methodName(methodName) {}

HTTPMethod::HTTPMethod(const std::string &resourceName,
                       const std::string &body,
                       const ResourceList &resourceList) :
        resourceName(resourceName), body(body), resourceList(resourceList) {}

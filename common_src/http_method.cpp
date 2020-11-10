#include "http_method.h"

HTTPMethod::HTTPMethod() {

}

HTTPMethod::HTTPMethod(std::string methodName) : methodName(methodName) {
    
}

HTTPMethod::HTTPMethod(std::string resourceName, std::string body) : resourceName(resourceName), body(body) {

}

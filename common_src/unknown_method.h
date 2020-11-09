#ifndef UNKNOWN_METHOD_H
#define UNKNOWN_METHOD_H


#include "http_method.h"

class UnknownMethod : public HTTPMethod {
    using HTTPMethod::HTTPMethod;
};


#endif //UNKNOWN_METHOD_H

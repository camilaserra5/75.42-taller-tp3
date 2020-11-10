#include <string>
#include "unknown_method.h"

std::string UnknownMethod::process() {
    return "HTTP/1.1 405 METHOD NOT ALLOWED\n\n" +
           this->methodName + " es un comando desconocido";
}

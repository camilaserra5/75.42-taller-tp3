#include <string>
#include "unknown_method.h"

#define ERROR_MSG "HTTP/1.1 405 METHOD NOT ALLOWED\n\n"
#define ERROR_DESC "{} es un comando desconocido\n"

std::string UnknownMethod::process() {
    std::string err = ERROR_DESC;
    return ERROR_MSG + err.replace(err.find("{}"), 2, this->methodName);
}

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <sstream>
#include <vector>
#include "http_method.h"
#include <memory>

/**
 * The protocol. Parses the string protocol.
 */
class Protocol {
public:
    /**
     * Creates the protocol.
     * @param line: the first line of the protocol
     *              the line should be <method> <resource> <protocol>
     * @param body: the body of the protocol
     */
    Protocol(const std::string &line, const std::string &body);

    /**
     * @return the first line
     */
    std::string getFirstLine();

    /**
     * @return the method as a string
     */
    std::string getMethodStr();

    /**
     * Creates the corresponding HTTP Method
     * @param resourceList: the resource list
     * @return the HTTP Method corresponding to the protocol method
     */
    std::unique_ptr <HTTPMethod> getMethod(ResourceList resourceList);

    /**
     * @return the resource as a string
     */
    std::string getResource();

    /**
     * @return the body as a string
     */
    std::string getBody();

private:
    std::vector <std::string> tokens;
    std::string line;
    std::string body;

    HTTPMethod *createGetMethod(ResourceList resourceList);

    HTTPMethod *createPostMethod(ResourceList resourceList);
};


#endif //PROTOCOL_H

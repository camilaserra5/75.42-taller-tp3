#ifndef TCP_PROTOCOL_H
#define TCP_PROTOCOL_H

#include <string>
#include "socket.h"

namespace TCPProtocol {
    void send(Socket &skt, std::string message);

    std::string receive(Socket &skt);
}

#endif //TCP_PROTOCOL_H

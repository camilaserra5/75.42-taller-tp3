#include "tcp_protocol.h"
#include <sstream>
#include <string>

#define BUFF_SIZE 64

int _do_send(Socket &skt, char *buffer, size_t buffer_length) {
    size_t total = 0;
    while (total < buffer_length) {
        size_t bytes_sent = ::send(skt.getFd(),
                                   &buffer[total],
                                   buffer_length - total,
                                   MSG_NOSIGNAL);
        total += bytes_sent;
        if (bytes_sent == 0) {
            return total;
        }
    }
    return total;
}

int _do_receive(Socket &skt, char *buffer, size_t buffer_length) {
    size_t total = 0;
    while (total < buffer_length) {
        size_t bytes_written = ::recv(skt.getFd(),
                                      &buffer[total],
                                      buffer_length - total,
                                      0);
        total += bytes_written;
        if (bytes_written == 0) {
            return total;
        }
    }
    return total;
}

void TCPProtocol::send(Socket &skt, std::string message) {
    char *my_argument = const_cast<char *> (message.c_str());
    _do_send(skt, my_argument, message.length());
}

std::string TCPProtocol::receive(Socket &skt) {
    std::stringstream stream;
    int cont = BUFF_SIZE;
    while (cont == BUFF_SIZE) {
        char buf[BUFF_SIZE];
        cont = _do_receive(skt, buf, BUFF_SIZE);
        stream.write(buf, cont);
    }
    return stream.str();
}


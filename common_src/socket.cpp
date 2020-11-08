#include <iostream>
#include <unistd.h>
#include <cstring>
#include "socket.h"

Socket::Socket(int fd) {
    this->fd = fd;
}

Socket::Socket() {
    // todo
}

Socket::Socket(Socket &&socket) {
    this->fd = socket.fd;
    socket.fd = -1;
}

Socket &Socket::operator=(Socket &&socket) {
    this->fd = socket.fd;
    socket.fd = -1;
    return *this;
}

int Socket::connect(char *host, char *port) {
    struct addrinfo hints;
    struct addrinfo *addr_info;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(NULL, port, &hints, &addr_info) != 0) {
        // todo error
        return -1;
    }

    int temp_fd = -1;
    bool cont = true;
    struct addrinfo *addr = addr_info;
    while (addr && cont) {
        temp_fd = ::socket(addr->ai_family,
                           addr->ai_socktype,
                           addr->ai_protocol);
        if (::connect(temp_fd, addr->ai_addr, addr->ai_addrlen) == -1) {
            cont = false;
        }
        addr = addr->ai_next;
    }

    this->fd = temp_fd;
    freeaddrinfo(addr_info);
    return this->fd != -1;
}

int Socket::bind(char *port) {
    struct addrinfo hints;
    struct addrinfo *addr_info;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if (getaddrinfo(NULL, port, &hints, &addr_info) != 0) {
        // todo error
        return -1;
    }

    int temp_fd = -1;
    bool cont = true;
    struct addrinfo *addr = addr_info;
    while (addr && cont) {
        temp_fd = ::socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (::bind(temp_fd, addr->ai_addr, addr->ai_addrlen) == -1) {
            cont = false;
        }
        addr = addr->ai_next;
    }

    this->fd = temp_fd;
    freeaddrinfo(addr_info);
    return this->fd != -1;
}

int Socket::listen() {
    return ::listen(this->fd, MAX_CONNECTIONS) != -1;
}

Socket Socket::accept() {
    int fd = ::accept(this->fd, nullptr, nullptr);
    if (fd == -1) {
        // todo error
    }
    return Socket(fd);
}

int Socket::send(char *buffer, size_t buffer_length) {
    size_t total = 0;
    while (total < buffer_length) {
        size_t bytes_sent = ::send(this->fd,
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

int Socket::recv(char *buffer, size_t buffer_length) {
    size_t total = 0;
    while (total < buffer_length) {
        size_t bytes_written = ::recv(this->fd,
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

Socket::~Socket() {
    if (this->fd != -1) {
        ::shutdown(this->fd, SHUT_RDWR);
        ::close(this->fd);
    }
}
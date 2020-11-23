#ifndef SOCKET_H
#define SOCKET_H

#include <netdb.h>
#include <sys/socket.h>

class Socket {
    static const int MAX_CONNECTIONS = 20;

public:
    explicit Socket(int fd);

    Socket();

    Socket(Socket &&socket);

    Socket &operator=(Socket &&socket);

    int connect(char *host, char *port);

    int bind(char *port);

    int listen();

    bool valid();

    Socket accept();

    void shutdown();

    int send(char *buffer, size_t buffer_length);

    int recv(char *buffer, size_t buffer_length);

    void closeWrite();

    void closeRead();

    ~Socket();

private:
    int fd;
};

#endif //SOCKET_H

#include <iostream>
#include <string>
#include "client.h"
#include "../common_src/socket.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: ./client <pip/hostname> <port/service>";
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    Socket socket;
    if (socket.connect(host, port) != 0) {
        // todo error
        std::cout << "connect error";
        return -1;
    }

    Client client(std::move(socket));
    client.run();
    return 0;
}

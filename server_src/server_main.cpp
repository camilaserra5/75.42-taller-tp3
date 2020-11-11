#include <iostream>
#include <string>
#include "server.h"
#include "../common_src/socket.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: ./server <puerto/servicio> <root_file>";
        return 1;
    }

    char *port = argv[1];
    std::string rootFile = argv[2];
    Socket socket;
    if (socket.bind(port) != 0) {
        std::cout << "bind error";
        return 1;
    }
    if (socket.listen() != 0) {
        std::cout << "listen error";
        return 1;
    }
    Server server(std::move(socket), rootFile);
    server.run();
    return 0;
}

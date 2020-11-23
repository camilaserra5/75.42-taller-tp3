#include <iostream>
#include <string>
#include "server.h"
#include "../common_src/socket.h"

#define OK_CODE 0
#define ERR_CODE 1
#define NBR_PARAMS 3
#define PORT_PARAM 1
#define FILE_PARAM 2
#define USAGE "Uso: ./server <puerto/servicio> <root_file>"

int main(int argc, char *argv[]) {
    if (argc != NBR_PARAMS) {
        std::cout << USAGE;
        return ERR_CODE;
    }

    char *port = argv[PORT_PARAM];
    std::string rootFile = argv[FILE_PARAM];
    Socket socket;
    if (socket.bind(port) != OK_CODE) {
        std::cout << "bind error";
        return ERR_CODE;
    }
    if (socket.listen() != OK_CODE) {
        std::cout << "listen error";
        return ERR_CODE;
    }
    Server server(std::move(socket), rootFile);
    server.run();
    return OK_CODE;
}

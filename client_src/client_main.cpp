#include <iostream>
#include <string>
#include "client.h"
#include "../common_src/socket.h"

#define OK_CODE 0
#define ERR_CODE 1
#define NBR_PARAMS 3
#define HOST_PARAM 1
#define PORT_PARAM 2
#define USAGE "Uso: ./client <pip/hostname> <port/service>"

int main(int argc, char *argv[]) {
    if (argc != NBR_PARAMS) {
        std::cout << USAGE;
        return ERR_CODE;
    }

    char *host = argv[HOST_PARAM];
    char *port = argv[PORT_PARAM];
    Socket socket(host, port);
    Client client(std::move(socket));
    client.run();
    return OK_CODE;
}

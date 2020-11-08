#include <iostream>
#include <string>
#include "client.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: ./client <pip/hostname> <port/service>";
        return 1;
    }

    std::string host = argv[1];
    std::string port = argv[2];
    Client client(host, port);
    client.run();
    return 0;
}

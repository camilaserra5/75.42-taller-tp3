#include <iostream>
#include <string>
#include "server.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: ./server <puerto/servicio> <root_file>";
        return 1;
    }

    std::string port = argv[1];
    std::string rootFile = argv[2];
    Server server(port, rootFile);
    server.run();
    return 0;
}

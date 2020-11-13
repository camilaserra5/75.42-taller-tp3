#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "../common_src/socket.h"
#include "client_manager.h"

class Server {
public:
    Server(Socket socket, const std::string &rootFile);

    void run();

    ~Server();

private:
    ClientManager clientManager;
};

#endif //SERVER_H

#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "../common_src/socket.h"

class Server {
public:
    Server(Socket& socket, std::string rootFile);

    void run();

private:
    Socket socket;
    std::string rootFile;
};


#endif //SERVER_H

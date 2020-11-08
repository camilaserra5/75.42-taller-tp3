#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "../common_src/socket.h"
#include "../common_src/thread.h"
#include "client_processor.h"

class Server : public Thread {
public:
    Server(Socket &socket, std::string rootFile);

    void run() override;

    ~Server() override;

private:
    Socket socket;

    std::vector<ClientProcessor *> clients;

    std::string rootFile;
};


#endif //SERVER_H

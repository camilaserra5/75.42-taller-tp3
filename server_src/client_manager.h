#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "../common_src/socket.h"
#include "client_processor.h"
#include <vector>

class ClientManager : public Thread {
public:
    ClientManager(Socket &socket);

    void run() override;

    ~ClientManager();

private:
    Socket socket;

    std::vector<ClientProcessor *> clients;
};

#endif //CLIENT_MANAGER_H
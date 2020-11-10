#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <vector>
#include <string>
#include "../common_src/socket.h"
#include "client_processor.h"

class ClientManager : public Thread {
public:
    ClientManager(Socket socket, std::string rootFile);

    void run() override;

    ~ClientManager() override;

private:
    Socket socket;

    std::vector<ClientProcessor *> clients;

    ResourceList resourceList;
};

#endif //CLIENT_MANAGER_H

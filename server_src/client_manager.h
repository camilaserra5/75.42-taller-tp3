#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "../common_src/socket.h"
#include "../common_src/thread.h"
#include <vector>

class ClientManager : public Thread {
public:
    ClientManager(Socket &socket);

    void run() override;

    ~ClientManager();

private:
    Socket socket;

    std::vector<Thread *> clients;

    int numberOfClients();
};

#endif //CLIENT_MANAGER_H

#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <vector>
#include <string>
#include "../common_src/socket.h"
#include "client_processor.h"

/**
 * The client manager.
 * In charge of handling the different client connections.
 */
class ClientManager : public Thread {
public:
    /**
     * Creates the client manager
     * @param socket: the server socket already listening
     * @param rootFile: the root file path
     */
    ClientManager(Socket socket, const std::string &rootFile);

    /**
     * Accepts the incoming client connections.
     * Creates the client processor for each, and deletes them once their finished.
     */
    void run() override;

    /**
     * Shutdowns the socket.
     * Waits for all the clients processors to finish.
     */
    void stop();

    /**
     * Client manager destructor.
     */
    ~ClientManager() override;

private:
    Socket socket;

    std::vector<ClientProcessor *> clients;

    ResourceList resourceList;
};

#endif //CLIENT_MANAGER_H

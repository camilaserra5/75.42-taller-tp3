#ifndef CLIENT_PROCESSOR_H
#define CLIENT_PROCESSOR_H

#include "../common_src/socket.h"
#include "../common_src/thread.h"
#include "../common_src/resource_list.h"
#include "../common_src/protocol.h"
#include <string>

class ClientProcessor : public Thread {
public:
    ClientProcessor(Socket socket, const ResourceList &resourceList);

    void run() override;

    bool isAlive();

    ~ClientProcessor() override;

private:
    Socket socket;

    ResourceList resourceList;

    bool is_alive;

    std::string getProtocolFromClient();

    Protocol createProtocol(std::string protocolStr);
};

#endif //CLIENT_PROCESSOR_H

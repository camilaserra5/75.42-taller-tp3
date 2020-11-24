#ifndef CLIENT_PROCESSOR_H
#define CLIENT_PROCESSOR_H

#include "../common_src/socket.h"
#include "../common_src/thread.h"
#include "../common_src/resource_list.h"
#include "../common_src/protocol.h"
#include <string>

/**
 * The client processor.
 * In charge of processing an individual client.
 */
class ClientProcessor : public Thread {
public:
    /**
     * Creates the processor
     * @param socket: the socket corresponding to the connection with a client
     * @param resourceList
     */
    ClientProcessor(Socket socket, const ResourceList &resourceList);

    /**
     * Processes the protocol received.
     * Sends the response to the client.
     * Closes the connection.
     */
    void run() override;

    /**
     * @return true while still processing. false, when already done.
     */
    bool isAlive();

    /**
     * Client processor destructor.
     */
    ~ClientProcessor() override;

private:
    Socket socket;

    ResourceList resourceList;

    bool is_alive;

    std::string getProtocolFromClient();

    Protocol createProtocol(std::string protocolStr);
};

#endif //CLIENT_PROCESSOR_H

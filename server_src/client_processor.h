#ifndef CLIENT_PROCESSOR_H
#define CLIENT_PROCESSOR_H

#include "../common_src/socket.h"
#include "../common_src/thread.h"

class ClientProcessor : public Thread {
public:
    ClientProcessor(Socket &socket);

    void run() override;

    bool isAlive();

    ~ClientProcessor() override;

private:
    Socket socket;

    bool is_alive;
};

#endif //CLIENT_PROCESSOR_H

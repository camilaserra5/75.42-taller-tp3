#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "../common_src/socket.h"

class Client {
public:
    explicit Client(Socket socket);

    void run();

    ~Client();

private:
    Socket socket;

    void sendStdInputToServer();
};

#endif //CLIENT_H

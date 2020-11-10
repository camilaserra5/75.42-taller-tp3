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
};

#endif //CLIENT_H

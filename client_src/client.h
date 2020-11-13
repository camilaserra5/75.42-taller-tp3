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

    std::stringstream getStreamFromStdin();

    void sendStreamToServer(std::string stream);

    std::string getResponse();
};

#endif //CLIENT_H

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(std::string host, std::string port);

    void run();

private:

};

#endif //CLIENT_H

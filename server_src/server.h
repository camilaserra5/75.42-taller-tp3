#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    Server(std::string port, std::string rootFile);

    void run();

private:

};


#endif //SERVER_H

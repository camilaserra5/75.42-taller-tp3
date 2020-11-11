#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
public:
    Thread();

    void start();

    void join();

    virtual void run() = 0;

    Thread(const Thread &) = delete;

    Thread &operator=(const Thread &) = delete;

    Thread(Thread &&thread);

    Thread &operator=(Thread &&thread);

    virtual ~Thread();

private:
    std::thread thread;
};

#endif //THREAD_H

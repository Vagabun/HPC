#ifndef SHARED_MUTEX_SHARED_MUTEX_H
#define SHARED_MUTEX_SHARED_MUTEX_H

#include <mutex>
#include <atomic>

class shared_mutex {
public:
    shared_mutex() : _readers_counter(0) {}; //is default value == 0?
    ~shared_mutex() = default;
    void lock();
    void unlock();
    void shared_lock();
    void shared_unlock();
private:
    std::atomic<int> _readers_counter;
};


#endif //SHARED_MUTEX_SHARED_MUTEX_H

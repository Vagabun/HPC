#include "shared_mutex.h"

void shared_mutex::lock() {
    _m.lock();
    while (_readers_counter)
        continue;
}

void shared_mutex::unlock() {
    _m.unlock();
}

void shared_mutex::shared_lock() {
    _m.lock();
    ++_readers_counter;
    _m.unlock();
}

void shared_mutex::shared_unlock() {
    --_readers_counter;
}

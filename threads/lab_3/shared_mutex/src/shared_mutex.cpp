#include "shared_mutex.h"

void shared_mutex::lock() {
    while (true) {
        if (_readers_counter)
            continue;
        else {
            _m.lock();
            break;
        }
    }
}

void shared_mutex::unlock() {
    _m.unlock();
}

void shared_mutex::shared_lock() {
    ++_readers_counter;
}

void shared_mutex::shared_unlock() {
    --_readers_counter;
}

#ifndef SHARED_MUTEX_THREAD_GUARD_H
#define SHARED_MUTEX_THREAD_GUARD_H

#include "header.h"

class thread_guard {
public:
    template<typename T>
    thread_guard(int nthreads, T&& f) {
        for (size_t i = 0; i < nthreads; ++i)
            _pool.emplace_back(std::move(std::thread(f)));
    };
    ~thread_guard() = default;
    void join();
    thread_guard(thread_guard &obj) = delete;
    thread_guard& operator=(thread_guard &obj) = delete;
private:
    std::vector<std::thread> _pool;
};

#endif //SHARED_MUTEX_THREAD_GUARD_H

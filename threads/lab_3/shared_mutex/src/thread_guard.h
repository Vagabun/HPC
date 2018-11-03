#ifndef SHARED_MUTEX_THREAD_GUARD_H
#define SHARED_MUTEX_THREAD_GUARD_H

#include <thread>
#include <vector>
#include <functional>

class thread_guard {
public:
    thread_guard(int nthreads, std::function<void()> f);
    ~thread_guard() = default;
    void join();
    thread_guard(thread_guard &obj) = delete;
    thread_guard& operator=(thread_guard &obj) = delete;
private:
   std::vector<std::thread> _pool;
};

#endif //SHARED_MUTEX_THREAD_GUARD_H

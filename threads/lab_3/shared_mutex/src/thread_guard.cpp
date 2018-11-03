#include "thread_guard.h"

thread_guard::thread_guard(int nthreads, std::function<void()> f) {
    for (size_t i = 0; i < nthreads; ++i)
        _pool.emplace_back(std::move(std::thread(f)));
}

void thread_guard::join() {
    for (auto &t : _pool)
        if (t.joinable())
            t.join();
}

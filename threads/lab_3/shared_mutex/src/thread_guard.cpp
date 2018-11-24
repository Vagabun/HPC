#include "thread_guard.h"

void thread_guard::join() {
    for (auto &t : _pool)
        if (t.joinable())
            t.join();
}

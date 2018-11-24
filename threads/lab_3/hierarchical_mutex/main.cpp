#include "src/hierarchical_mutex.h"

hierarchical_mutex high_level_mutex(10000);

void high_level_func() {
    std::lock_guard<hierarchical_mutex> lk(high_level_mutex);
}

hierarchical_mutex other_mutex(100);

void other_stuff() {
    high_level_func();
}

void thread_b() {
    std::lock_guard<hierarchical_mutex> lk(other_mutex);
    other_stuff();
}

int main() {

    std::thread b(thread_b);
    b.join();

    return 0;
}
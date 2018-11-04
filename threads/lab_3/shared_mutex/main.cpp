#include "src/shared_mutex.h"
#include "src/thread_guard.h"

shared_mutex s;

struct database {
    void query() {
        std::lock_guard<shared_mutex> lk(s);
        std::this_thread::sleep_for(std::chrono::milliseconds(time_generator()));
    }
    void non_blocking_query() {
        s.shared_lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(time_generator()));
        s.shared_unlock();
    }
    int time_generator() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 700);
        return distribution(gen);
    }
};


int main() {

    database d;
    std::chrono::steady_clock::time_point start, finish;
    std::chrono::duration<double> elapsed;
    std::ofstream output("output.txt");

    auto f_simulate_block = [&d]() {
        for (int i = 0; i < 11; ++i)
            d.query();
    };

    auto f_simulate_simultaneous = [&d]() {
        for (int i = 0; i <= 11; ++i)
            if (i % 10 == 1)
                d.query();
            else
                d.non_blocking_query();
    };


    start = std::chrono::steady_clock::now();
    thread_guard workers_1(std::thread::hardware_concurrency() - 1, f_simulate_block);
    workers_1.join();
    finish = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    std::cout << "Connection with full block: " << elapsed.count() << " s." << std::endl;
    output << "Connection with full block: " << elapsed.count() << " s." << std::endl;

    start = std::chrono::steady_clock::now();
    thread_guard workers_2(std::thread::hardware_concurrency() - 1, f_simulate_simultaneous);
    workers_2.join();
    finish = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    std::cout << "Connection with partial block: " << elapsed.count() << " s." << std::endl;
    output << "Connection with partial block: " << elapsed.count() << " s." << std::endl;

    return 0;
}
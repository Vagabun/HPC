#include "src/shared_mutex.h"
#include "src/thread_guard.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

shared_mutex s;

struct database {
    //add sleep for random time
    void query() {
        std::lock_guard<shared_mutex> lk(s);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    void non_blocking_query() {
        s.shared_lock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        s.shared_unlock();
    }
};

int main() {

    database d;

    std::function<void()> f = [&d]() {
        for (int i = 0; i < 11; ++i)
            d.query();
    };

    std::function<void()> f2 = [&d]() {
        for (int i = 0; i <= 11; ++i)
            if (i % 10 == 1)
                d.query();
            else
                d.non_blocking_query();
    };


    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    thread_guard workers(std::thread::hardware_concurrency() - 1, f);
    workers.join();
    std::chrono::steady_clock::time_point finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
    std::cout << "Connection with full block: " << elapsed.count() << " s." << std::endl;

//    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//    thread_guard workers(std::thread::hardware_concurrency() - 1, f2);
//    workers.join();
//    std::chrono::steady_clock::time_point finish = std::chrono::steady_clock::now();
//    std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
//    std::cout << "Connection with full block: " << elapsed.count() << " s." << std::endl;


    return 0;
}
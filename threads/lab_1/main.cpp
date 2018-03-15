#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::endl;

class thread_guard {
public:
    thread_guard(thread &obj) : t(obj) {};
    ~thread_guard() {
        if (t.joinable())
            t.join();
    };
    thread_guard(thread_guard &obj) = delete;
    thread_guard& operator=(thread_guard &obj) = delete;

private:
    thread &t;
};

int main() {

    thread t([]() { cout << "new thread" << endl; });
    thread_guard g(t);
    cout << "main" << endl;
    //cout << thread::hardware_concurrency() << endl;
    return 0;
}
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using std::thread;
using std::vector;
using std::ref;
using std::for_each;
using std::move;
using std::cout;
using std::endl;

class thread_guard {
public:
    thread_guard(thread obj) : t(move(obj)) {}
    ~thread_guard() {
        if (t.joinable())
            t.join();
    };
    thread_guard(thread_guard &obj) = delete;
    thread_guard& operator=(thread_guard &obj) = delete;

private:
    thread t;
};

class new_thread_guard {
public:
    new_thread_guard(int nthreads, int dsize, vector<int> &source1, vector<int> &source2, vector<int> &result) {
        int gap = dsize / nthreads, a = 0, b = a + gap;
        for (int i = 0; i < nthreads; i++) {
            workers.push_back(thread([&source1, &source2, &result, a, b]() {
                for (int i = a; i < b; ++i)
                    result[a] = source1[a] * source2[a];
            }));
            a = b, b += gap;
        }
    }
    ~new_thread_guard() {
        for_each(workers.begin(), workers.end(), [](thread &t) {
            if (t.joinable()) 
                t.join();
        });
    };
    new_thread_guard(new_thread_guard &obj) = delete;
    new_thread_guard& operator=(new_thread_guard &obj) = delete;

private:
    vector<thread> workers;
};

void sum(int a, int b) {
    cout << a + b << endl;
    return;
}

void multiply(vector<int> &source1, vector<int> &source2, vector<int> &result, int a, int b) {
    for (int i = a; i < b; ++i)
        result[a] = source1[a] * source2[a];
}

int main() {
    /*int a = 0;
    thread t(sum, std::ref(a), 25);*/
    //t.join();
    
    /*thread_guard g(move(t));
    cout << a << endl;*/
    //int a = 0, b = 0, c = 0;
    //thread_guard g(thread([&a]() { a += 25; }));
    
    /*thread_guard g(thread([&a]() { a += 25; }));
    thread_guard c(thread([&a]() { a += 25; }));
    thread_guard d(thread([&a]() { a += 25; }));
    thread_guard e(thread([&a]() { a += 25; }));
    thread_guard f(thread([&a]() { a += 25; }));*/

    int size = 3;
    vector<int> a = { 1, 2, 3 };
    vector<int> b = { 2, 2, 3 };
    vector<int> result(3);

    //int ntreads = thread::hardware_concurrency();
    new_thread_guard(3, 3, a, b, result);

    int sum = 0;
    for (auto &i : result)
        sum += i;

    /*thread t1(multiply, ref(a), ref(b), ref(result), 0, 1), t2(multiply, ref(a), ref(b), ref(result), 1, 2), t3(multiply, ref(a), ref(b), ref(result), 2, 3);
    cout << "hello" << endl;
    t1.join();
    t2.join();
    t3.join();*/

    cout << sum << endl;

    return 0;
}
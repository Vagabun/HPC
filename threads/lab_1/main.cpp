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
                for (int j = a; j < b; ++j)
                    result[j] = source1[j] * source2[j];
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

int threads(int nthreads, int dsize) {
    for (int i = nthreads; i >= 2; i--) {
        if (dsize % i == 0)
            return i;
    }
    return 0;
}

void change_capacity(int &dsize, vector<int> &a, vector<int> &b, vector<int> &result) {
    dsize += 1;
    a.push_back(0);
    b.push_back(0);
    result.push_back(0);
}

int main() {

    /*int size = 7;
    vector<int> a = { 1, 2, 3, 1, 2, 3, 4 };
    vector<int> b = { 2, 2, 3, 2, 2, 3, 4 };
    vector<int> result(size);*/

    int size = 3;
    vector<int> a = { 1, 2, 3 };
    vector<int> b = { 2, 2, 3 };
    vector<int> result(size);

    if (threads(thread::hardware_concurrency(), size))
        new_thread_guard(threads(thread::hardware_concurrency(), size), size, a, b, result);
    else {
        change_capacity(size, a, b, result);
        new_thread_guard(threads(thread::hardware_concurrency(), size), size, a, b, result);
    }

    int sum = 0;
    for (auto &i : result)
        sum += i;

    cout << sum << endl;

    return 0;
}
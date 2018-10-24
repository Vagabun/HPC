#include <iostream>
#include <thread>
#include <mutex>
#include <stack>
#include <map>

class hierarchical_mutex {
public:
    explicit hierarchical_mutex(int level) : _level(level) {};
    ~hierarchical_mutex() = default;
    int get_level();
    void lock();
    void unlock();

private:
    int _level;
    std::mutex _m;
    static std::stack<int> _hierarchy_levels;
    //static int _current_level;
};

int hierarchical_mutex::get_level() {
    return _level;
}

void hierarchical_mutex::lock() {
    if (!_hierarchy_levels.empty()) {
        if (_hierarchy_levels.top() > this->get_level()) {
            _hierarchy_levels.push(this->get_level());
            _m.lock();
        }
    }
    else {
        _hierarchy_levels.push(this->get_level());
        _m.lock();
    }
    //std::this_thread::get_id();
}

void hierarchical_mutex::unlock() {
    if (!_hierarchy_levels.empty())
        _hierarchy_levels.pop();
    _m.unlock();
}

hierarchical_mutex a(10);

void test() {
    std::lock_guard<hierarchical_mutex> lk(a);
    std::cout << "test" << std::endl;

}

int main() {

    //std::thread t1(test);
    //t1.join();

    return 0;
}
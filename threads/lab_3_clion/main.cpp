#include <iostream>
#include <thread>
#include <mutex>
#include <stack>
#include <map>
#include <string>

using namespace std;

class hierarchical_mutex {
public:
    explicit hierarchical_mutex(int level) : _level(level) {};
    ~hierarchical_mutex() = default;
    void lock();
    void unlock();

private:
    int _level;
    std::mutex _m;
    static std::map< std::thread::id, std::stack<int> > _hierarchy;
    void _check_for_hierarchy_violation();
};

std::map< std::thread::id, std::stack<int> > hierarchical_mutex::_hierarchy = { };

void hierarchical_mutex::lock() {
    _check_for_hierarchy_violation();
    _hierarchy.at(std::this_thread::get_id()).push(this->_level);
    _m.lock();
}

void hierarchical_mutex::unlock() {
    _hierarchy.at(std::this_thread::get_id()).pop();
    _m.unlock();
}

void hierarchical_mutex::_check_for_hierarchy_violation() {
    if (!_hierarchy.count(std::this_thread::get_id())) //move this block to separate function
        _hierarchy.insert(std::make_pair(std::this_thread::get_id(), std::stack<int>())); //() ?

    try {
        if (_hierarchy.at(std::this_thread::get_id()).empty())
            return;
//        if (_hierarchy[std::this_thread::get_id()].empty())
//            return;
        else if (_hierarchy.at(std::this_thread::get_id()).top() < this->_level)
            throw std::logic_error("hierarchy violation");
            //std::cout << "that's sad" << std::endl;
    }
    catch (...) {
        std::cout << "logic error: mutex hierarchy violation" << std::endl;
        //std::terminate(); //stack will not unwind
        throw;
    }
}

int main() {


    hierarchical_mutex a(10);
    hierarchical_mutex b(5);

    std::lock_guard<hierarchical_mutex> lk(a);


    return 0;
}
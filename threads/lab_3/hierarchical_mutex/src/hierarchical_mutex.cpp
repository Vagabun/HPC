#include "hierarchical_mutex.h"

std::map< std::thread::id, std::stack<int> > hierarchical_mutex::_hierarchy = {};

void hierarchical_mutex::_init_hierarchy_storage() {
    _hierarchy_storage_mutex.lock();
    if (!_hierarchy.count(std::this_thread::get_id()))
        _hierarchy.insert(std::make_pair(std::this_thread::get_id(), std::stack<int>()));
    _hierarchy_storage_mutex.unlock();
}

void hierarchical_mutex::_check_for_hierarchy_violation() {
    _init_hierarchy_storage();
    try {
        if (_hierarchy.at(std::this_thread::get_id()).empty())
            return;
        else if (_hierarchy.at(std::this_thread::get_id()).top() < this->_level)
            throw std::logic_error("hierarchy violation");
    }
    catch (...) {
        std::cout << "logic error: mutex hierarchy violation" << std::endl;
        std::terminate();
    }
}

void hierarchical_mutex::lock() {
    _check_for_hierarchy_violation();
    _hierarchy.at(std::this_thread::get_id()).push(this->_level);
    _m.lock();
}

void hierarchical_mutex::unlock() {
    _hierarchy.at(std::this_thread::get_id()).pop();
    _m.unlock();
}

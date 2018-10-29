#ifndef LAB_3_CLION_HIERARCHICAL_MUTEX_H
#define LAB_3_CLION_HIERARCHICAL_MUTEX_H

#include <iostream>
#include <thread>
#include <mutex>
#include <stack>
#include <map>

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
    void _init_hierarchy_storage();
};

#endif

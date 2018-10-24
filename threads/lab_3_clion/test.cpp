#include <iostream>
#include <thread>
#include <mutex>

class hierarchical_mutex {
public:
	hierarchical_mutex(int data) : _value(data) {};
	~hierarchical_mutex() = default;
	void lock();
	void unlock();

private:
	int _value;
	static int _current_level;
};

void hierarchical_mutex::lock() {
	if (_value < _current_level)
		_current_level = _value; //???
}

void hierarchical_mutex::unlock() {
}

hierarchical_mutex a(10);

int main() {
	
	

	std::lock_guard<hierarchical_mutex> lock(a);

	std::cout << "test" << std::endl;
	return 0;
}



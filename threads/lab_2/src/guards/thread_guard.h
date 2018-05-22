#pragma once

#include "headers.h"

class thread_guard {
public:
	thread_guard(size_t nthreads, std::function<void(std::string, std::string)> f, std::vector<std::string> in, std::vector<std::string> out);
	~thread_guard();
	thread_guard(thread_guard &obj) = delete; //for what?
	thread_guard &operator=(thread_guard &obj) = delete; //for what?
private:
	std::vector<std::thread> _thread_pool;
};


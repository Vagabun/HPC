#pragma once

#include "headers.h"

class thread_guard {
public:
	thread_guard(size_t nthreads, std::function<void(std::string, std::string)> func, std::vector<std::string> in, std::vector<std::string> out);
	~thread_guard();
	thread_guard(thread_guard &obj) = delete;
	thread_guard &operator=(thread_guard &obj) = delete;
private:
	std::vector<std::thread> _thread_pool;
};


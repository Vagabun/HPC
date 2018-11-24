#include "thread_guard.h"

thread_guard::thread_guard(size_t nthreads, std::function<void(std::string, std::string)> func, std::vector<std::string> in, std::vector<std::string> out) {
	for (size_t i = 0; i < nthreads; i++)
		_thread_pool.push_back(std::thread(func, in[i], out[i]));
}

thread_guard::~thread_guard() {
	for (auto &t : _thread_pool)
		if (t.joinable())
			t.join();
}

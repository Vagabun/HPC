#include <stack>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>


class thread_guard {
public:
	thread_guard() {};
	~thread_guard() {
		for (auto &t : thread_pool)
			if (t.joinable())
				t.join();
	};
	thread_guard(thread_guard &obj) = delete; //for what?
	thread_guard &operator=(thread_guard &obj) = delete; //for what?
private:
	std::vector<std::thread> thread_pool;
};

void test(std::string str) {
	for (size_t i = 0; i < 100; i++) {
		std::cout << str << std::endl;
	}
}

void out(std::deque<std::string> &filenames) {
	std::ifstream(filenames.front());
}

int main() {

	std::deque<std::string> in { "1_in.txt", "2_in.txt", "3_in.txt" };

	return 0;
}
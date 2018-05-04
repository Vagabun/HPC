#include <stack>
#include <thread>
#include <mutex>
#include <vector>

class thread_guard {
public:
	thread_guard() {};
	thread_guard(thread_guard &obj) = delete;
private:
	std::vector<std::thread> thread_pool;
};

int main() {

	return 0;
}
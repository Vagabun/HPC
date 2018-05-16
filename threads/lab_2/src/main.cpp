#include <stack>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

//template<typename T> or template<class T>
template<typename T>
class stack_guard {
public:
	void push(T value) {
		std::lock_guard<std::mutex> lock(_m);
		_stack.push(value);
	}
	T pop_top() {
		std::lock_guard<std::mutex> lock(_m);
		T data;
		if (!_stack.empty()) {
			data = _stack.top(); //T should have copy constructor?
			_stack.pop();
		}
		return data;
	}
private:
	std::stack<T> _stack;
	std::mutex _m;
};

stack_guard<int> s;

void print(std::string in, std::string out) {
	std::string command;
	int data;
	std::ifstream input(in);
	std::ofstream output(out);
	while (!input.eof()) {
		input >> command;
		if (command == "PUSH") {
			input >> data;
			s.push(data);
			output << "PUSHED " << data << std::endl;
		}
		else if (command == "POP") {
			data = s.pop_top();
			output << "POPPED " << data << std::endl;
		}
	}
	input.close();
	output.close();
}

class thread_guard {
public:
	thread_guard(size_t nthreads, std::vector<std::string> in, std::vector<std::string> out) {
		for (size_t i = 0; i < nthreads; ++i) {
			thread_pool.push_back(std::thread(print, in[i], out[i]));
		}
	};
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

int main() {

	std::vector<std::string> in { "src/data/1_in.txt", "src/data/2_in.txt", "src/data/3_in.txt" };
	std::vector<std::string> out { "src/data/1_out.txt", "src/data/2_out.txt", "src/data/3_out.txt" };
	thread_guard test(3, in, out);

	return 0;
}
#pragma once

#include "headers.h"

template<typename T>
class stack_guard {
public:
	stack_guard() = default;
	~stack_guard() = default;
	void push(T value) {
		std::lock_guard<std::mutex> lock(_m);
		_stack.push(value);
	}
	void pop_top(T &result) {
		std::lock_guard<std::mutex> lock(_m);
		if (!_stack.empty()) {
			result = _stack.top(); //user data should support copy by value operation
			_stack.pop();
		}
	}
	std::shared_ptr<T> pop_top() {
		std::lock_guard<std::mutex> lock(_m);
        std::shared_ptr<T> temp; //nullptr by default
		if (!_stack.empty()) {
            temp = std::make_shared<T>(_stack.top());
			_stack.pop();
		}
		return temp;
	}
	void status() {
		std::lock_guard<std::mutex> lock(_m);
		if (!_stack.empty())
			std::cout << "STACK IS NOT EMPTY" << std::endl;
		else
			std::cout << "STACK IS EMPTY" << std::endl;
	}
private:
	std::stack<T> _stack;
	std::mutex _m;
};

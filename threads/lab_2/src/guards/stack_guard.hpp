#pragma once

#include "headers.h"

//template<typename T> or template<class T>?
template<typename T>
class stack_guard {
public:
	stack_guard() = default;
	~stack_guard() = default;
	void push(T value) {
		//_stack.push(new T(value));
		std::lock_guard<std::mutex> lock(_m);
		_stack.push(std::make_shared<T>(value));
	}
	void pop_top(T &result) {
		std::lock_guard<std::mutex> lock(_m);
		if (!_stack.empty()) {
			result = *_stack.top();
			_stack.pop();
		}
	}
	std::shared_ptr<T> pop_top() {
		std::lock_guard<std::mutex> lock(_m);
		std::shared_ptr<T> temp;
		if (!_stack.empty()) {
			temp = _stack.top();
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
	std::stack<std::shared_ptr<T>> _stack;
	std::mutex _m;
};

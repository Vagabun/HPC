#pragma once

#include <iostream>
#include <string>

class output_wrapper {
public:
	static output_wrapper& instance();
	void print(const std::string &&data);
private:
	output_wrapper();
	~output_wrapper();
	output_wrapper(output_wrapper const&) = delete;
	output_wrapper& operator= (output_wrapper const&) = delete;
};


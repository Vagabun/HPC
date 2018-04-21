#pragma once

#include "headers.h"

class output_wrapper {
public:
	static output_wrapper& instance();
	void print(string &&data);
private:
	output_wrapper() = default;
	~output_wrapper() = default;
	output_wrapper(output_wrapper const&) = delete;
	output_wrapper& operator= (output_wrapper const&) = delete;
};


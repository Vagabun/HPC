#pragma once

#include "output_wrapper_interface.h"

class output_wrapper : public output_wrapper_interface {
public:
	static output_wrapper& instance();
	void print(string &&data) override;
private:
	output_wrapper() = default;
	~output_wrapper() = default;
	output_wrapper(output_wrapper const&) = delete;
	output_wrapper& operator= (output_wrapper const&) = delete;
};


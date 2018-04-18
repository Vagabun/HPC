#include "output_wrapper.h"

output_wrapper& output_wrapper::instance() {
	static output_wrapper ow;
	return ow;
}

output_wrapper::output_wrapper() {}

output_wrapper::~output_wrapper() {}

void output_wrapper::print(const std::string &&data) {
	std::cout << std::endl;
	std::cout << data << std::endl;
	std::cout << std::endl;
}

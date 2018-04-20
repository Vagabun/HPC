#include "output_wrapper.h"

output_wrapper& output_wrapper::instance() {
	static output_wrapper instance;
	return instance;
}

output_wrapper::output_wrapper() {}

output_wrapper::~output_wrapper() {}

void output_wrapper::print(const std::string &&data) {
	cout << endl << data << endl << endl;
}

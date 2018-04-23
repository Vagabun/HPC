#include "output_wrapper.h"

output_wrapper& output_wrapper::instance() {
	static output_wrapper instance;
	return instance;
}

void output_wrapper::print(std::string &&data) {
	cout << endl << data << endl << endl;
}

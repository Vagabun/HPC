#include "guards/stack_guard.hpp"
#include "guards/thread_guard.h"

class data {
public:
	data() = default;
	~data() = default;
	data operator=(const data &value) {
		this->_data = value._data;
		return *this;
	}
	friend std::ifstream& operator>>(std::ifstream &in, data &d) {
		in >> d._data;
		return in;
	}
	friend std::ofstream& operator<<(std::ofstream &out, data &d) {
		out << d._data;
		return out;
	}
private:
	int _data;
};

int main() {

	std::vector<std::string> in { "src/data/1_in.txt", "src/data/2_in.txt", "src/data/3_in.txt" };
	std::vector<std::string> out { "src/data/1_out.txt", "src/data/2_out.txt", "src/data/3_out.txt" };

	/*stack_guard<int> s;

	std::function<void(std::string, std::string)> func = [&s](std::string in, std::string out) {
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
				s.pop_top(data);
				output << "POPPED " << data << std::endl;
			}
		}
		input.close();
		output.close();
	};

	thread_guard guard(3, func, in, out);*/

	stack_guard<data> s;

	std::function<void(std::string, std::string)> func = [&s](std::string in, std::string out) {
		std::string command;
		data d;
		std::ifstream input(in);
		std::ofstream output(out);
		while (!input.eof()) {
			input >> command;
			if (command == "PUSH") {
				input >> d;
				s.push(d);
				output << d << " PUSHED" << std::endl;
			}
			else if (command == "POP") {
				s.pop_top(d);
				output << d << " POPPED " << std::endl;
			}
		}
		input.close();
		output.close();
	};

	thread_guard guard(3, func, in, out);

    return 0;
}
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <functional>

class thread_guard {
public:
	thread_guard(int nthreads, std::function<void(int)> f) {
		for (size_t i = 0; i < nthreads; i++)
			workers.push_back(std::thread(f, i));
	}
	~thread_guard() {
		for (auto &t : workers)
			if (t.joinable())
				t.join();
	};
	thread_guard(thread_guard &obj) = delete;
	thread_guard& operator=(thread_guard &obj) = delete;

private:
	std::vector<std::thread> workers;
};

struct data {
    data() {
        std::ifstream input("input.txt");
        input >> size;
        gap = size / (std::thread::hardware_concurrency() - 1);
        result.resize(size);
        read(input, src1);
        read(input, src2);
        input.close();
    }
    void read(std::ifstream &file, std::vector<int> &dest) {
        int val;
        for (size_t i = 0; i < size; ++i) {
            file >> val;
            dest.push_back(val);
        }
    }
    void print() {
        int sum = 0;
        for (size_t i = 0; i < result.size(); ++i) {
            if (!result[i])
                result[i] = src1[i] * src2[i];
            sum += result[i];
        }
        std::cout << sum << std::endl;
    }
    std::vector<int> src1, src2, result;
    int size, gap;
};

int main() {
    data d;

	std::function<void(int)> calculate = [&d](int nthread) {
		for (size_t i = nthread * d.gap; i < (nthread + 1) * d.gap; ++i)
			d.result[i] = d.src1[i] * d.src2[i];
	};
	thread_guard guard(std::thread::hardware_concurrency() - 1, calculate);

	d.print();

    return 0;
}

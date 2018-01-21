#include <iostream>
#include <fstream>
#include <set>

int main() {

    std::ifstream in("input.txt");
    int N, M, K, data;
    std::set<int> questions;
    in >> N;
    for (int i = 0; i < N; ++i) {
        in >> data;
        questions.insert(data);
    }
    in >> M;
    for (int i = 0; i < M; ++i) {
        in >> K;
        int counter = 0;
        for (int j = 0; j < K; ++j) {
            in >> data;
            if (questions.count(data) != 0)
                ++counter;
        }
        std::cout << counter << std::endl;
    }

    in.close();
    return 0;
}
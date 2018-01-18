#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

bool operator==(const char &obj) {
    std::cout << "bla";
}

int main() {

    std::ifstream in("input.txt");
    char c, buffer[80];
    while (true) {
        if (in.eof())
            break;
        in >> buffer;
//        if () std::cout << "bla";
        std::cout << buffer << " ";
    }
//    std::cout << buffer << std::endl;
//    std::cout << buffer;
    return 0;
}
#include "text_func.h"

int main() {

    std::ifstream in("input.txt");
    char buffer[100], reverted_buffer[100]; //move char to struct
    while (true) {
        if (in.eof())
            break;
        in >> buffer;
        revert(buffer, reverted_buffer);
        if (equal(buffer, reverted_buffer)) {
            if (buffer[0] >= '0' && buffer[0] <= '9')
                std::cout << get_max(buffer) << " ";
            else
                std::cout << get_max(buffer, false) << " ";
        }
    }
    return 0;
}
#include "text_func.h"

int main() {

    std::ifstream in("input.txt");
    char buffer[100], reverted_buffer[100]; //move char to struct?
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
        else if (buffer[0] >= '0' && buffer[0] <= '9' && grows_evenly(buffer))
            std::cout << get_mid(buffer) << " ";
        else if (grows_evenly(buffer, false))
            std::cout << get_mid(buffer, false) << " ";
        else
            std::cout << buffer << " ";
    }
    in.close();
    return 0;
}
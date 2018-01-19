#include <iostream>
#include <fstream>

void revert(const char *obj, char *buffer) {
    int i = 0;
    while (obj[i] != '\0') {
        ++i;
    }
    int k = 0;
    for (int j = i - 1; j >= 0; --j) {
        buffer[k++] = obj[j];
    }
}

bool equal(const char *obj, const char *buffer) {
    int i = 0;
    while (obj[i] != '\0') {
        if (obj[i] != buffer[i])
            return false;
        ++i;
    }
    return true;
}

int get_max(const char *obj) {
    int max = -1, i = 0;
    while (obj[i] != '\0') {
        int number = (obj[i] - '0') * 10 + (obj[i+1] - '0');
        if (number > max)
            max = number;
        i += 2;
    }
    return max;
}

char get_max(const char *obj, bool flag) {
    if (!flag) {
        int i = 0;
        char max = '0';
        while (obj[i] != '\0') {
            if (obj[i] > max)
                max = obj[i];
            ++i;
        }
    }
}

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
                std::cout << get_max(buffer) << std::endl;
            else
                std::cout << get_max(buffer, false) << std::endl;
        }
    }
    return 0;
}
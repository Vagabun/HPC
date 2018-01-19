#include "text_func.h"

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
    char max = '0';
    if (!flag) {
        int i = 0;
        while (obj[i] != '\0') {
            if (obj[i] > max)
                max = obj[i];
            ++i;
        }
    }
    return max;
}


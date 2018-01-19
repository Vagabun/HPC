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

bool grows_evenly(const char *obj) {
    int i = 0, k = 0, buffer[100];
    while (obj[i] != '\0') {
        buffer[k] = (obj[i] - '0') * 10 + (obj[i+1] - '0');
        if (k != 0) {
            if (buffer[k] != buffer[k-1] + 1)
                return false;
        }
        i += 2;
        ++k;
    }
    return true;
}

bool grows_evenly(const char *obj, bool flag) {
    if (!flag) {
        int i = 0;
        char letter = obj[0];
        while (obj[i] != '\0') {
            if (i != 0) {
                if (obj[i] != letter + 1)
                    return false;
                ++letter;
            }
            ++i;
        }
    }
    return true;
}

int get_mid(const char *obj) {
    int i = 0, sum = 0;
    while (obj[i] != '\0') {
        sum += (obj[i] - '0') * 10 + (obj[i+1] - '0');
        i += 2 ;
    }
    return sum/(i/2);
}

char get_mid(const char *obj, bool flag) {
    int i = 0;
    if (!flag) {
        while (obj[i] != '\0')
            ++i;
    }
    return obj[i/2];
}

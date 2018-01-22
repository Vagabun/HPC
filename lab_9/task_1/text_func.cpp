#include "headers.h"
#include "text_func.h"

bool palindrome(const char *obj) {
    int j = _size - 1;
    for (int i = 0; i < _size; ++i) {
        if (obj[i] != obj[j--])
            return false;
    }
    return true;
}

//for words in numeric representation
int get_max(const int *obj) {
    int max = -1;
    for (int i = 0; i < _seq_size; i++) {
        int number = obj[i];
        if (number > max)
            max = number;
    }
    return max;
}

//for words in usual representation
char get_max(const char *obj) {
    char max = '0';
        for (int i = 0; i < _size; ++i) {
            if (obj[i] > max)
                max = obj[i];
        }
    return max;
}

bool grows_evenly(const int *obj) {
    if (_seq_size > 1) {
        int gap = obj[1] - obj[0];
        for (int i = 0; i < _seq_size - 1; ++i) {
            if (obj[i] != obj[i + 1] - gap)
                return false;
        }
    }
    return true;
}

bool grows_evenly(const char *obj) {
        char letter = obj[0];
        for (int i = 1; i < _size; ++i) {
            if (obj[i] != letter + 1)
                return false;
            ++letter;
        }
    return true;
}

int get_mid(const int *obj) {
    int sum = 0;
    for (int i = 0; i < _seq_size; ++i)
        sum += obj[i];
    return sum/(_seq_size);
}

char get_mid(const char *obj) {
    return obj[_size/2];
}

void get_size(const char *buf) {
    _size = (int)strlen(buf);
}

bool if_number(const char *obj) {
    return ((obj[0] - '0') >= 0 && (obj[0] - '0' <= 9)) ? true : false;
}

void get_sequence(const char *buf, int *obj) {
    int j = 0;
    for (int i = 0; i < _size; i += 2)
        obj[j++] = (buf[i] - '0') * 10 + (buf[i+1] - '0');
    _seq_size = j;
}

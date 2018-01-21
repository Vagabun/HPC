#include "text_func.h"

void revert(word &obj) {
    int i = 0;
    for (int j = obj.size - 1; j >= 0; --j) {
        obj.reverted_buffer[i++] = obj.buffer[j];
    }
}

bool palindrome(const word &obj) {
    for (int i = 0; i < obj.size; ++i) {
        if (obj.buffer[i] != obj.reverted_buffer[i])
            return false;
    }
    return true;
}

//for words in numeric representation
int get_max(const word &obj) {
    int max = -1;
    for (int i = 0; i < obj.seq_size; i++) {
        int number = obj.sequence[i];
        if (number > max)
            max = number;
    }
    return max;
}

//for words in usual representation
char get_max(const word &obj, bool flag) {
    char max = '0';
    if (!flag) {
        for (int i = 0; i < obj.size; ++i) {
            if (obj.buffer[i] > max)
                max = obj.buffer[i];
        }
    }
    return max;
}

bool grows_evenly(const word &obj) {
    for (int i = 0; i < obj.seq_size - 1; ++i) {
        if (obj.sequence[i] != obj.sequence[i+1] - 1)
            return false;
    }
    return true;
}

bool grows_evenly(const word &obj, bool flag) {
    if (!flag) {
        char letter = obj.buffer[0];
        for (int i = 1; i < obj.size; ++i) {
            if (obj.buffer[i] != letter + 1)
                return false;
            ++letter;
        }
    }
    return true;
}

int get_mid(const word &obj) {
    int sum = 0;
    for (int i = 0; i < obj.seq_size; ++i)
        sum += obj.sequence[i];
    return sum/(obj.seq_size);
}

char get_mid(const word &obj, bool flag) {
    if (!flag)
        return obj.buffer[obj.size/2];
}

void get_size(word &obj) {
    int i = 0;
    while (obj.buffer[i] != '\0')
        ++i;
    obj.size = i;
}

bool if_number(const word &obj) {
    return ((obj.buffer[0] >= '0') && (obj.buffer[0] <= '9')) ? true : false;
}

void get_sequence(word &obj) {
    int j = 0;
    for (int i = 0; i < obj.size; i += 2)
        obj.sequence[j++] =  (obj.buffer[i] - '0') * 10 + (obj.buffer[i+1] - '0');
    obj.seq_size = j;
}

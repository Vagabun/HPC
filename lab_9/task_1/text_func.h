#ifndef TASK_1_TEXT_FUNC_H
#define TASK_1_TEXT_FUNC_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

struct word {
    char buffer[100], reverted_buffer[100];
    int size, sequence[100], seq_size;
};

void get_size(word &obj);
bool if_number(const word &obj);
void get_sequence(word &obj);
void revert(word &obj);
bool palindrome(const word &obj);
int get_max(const word &obj);
char get_max(const word &obj, bool flag);
bool grows_evenly(const word &obj);
bool grows_evenly(const word &obj, bool flag);
int get_mid(const word &obj);
char get_mid(const word &obj, bool flag);

#endif //TASK_1_TEXT_FUNC_H

#ifndef TASK_1_TEXT_FUNC_H
#define TASK_1_TEXT_FUNC_H

#include <iostream>
#include <fstream>
#include <cstring>

using std::ifstream;
using std::cout;

void get_size(const char *buf);
bool if_number(const char *obj);
void get_sequence(const char *buf, int *obj);
bool palindrome(const char *obj);
int get_max(const int *obj);
char get_max(const char *obj);
bool grows_evenly(const char *obj);
bool grows_evenly(const int *obj);
int get_mid(const int *obj);
char get_mid(const char *obj);

#endif //TASK_1_TEXT_FUNC_H

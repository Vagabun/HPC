#pragma once
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Pie {
public:
    static int quantity;
    Pie();
    ~Pie();
    static void tastier(const Pie &obj1, const Pie &obj2);
private:
    string title;
    int tasty;
};
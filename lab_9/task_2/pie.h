#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Pie {
public:
    Pie();
    ~Pie();
    Pie(const Pie &obj); //copy
    Pie(int tsty, string ttl);
    Pie(int tsty);
    Pie(string ttl);
    static int quantity;
    static void tastier(const Pie &obj1, const Pie &obj2);
    Pie& operator= (const Pie& obj);
private:
    string title;
    int tasty;
    const std::vector<string> types = {"meat pie", "potato pie", "cheese and mushrooms pie", "banana pie", "strawberry pie", "chicken pie"};
    std::mt19937 generate_rand();
};
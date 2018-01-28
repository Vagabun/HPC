#pragma once
//#ifndef TASK_2_PIE_H
//#define TASK_2_PIE_H

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <chrono>
#include <utility>

using std::cout;
using std::endl;
using std::string;

class Pie {
public:
    Pie();
    ~Pie();
    Pie(const Pie &obj); //copy
    Pie(string &new_title, int new_tasty);
    explicit Pie(int new_tasty);
    explicit Pie(string &&new_title);
    static int quantity;
    static void tastier(const Pie &obj1, const Pie &obj2);
    Pie& operator= (const Pie& obj);
private:
    string title;
    int tasty;
    const std::vector<string> pie_types = {"meat pie", "potato pie", "cheese and mushrooms pie", "banana pie", "strawberry pie", "chicken pie"};
    int generate_rand(std::uniform_int_distribution<int> obj);
};

//#endif TASK_2_PIE_H
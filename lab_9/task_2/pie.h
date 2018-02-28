//#pragma once
#ifndef TASK_2_PIE_H
#define TASK_2_PIE_H

#include "headers.h"

class Pie {
public:
    Pie();
    ~Pie();
    Pie(const Pie &obj); //copy
    Pie(string &new_title, int new_tasty);
    Pie(int new_tasty);
    Pie(string &&new_title);
    static int all_time_quantity;
    static void tastier(const Pie &obj1, const Pie &obj2);
    Pie& operator= (const Pie& obj);
    int get_tasty() const;
    void set_tasty(int new_tasty);
    string get_title() const;
private:
    string _title;
    int _tasty;
    const std::array<string, 6> pie_types = { {"meat pie", "potato pie", "cheese and mushrooms pie", "banana pie", "strawberry pie", "chicken pie"} };
    int generate_rand(std::uniform_int_distribution<int> obj);
};

#endif //TASK_2_PIE_H
//#pragma once
#ifndef TASK_2_PIE_H
#define TASK_2_PIE_H

#include "headers.h"
#include "baker.h"

//class Baker; // why i shouldn't make forward declaration here?

class Pie {
    friend class Baker;
public:
    Pie();
    ~Pie();
    Pie(const Pie &obj); //copy
    Pie(string &new_title, int new_tasty);
    explicit Pie(int new_tasty);
    explicit Pie(string &&new_title);
    static int all_time_quantity;
    static void tastier(const Pie &obj1, const Pie &obj2);
    Pie& operator= (const Pie& obj);
    //friend class Baker; how to access private function of Pie class?
private:
    string title;
    int tasty;
    const std::array<string, 6> pie_types = {"meat pie", "potato pie", "cheese and mushrooms pie", "banana pie", "strawberry pie", "chicken pie"};
    int generate_rand(std::uniform_int_distribution<int> obj);
//    friend void Baker::bake_pie(); //redundant declaration?
};

#endif //TASK_2_PIE_H
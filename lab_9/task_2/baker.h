//#pragma once
#ifndef TASK_2_BAKER_H
#define TASK_2_BAKER_H

#include "headers.h"
#include "pie.h"

class Baker {
public:
    Baker();
    ~Baker();
    Baker(const Baker &obj);
    Baker(int new_pies_quantity);
    Baker& operator= (const Baker &obj);
    void bake_pie();
    void eat_pie();
    void return_pie(Baker &obj);
    int get_bake_tasty() const;
    void set_new_exp(int exp);
    void set_new_prof(int prof);

private: //refactor
    int professionality;
    int bellyful;
    int experience;
    int pies_quantity;
    int generate_rand(std::uniform_int_distribution<int> obj);
    Pie *pies_array;
};

#endif //TASK_2_BAKER_H

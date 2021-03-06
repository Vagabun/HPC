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
    int _professionality;
    int _bellyful;
    int _experience;
    int _pies_quantity;
    const int _max_pies_quantity = 100;
    int generate_rand(std::uniform_int_distribution<int> obj);
    Pie *pies_array;
};

#endif //TASK_2_BAKER_H

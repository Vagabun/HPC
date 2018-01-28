#pragma once
//#ifndef TASK_2_BAKER_H
//#define TASK_2_BAKER_H
#include "pie.h"

class Baker {
public:
    Baker();
    ~Baker();

private:
    int professionality;
    int bellyful;
    int experience;
    int generate_rand(std::uniform_int_distribution<int> obj);
    Pie *pies_array;
};


//#endif //TASK_2_BAKER_H

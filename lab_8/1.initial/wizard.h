#pragma once

#include "common.h"

class wizard {
public:
    wizard();
    ~wizard();
    void improvement();
    int magic_shield(int damage);

private:
    int _health, _attack, _attack_dist, _armor, _mana;
    int rand_generator(string choice);
    
};


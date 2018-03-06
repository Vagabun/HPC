#pragma once

#include "common.h"

class knight {
public:
    knight();
    ~knight();
    int damage();
    void take_damage(int damage);
    void eating();
    void naked_knight();
private:
    int _health, _armor, _attack, _attack_dist;
    int rand_generator(string choice);
};


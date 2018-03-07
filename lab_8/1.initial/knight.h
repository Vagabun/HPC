#pragma once

#include "common.h"

class knight {
public:
    knight();
    ~knight();
    int damage();
    int get_hp();
    void take_damage(int damage);
    void eating();
private:
    int _health, _armor, _attack, _attack_dist;
    void naked_knight();
    int rand_generator(string choice);
};


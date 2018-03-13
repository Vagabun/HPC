#pragma once

#include "common.h"

class knight {
public:
    knight();
    ~knight();
    int damage() const;
    int get_hp() const;
    int get_attack_distance() const;
    int get_armor() const;
    void take_damage(int damage);
    void eating();
private:
    int _health, _armor, _attack, _attack_dist;
    void naked_knight();
    int rand_generator(string choice);
};


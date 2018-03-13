#pragma once

#include "common.h"

class wizard {
public:
    wizard();
    ~wizard();
    int get_hp() const;
    int damage() const;
    int get_attack_distance() const;
    int get_armor() const;
    void take_damage(int damage);
    void improvement();
private:
    int _health, _attack, _attack_dist, _armor, _mana;
    int rand_generator(string choice);
    int magic_shield(int damage);
};


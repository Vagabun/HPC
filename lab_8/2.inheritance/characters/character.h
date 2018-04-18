#pragma once

#include "../helpers/common.h"

class character {
public:
    character();
    virtual ~character();
    int get_attack() const;
    int get_attack_distance() const;
    int get_health() const;
    int get_armor() const;
    int get_mana() const;
    virtual int active_ability(int enemy_health) = 0;
    virtual void take_damage(int damage);
protected:
    int _health, _attack, _attack_distance, _armor, _mana;
};


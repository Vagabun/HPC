#pragma once

#include "common.h"

class character {
public:
    character();
    virtual ~character();
    int get_attack() const;
    int get_attack_distance() const;
    int get_health() const;
    virtual int get_armor() const = 0;
    virtual void active_ability() = 0;
    virtual void take_damage(int damage);
protected:
    int rand(const string &&choice) const;
    int _health, _attack, _attack_distance;
};


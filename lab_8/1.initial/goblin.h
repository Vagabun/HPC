#pragma once

#include "common.h"

class goblin {

public:
    goblin();
	~goblin();
    int damage() const;
    int get_hp() const;
    int get_attack_distance() const;
    void take_damage(int damage);
    int bomb(int enemy_health);
    
private:
    int _health, _attack, _attack_dist;
    int call_counter = 0;
    int coward(int damage);
    int rand_generator(string choice);
};


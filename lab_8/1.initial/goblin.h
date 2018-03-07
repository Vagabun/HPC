#pragma once

#include "common.h"

class goblin {

public:
    goblin();
	~goblin();
    int damage();
    int get_hp();
    void take_damage(int damage);
    int bomb(int enemy_health);
    
private:
    int _health, _attack, _attack_dist;
    static int call_counter;
    int coward(int damage);
    int rand_generator();
};


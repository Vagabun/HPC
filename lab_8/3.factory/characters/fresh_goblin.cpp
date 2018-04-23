#include "fresh_goblin.h"

fresh_goblin::fresh_goblin() : character(), _ability_counter(0) {}

int fresh_goblin::cowardice(int damage) {
    if (damage) {
        if (_health >= 50) {
			output_wrapper::instance().print("goblin attacked himself");
            damage *= 2;
        }   
        else {
			output_wrapper::instance().print("goblin dodged from attack!");
            damage = 0;
        }
    }
    return damage;
}

int fresh_goblin::active_ability(int enemy_health) {
    int damage;
    switch (_ability_counter) {
    case 0: {
		output_wrapper::instance().print("constructing bomb...");
        damage = 0;
        _ability_counter = 1;
        break;
    }
    case 1: {
		output_wrapper::instance().print("BOOM!");
        _health -= _health - 1;
        damage = enemy_health - 1;
        _ability_counter = 0;
        break;
    }
    default:
        break;
    }
    return damage;
}

void fresh_goblin::take_damage(int damage) {
    damage = cowardice(damage);
    character::take_damage(damage);
}

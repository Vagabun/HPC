#include "fresh_goblin.h"

fresh_goblin::fresh_goblin() : character(), _ability_counter(0) {}

fresh_goblin::~fresh_goblin() {}

int fresh_goblin::cowardice(int damage) {
    if (damage) {
        if (_health >= 50) {
            cout << endl << "goblin attacked himself" << endl;
            damage *= 2;
        }   
        else {
            cout << endl << "goblin dodged from attack!";
            damage = 0;
        }
    }
    return damage;
}

int fresh_goblin::active_ability(int enemy_health) {
    int damage;
    switch (_ability_counter) {
    case 0: {
        cout << endl << "constructing bomb..." << endl;
        damage = 0;
        _ability_counter = 1;
        break;
    }
    case 1: {
        cout << endl << "BOOM!" << endl;
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

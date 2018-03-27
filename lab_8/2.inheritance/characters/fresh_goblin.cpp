#include "fresh_goblin.h"

fresh_goblin::fresh_goblin() : character() {}

fresh_goblin::~fresh_goblin() {}

int fresh_goblin::cowardice(int damage) {
    if (damage > 0) {
        if (_health >= 50) {
            cout << endl;
            cout << "goblin attacked himself" << endl;
            cout << endl;
            damage *= 2;
        }   
        else {
            cout << endl;
            cout << "goblin dodged from attack!";
            cout << endl;
            damage = 0;
        }
    }
    return damage;
}

int fresh_goblin::active_ability(int enemy_health) {
    int damage;
    switch (ability_counter) {
    case 0: {
        cout << "constructing bomb..." << endl;
        damage = 0;
        ability_counter = 1;
        break;
    }
    case 1: {
        cout << "BOOM!" << endl;
        _health -= _health - 1;
        damage = enemy_health - 1;
        ability_counter = 0;
        break;
    }
    default:
        break;
    }
    return damage;
}

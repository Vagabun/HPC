#include "fresh_knight.h"

fresh_knight::fresh_knight() : character() {
    _armor = 100;
}

fresh_knight::~fresh_knight() {}

int fresh_knight::active_ability(int enemy_health) {
    cout << endl << "eating slice of armor..." << endl;
    if (_armor <= 10) {
        cout << endl << "knight can't eat all of his armor" << endl;
        return 0;
    }
    _armor -= 10;
    _attack += 10;
    return 0;
}

void fresh_knight::naked_knight() {
    int chance = service_functions::rand(rand_variants::standard);
    if (chance <= 30 && _armor > 0) {
        cout << endl << "time for blood..." << endl;
        cout << endl << "attack increased by two times" << endl;
        _armor = 0;
        _attack *= 2;
    }
}

void fresh_knight::take_damage(int damage) {
    naked_knight();
    if (damage > 0) {
        if (_armor - damage >= 0) {
            damage = 0;
            cout << endl << "all of the damage was consumed by knight armor" << endl;
        }
        else
            damage -= _armor;
        _armor /= 2;
    }
    character::take_damage(damage);
}
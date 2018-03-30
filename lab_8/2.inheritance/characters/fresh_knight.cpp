#include "fresh_knight.h"

fresh_knight::fresh_knight() : character(), _armor(100) {}

fresh_knight::~fresh_knight() {}

void fresh_knight::active_ability() {
    cout << "eating armor..." << endl;
    if (_armor <= 10) {
        cout << "knight can't eat all of his armor" << endl;
        return;
    }
    _armor -= 10;
    _attack += 10;
}

void fresh_knight::naked_knight() {
    int chance = character::rand(0);
    if (chance <= 30 && _armor > 0) {
        cout << endl;
        cout << "time for blood..." << endl;
        cout << "attack increased by two times" << endl;
        cout << endl;
        _armor = 0;
        _attack *= 2;
    }
}

void fresh_knight::take_damage(int damage) {
    naked_knight();
    if (damage > 0) {
        if (_armor - damage >= 0) {
            damage = 0;
            cout << "all of the damage was consumed by knight armor" << endl;
        }
        else
            damage -= _armor;
        _armor /= 2;
    }
    character::take_damage(damage);
}

int fresh_knight::get_armor() const {
    return _armor;
}

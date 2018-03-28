#include "fresh_wizard.h"

fresh_wizard::fresh_wizard() : character(), _armor(0), _mana(100) {}

fresh_wizard::~fresh_wizard() {}

int fresh_wizard::get_mana() const {
    return _mana;
}

int fresh_wizard::get_armor() const {
    return _armor;
}

int fresh_wizard::magic_shield(int damage) {
    if (character::rand("default") < 30) {
        if (_mana > damage * 2) {
            _mana -= damage * 2;
            damage = 0;
            cout << endl;
            cout << "magic shield consumed all damage" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            cout << "not enough mana for magic shield" << endl;
            cout << endl;
        }    
    }
    return damage;
}

void fresh_wizard::take_damage(int damage) {
    damage = magic_shield(damage);
    if (_armor) {
        if (damage - _armor < 0) {
            damage = 0;
            cout << "all of the damage was consumed by enemy armor" << endl;
        }
        else
            damage -= _armor;
        _armor /= 2;
    }
    character::take_damage(damage);
}

void fresh_wizard::active_ability() {
    //use enum
    cout << "selecting one of four improvements..." << endl;
    switch (character::rand("ability")) {
    case 1: {
        _mana *= 2;
        cout << "wizard mana increased by 2 times" << endl;
        break;
    }
    case 2: {
        _health *= 2;
        cout << "wizard health increased by 2 times" << endl;
        break;
    }
    case 3: {
        _health = 0;
        cout << "oohps, looks like wizard suicide" << endl;
        break;
    }
    case 4: {
        _armor = 100;
        cout << "wizard created armor" << endl;
        break;
    }
    default:
        break;
    }
    _mana = 0;
}

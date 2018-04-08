#include "fresh_wizard.h"

fresh_wizard::fresh_wizard() : character() {
    _mana = 100;
}

fresh_wizard::~fresh_wizard() {}

int fresh_wizard::magic_shield(int damage) {
    if (service_functions::rand(rand_variants::standard) < 30) {
        if (_mana > damage * 2) {
            _mana -= damage * 2;
            damage = 0;
            cout << endl << "magic shield consumed all damage" << endl;
        }
        else {
            cout << endl << "not enough mana for magic shield" << endl;
        }    
    }
    return damage;
}

void fresh_wizard::take_damage(int damage) {
    damage = magic_shield(damage);
    if (_armor) {
        if (damage - _armor <= 0) {
            damage = 0;
            cout << endl << "all of the damage was consumed by wizard armor" << endl;
        }
        else
            damage -= _armor;
        _armor /= 2;
    }
    character::take_damage(damage);
}

int fresh_wizard::active_ability(int enemy_health) {
    cout << endl << "selecting one of four improvements..." << endl;
    switch (service_functions::rand(rand_variants::wizard_ability)) {
    case improvements::mana : {
        _mana *= 2;
        cout << endl << "wizard mana increased by 2 times" << endl;
        break;
    }
    case improvements::health : {
        _health *= 2;
        cout << endl << "wizard health increased by 2 times" << endl;
        break;
    }
    case improvements::suicide : {
        _health = 0;
        cout << endl << "oohps, looks like wizard suicide" << endl;
        break;
    }
    case improvements::armor : {
        _armor = 100;
        cout << endl << "wizard created armor" << endl;
        break;
    }
    default:
        break;
    }
    _mana = 0;
    return 0;
}

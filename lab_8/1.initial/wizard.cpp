#include "wizard.h"

wizard::wizard() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("default");
    _mana = rand_generator("default");
    _armor = 0;
}

wizard::~wizard() {}

void wizard::take_damage(int damage) {
    if (damage > _health) {
        _health = 0;
        cout << "wizard killed" << endl;
        return;
    }
    _health -= damage;
}

int wizard::damage() {
    return _attack;
}

void wizard::improvement() {
    cout << "selecting one of four improvements..." << endl;
    switch (rand_generator("active")) {
    case 1: {
        _mana *= 2;
        cout << "increase mana by 2 times" << endl;
        break;
    }
    case 2: {
        _health *= 2;
        cout << "increase health by 2 times" << endl;
        break;
    }
    case 3: {
        _health = 0;
        cout << "oohps, looks like suicide" << endl;
        break;
    }
    case 4: {
        _armor = rand_generator("default");
        cout << "create armor" << endl;
        break;
    }
    default:
        break;
    }

    _mana = 0;
}

int wizard::magic_shield(int damage) {
    if (rand_generator("default") < 30) {
        if (_mana > damage * 2) {
            _mana -= damage * 2;
            cout << "magic shield reflected damage" << endl;
            return 0;
        }
        else
            cout << "not enough mana" << endl;
    }
    return damage;
}

int wizard::rand_generator(string choice) {
    random_device rd;
    mt19937 gen(rd());
    if (choice == "default") {
        uniform_int_distribution<> dist(1, 100);
        return dist(gen);
    }
    else if (choice == "active") {
        uniform_int_distribution<> dist(1, 4);
        return dist(gen);
    }
}
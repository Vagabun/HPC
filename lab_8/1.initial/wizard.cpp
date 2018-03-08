#include "wizard.h"

wizard::wizard() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("distance");
    _mana = rand_generator("default");
    _armor = 0;
}

wizard::~wizard() {}

int wizard::get_hp() {
    return this->_health;
}

int wizard::get_attack_distance() {
    return this->_attack_dist;
}

void wizard::take_damage(int damage) {
    damage = this->magic_shield(damage);
    if (damage > this->_health) {
        this->_health = 0;
        cout << "wizard killed" << endl;
        return;
    }
    this->_health -= damage;
}

int wizard::damage() {
    return _attack;
}

void wizard::improvement() {
    cout << "selecting one of four improvements..." << endl;
    switch (rand_generator("ability")) {
    case 1: {
        this->_mana *= 2;
        cout << "mana increased by 2 times" << endl;
        break;
    }
    case 2: {
        this->_health *= 2;
        cout << "health increased by 2 times" << endl;
        break;
    }
    case 3: {
        this->_health = 0;
        cout << "oohps, looks like suicide" << endl;
        break;
    }
    case 4: {
        this->_armor = rand_generator("default");
        cout << "create armor" << endl;
        break;
    }
    default:
        break;
    }
    this->_mana = 0;
}

int wizard::magic_shield(int damage) {
    if (rand_generator("default") < 30) {
        if (this->_mana > damage * 2) {
            this->_mana -= damage * 2;
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
    else if (choice == "ability") {
        uniform_int_distribution<> dist(1, 4);
        return dist(gen);
    }
    else if (choice == "distance") {
        uniform_int_distribution<> dist(1, 7);
        return dist(gen);
    }
}
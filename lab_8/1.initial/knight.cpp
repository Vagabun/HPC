#include "knight.h"

knight::knight() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("default");
    _armor = 100;
}


knight::~knight() {
}

int knight::damage() {
    return _attack;
}

void knight::take_damage(int damage) {
    damage -= _armor;
    if (damage < 0)
        damage = 0;
    _health -= damage;
    _armor /= 2;
}

void knight::eating() {
    cout << "eating armor..." << endl;
    int armor_slice = 10;
    if (_armor <= 10) {
        cout << "knight can't eat all of his armor" << endl;
        return;
    }
    _armor -= armor_slice;
    _attack += armor_slice;
}

void knight::naked_knight() {
    int chance = rand_generator("default");
    if (chance <= 30 && _armor > 0) {
        cout << "time for blood..." << endl;
        _armor = 0;
        _attack *= 2;
    }
}

int knight::rand_generator(string choice) {
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

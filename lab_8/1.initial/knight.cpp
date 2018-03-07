#include "knight.h"

knight::knight() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("default");
    _armor = 100;
}

knight::~knight() {}

int knight::damage() {
    return this->_attack;
}

int knight::get_hp() {
    return this->_health;
}

void knight::take_damage(int damage) {
    this->naked_knight();
    damage -= this->_armor;
    if (damage < 0)
        damage = 0;
    this->_health -= damage;
    this->_armor /= 2;
}

void knight::eating() {
    cout << "eating armor..." << endl;
    int armor_slice = 10;
    if (this->_armor <= 10) {
        cout << "knight can't eat all of his armor" << endl;
        return;
    }
    this->_armor -= armor_slice;
    this->_attack += armor_slice;
}

void knight::naked_knight() {
    int chance = rand_generator("default");
    if (chance <= 30 && this->_armor > 0) {
        cout << "time for blood..." << endl;
        cout << "attack increased by two times" << endl;
        this->_armor = 0;
        this->_attack *= 2;
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

#include "knight.h"

knight::knight() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("distance");
    _armor = 100;
}

knight::~knight() = default;

int knight::damage() const {
    return this->_attack;
}

int knight::get_hp() const {
    return this->_health;
}

int knight::get_attack_distance() const {
    return this->_attack_dist;
}

int knight::get_armor() const {
    return this->_armor;
}

void knight::take_damage(int damage) {
    this->naked_knight();
    damage -= this->_armor;
    if (damage < 0) {
        cout << "all of the damage was consumed by enemy armor" << endl;
        damage = 0;
    }
    else if (damage >= this->_health) {
        this->_health = 0;
        cout << "knight killed!" << endl;
        return;
    }
    this->_health -= damage;
    this->_armor /= 2;
    cout << "knight took " << damage << " damage" << endl;
    cout << "his current health is " << this->_health << " points" << endl;
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
        cout << endl;
        cout << "time for blood..." << endl;
        cout << "attack increased by two times" << endl;
        cout << endl;
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
    else if (choice == "distance") {
        uniform_int_distribution<> dist(1, 7);
        return dist(gen);
    }
}

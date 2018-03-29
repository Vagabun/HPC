#include "character.h"

character::character() : _health(100), _attack(rand("default")), _attack_distance(rand("distance")) {}

character::~character() {
    //?
    /*if (this != nullptr)
        delete this;*/
};

int character::get_attack() const {
    return _attack;
}

int character::get_attack_distance() const {
    return _attack_distance;
}

int character::get_health() const {
    return _health;
}

int character::get_armor() const {
    return 0;
}

int character::get_mana() const {
    return 0;
}

void character::active_ability() {
    return;
}

int character::active_ability(int enemy_health) {
    return 0;
}

void character::take_damage(int damage) {
    cout << "character took " << damage << endl;
    if (damage > _health) {
        _health = 0;
        return;
    }
    _health -= damage;
    cout << "current health is " << _health << " points" << endl;
}

int character::rand(const string &&choice) const {
    //move variants to enum
    random_device rd;
    mt19937 gen(rd());
    if (choice == "default") {
        uniform_int_distribution<> r(1, 100);
        return r(gen);
    }
    else if (choice == "distance") {
        uniform_int_distribution<> r(1, 6);
        return r(gen);
    }
    else if (choice == "ability") {
        uniform_int_distribution<> r(1, 4);
        return r(gen);
    }
}

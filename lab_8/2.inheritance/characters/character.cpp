#include "character.h"

character::character() : _health(100), _attack(service_functions::rand(rand_variants::standard)), 
    _attack_distance(service_functions::rand(rand_variants::distance)), _armor(0), _mana(0) {}

character::~character() {
    cout << "character destructor" << endl;
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
    return _armor;
}

int character::get_mana() const {
    return _mana;
}

void character::take_damage(int damage) {
    if (damage) {
        cout << "character took " << damage << " damage" << endl;
        if (damage > _health) {
            _health = 0;
            return;
        }
        _health -= damage;
        cout << "current health is " << _health << " points" << endl;
    }
}

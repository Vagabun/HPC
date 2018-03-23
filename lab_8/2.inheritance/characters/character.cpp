#include "character.h"

character::character() : _health(100), _attack(rand_gen("default")), _attack_distance(rand_gen("distance")) {}

character::~character() = default;

int character::rand_gen(const string &&choice) const {
    random_device rd;
    mt19937 gen(rd());
    if (choice == "default") {
        uniform_int_distribution<> r(1, 100);
        return r(gen);
    }
    else if (choice == "distance") {
        uniform_int_distribution<> r(1, 7);
        return r(gen);
    }
}

#include "fresh_knight.h"

fresh_knight::fresh_knight() : character() {
    _armor = 100;
}

int fresh_knight::active_ability(int enemy_health) {
	output_wrapper::instance().print("eating slice of an armor...");
    if (_armor <= 10) {
		output_wrapper::instance().print("knight can't eat all of his armor");
        return 0;
    }
    _armor -= 10;
    _attack += 10;
    return 0;
}

void fresh_knight::naked_knight() {
    int chance = helpers::rand(helpers::rand_variants::standard);
    if (chance <= 30 && _armor > 0) {
		output_wrapper::instance().print("time for blood...");
		output_wrapper::instance().print("no armor, all man - attack increased by two times");
        _armor = 0;
        _attack *= 2;
    }
}

void fresh_knight::take_damage(int damage) {
    naked_knight();
    if (damage) {
        if (_armor - damage >= 0) {
            damage = 0;
			output_wrapper::instance().print("all of the damage was consumed by knight armor");
        }
        else
            damage -= _armor;
        _armor /= 2;
    }
    character::take_damage(damage);
}
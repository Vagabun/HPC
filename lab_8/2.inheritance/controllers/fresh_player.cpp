#include "fresh_player.h"

fresh_player::fresh_player(string name) : _name(name) {}

fresh_player::~fresh_player() {
    cout << "fresh player destructor" << endl;
}

void fresh_player::set_character_class(int choice) {
    switch (choice) {
    case heroes::knight : {
        _hero = move(unique_ptr<character>(new fresh_knight));
        _current_class = "knight";
        break;
    }
    case heroes::wizard : {
        _hero = move(unique_ptr<character>(new fresh_wizard));
        _current_class = "wizard";
        break;
    }
    case heroes::goblin : {
        _hero = move(unique_ptr<character>(new fresh_goblin));
        _current_class = "goblin";
        break;
    }
    default:
        break;
    }
}

int fresh_player::get_health() const {
    return _hero->get_health();
}

int fresh_player::get_attack() const {
    return _hero->get_attack();
}

int fresh_player::get_attack_distance() const {
    return _hero->get_attack_distance();
}

int fresh_player::get_armor() const {
    return _hero->get_armor();
}

int fresh_player::get_mana() const {
    return _hero->get_mana();
}

int fresh_player::active_ability(int enemy_health) {
    return _hero->active_ability(enemy_health);
}

void fresh_player::take_damage(int damage) {
    _hero->take_damage(damage);
}

void fresh_player::set_position(int position) {
	if (!_init_position)
		_init_position = position;
    _current_position = position;
}

int fresh_player::get_position() const {
    return _current_position;
}

int fresh_player::get_init_position() const {
	return _init_position;
}

string fresh_player::get_current_class() const {
    return _current_class;
}

string fresh_player::get_name() const {
    return _name;
}

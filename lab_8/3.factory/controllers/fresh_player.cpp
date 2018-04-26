#include "fresh_player.h"

fresh_player::fresh_player(string name) : _name(name) {
	_knight_f = move(unique_ptr<knight_factory>(new knight_factory));
	_wizard_f = move(unique_ptr<wizard_factory>(new wizard_factory));
	_goblin_f = move(unique_ptr<goblin_factory>(new goblin_factory));
}

void fresh_player::set_character_class(int character_class) {
	switch (character_class) {
		case _heroes::knight : {
			_hero = move(_knight_f->create_character());
			_current_class = "knight";
			break;
		}
		case _heroes::wizard: {
			_hero = move(_wizard_f->create_character());
			_current_class = "wizard";
			break;
		}
		case _heroes::goblin: {
			_hero = move(_goblin_f->create_character());
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
	int damage = _hero->active_ability(enemy_health);
	if (!_hero->get_health())
		_dead = true;
    return damage;
}

void fresh_player::take_damage(int damage) {
    _hero->take_damage(damage);
	if (!_hero->get_health())
		_dead = true;
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

bool fresh_player::dead() const {
    return _dead;
}

string fresh_player::get_current_class_name() const {
    return _current_class;
}

string fresh_player::get_player_name() const {
    return _name;
}

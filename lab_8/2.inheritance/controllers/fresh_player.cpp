#include "fresh_player.h"

fresh_player::fresh_player(int choice) {
    switch (choice) {
    case heroes::knight : {
        hero = move(unique_ptr<character>(new fresh_knight));
        _current_class = "knight";
        break;
    }
    case heroes::wizard : {
        hero = move(unique_ptr<character>(new fresh_wizard));
        _current_class = "wizard";
        break;
    }
    case heroes::goblin : {
        hero = move(unique_ptr<character>(new fresh_goblin));
        _current_class = "goblin";
        break;
    }
    default:
        break;
    }
}

fresh_player::~fresh_player() {
    cout << "player destructor" << endl;
}

int fresh_player::get_health() const {
    return hero->get_health();
}

int fresh_player::get_attack() const {
    return hero->get_attack();
}

int fresh_player::get_attack_distance() const {
    return hero->get_attack_distance();
}

int fresh_player::get_armor() const {
    return hero->get_armor();
}

int fresh_player::get_mana() const {
    return hero->get_mana();
}

void fresh_player::active_ability() {
    hero->active_ability();
}

int fresh_player::active_ability(int enemy_health) {
    return hero->active_ability(enemy_health);
}

void fresh_player::take_damage(int damage) {
    hero->take_damage(damage);
}

void fresh_player::set_position(int position) {
    _current_position = position;
}

int fresh_player::get_position() const {
    return _current_position;
}

string fresh_player::get_current_class() const {
    return _current_class;
}

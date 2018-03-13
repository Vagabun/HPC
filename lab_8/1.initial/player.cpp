#include "player.h"

player::player() = default;

player::player(string choice) {
    while (1) {
        if (choice == "1") {
            cout << "you have chosen Knight class" << endl << endl;
            current_class = "knight";
            break;
        }
        else if (choice == "2") {
            cout << "you have chosen Wizard class" << endl << endl;
            current_class = "wizard";
            break;
        }
        else if (choice == "3") {
            cout << "you have chosen Goblin class" << endl << endl;
            current_class = "goblin";
            break;
        }
        else
            cout << "wrong input, try again" << endl << endl;
    }
}

player::~player() = default;

int player::get_damage() const {
    if (this->current_class == "knight")
        return this->k.damage();
    else if (this->current_class == "goblin")
        return this->g.damage();
    else if (this->current_class == "wizard")
        return this->w.damage();
}

int player::get_hp() const {
    if (this->current_class == "knight")
        return this->k.get_hp();
    else if (this->current_class == "goblin")
        return this->g.get_hp();
    else if (this->current_class == "wizard")
        return this->w.get_hp();
}

int player::get_position() const {
    return _current_position;
}

int player::get_attack_distance() const {
    if (this->current_class == "knight")
        return this->k.get_attack_distance();
    else if (this->current_class == "goblin")
        return this->g.get_attack_distance();
    else if (this->current_class == "wizard")
        return this->w.get_attack_distance();
}

string player::get_type() const {
    return this->current_class;
}

void player::set_position(int position) {
    _current_position = position;
}

void player::take_damage(int damage) {
    if (this->current_class == "knight")
        this->k.take_damage(damage);
    else if (this->current_class == "goblin")
        this->g.take_damage(damage);
    else if (this->current_class == "wizard")
        this->w.take_damage(damage);
}

void player::ability(player &enemy) {
    if (this->current_class == "knight")
        this->k.eating();
    else if (this->current_class == "goblin")
        enemy.take_damage(this->g.bomb(enemy.get_hp()));
    else if (this->current_class == "wizard")
        this->w.improvement();
}

bool player::is_dead() const {
    if (this->current_class == "knight")
        return (this->k.get_hp() == 0);
    else if (this->current_class == "goblin")
        return (this->g.get_hp() == 0);
    else if (this->current_class == "wizard")
        return (this->w.get_hp() == 0);
}

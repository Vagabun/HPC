#include "player.h"

player::player() {}

player::player(string choice) {
    if (choice == "1") {
        cout << "you have chosen Knight class" << endl << endl;
        current_class = "knight";
    } 
    else if (choice == "2") {
        cout << "you have chosen Wizard class" << endl << endl;
        current_class = "wizard";
    }
    else if (choice == "3") {
        cout << "you have chosen Goblin class" << endl << endl;
        current_class = "goblin";
    }
}

player::~player() {}

int player::get_damage() {
    if (this->current_class == "knight")
        return this->k.damage();
    else if (this->current_class == "goblin")
        return this->g.damage();
    else if (this->current_class == "wizard")
        return this->w.damage();
}

int player::get_hp() {
    if (this->current_class == "knight")
        return this->k.get_hp();
    else if (this->current_class == "goblin")
        return this->g.get_hp();
    else if (this->current_class == "wizard")
        return this->w.get_hp();
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

bool player::is_dead() {
    if (this->current_class == "knight")
        return ((this->k.get_hp() == 0) ? true : false);
    else if (this->current_class == "goblin")
        return ((this->g.get_hp() == 0) ? true : false);
    else if (this->current_class == "wizard")
        return ((this->w.get_hp() == 0) ? true : false);
}

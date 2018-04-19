#pragma once

#include "../characters/character.h"
#include "../characters/fresh_knight.h"
#include "../characters/fresh_wizard.h"
#include "../characters/fresh_goblin.h"

class fresh_player {
public:
    fresh_player(string name);
    ~fresh_player();
    void set_character_class(int choice);
    int get_health() const;
    int get_attack() const;
    int get_attack_distance() const;
    int get_armor() const;
    int get_mana() const;
    int active_ability(int enemy_health);
    void take_damage(int damage);
    void set_position(int position);
    int get_position() const;
	int get_init_position() const;
    bool dead() const;
    string get_current_class_name() const;
    string get_player_name() const;
private:
    unique_ptr<character> _hero;
    string _current_class, _name;
	bool _dead = false;
    int _current_position, _init_position = 0;
    enum _heroes {knight = 1, wizard, goblin};
};


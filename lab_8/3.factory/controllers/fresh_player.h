#pragma once

#include "../factories/knight_factory.h"
#include "../factories/wizard_factory.h"
#include "../factories/goblin_factory.h"

class fresh_player {
public:
    fresh_player(string name);
    ~fresh_player() = default;
    void set_character_class(int character_class);
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
	unique_ptr<knight_factory> _knight_f;
	unique_ptr<wizard_factory> _wizard_f;
	unique_ptr<goblin_factory> _goblin_f;
    string _current_class, _name;
	bool _dead = false;
    int _current_position, _init_position = 0;
    enum _heroes {knight = 1, wizard, goblin};
};


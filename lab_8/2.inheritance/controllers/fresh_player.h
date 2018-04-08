#pragma once

#include "../characters/character.h"
#include "../characters/fresh_knight.h"
#include "../characters/fresh_wizard.h"
#include "../characters/fresh_goblin.h"

class fresh_player {
public:
    explicit fresh_player(int choice);
    ~fresh_player();
    int get_health() const;
    int get_attack() const;
    int get_attack_distance() const;
    int get_armor() const;
    int get_mana() const;
    int active_ability(int enemy_health);
    void take_damage(int damage);
    void set_position(int position);
    int get_position() const;
    string get_current_class() const;
private:
    //character *hero ?
    unique_ptr<character> hero;
    string _current_class;
    int _current_position;
    enum _heroes {knight = 1, wizard, goblin};
};


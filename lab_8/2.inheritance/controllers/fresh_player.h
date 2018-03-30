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
    void active_ability();
    int active_ability(int enemy_health) const;
    void take_damage(int damage) const;


private:
    //character *hero ?
    unique_ptr<character> hero;
    string _current_class;
    enum heroes {knight = 1, wizard, goblin};
};


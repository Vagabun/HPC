#pragma once

#include "../characters/knight.h"
#include "../characters/goblin.h"
#include "../characters/wizard.h"

class player {
public:
    player();
    player(string choice);
    ~player();
    int get_damage() const;
    int get_hp() const;
    int get_position() const;
    int get_attack_distance() const;
    int get_armor() const;
    string get_type() const;
    void set_position(int position);
    void take_damage(int damage);
    void ability(player &enemy);
    bool is_dead() const;
private:
    knight k; 
    goblin g; 
    wizard w;
    string current_class;
    int _current_position;
};


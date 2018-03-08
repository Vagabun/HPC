#pragma once

#include "knight.h"
#include "goblin.h"
#include "wizard.h"

class player {
public:
    player();
    player(string choice);
    ~player();
    int get_damage();
    int get_hp();
    int get_position();
    void set_position(int position);
    void take_damage(int damage);
    void ability(player &enemy);
    bool is_dead();
private:
    knight k; 
    goblin g; 
    wizard w;
    string current_class;
    int _current_position;
};


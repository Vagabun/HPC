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
    void take_damage(int damage);
    string current_class;
private:
    knight k; 
    goblin g; 
    wizard w;
};


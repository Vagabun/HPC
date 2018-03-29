#pragma once

#include "../characters/character.h"
#include "../characters/fresh_knight.h"

class fresh_player {
public:
    fresh_player();
    ~fresh_player();
private:
    //character *hero
    unique_ptr<character> hero;
    string _current_class;
};


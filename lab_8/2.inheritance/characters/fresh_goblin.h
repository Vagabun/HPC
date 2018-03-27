#pragma once

#include "character.h"

class fresh_goblin : public character {
public:
    fresh_goblin();
    ~fresh_goblin();
private:
    int ability_counter = 0;
    int cowardice(int damage);
    int active_ability(int enemy_health) override;
};


#pragma once

#include "character.h"

class fresh_goblin : public character {
public:
    fresh_goblin();
    ~fresh_goblin();
private:
    int _ability_counter;
    int cowardice(int damage);
    int active_ability(int enemy_health) override;
    void take_damage(int damage) override;
};


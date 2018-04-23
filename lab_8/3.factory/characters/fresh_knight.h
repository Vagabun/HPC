#pragma once

#include "character.h"

class fresh_knight : public character {
public:
    fresh_knight();
    ~fresh_knight() = default;
private:
    int active_ability(int enemy_health) override;
    void naked_knight();
    void take_damage(int damage) override;
};


#pragma once

#include "character.h"

class fresh_wizard : public character {
public:
    fresh_wizard();
    ~fresh_wizard();
private:
    enum improvements {mana = 1, health, suicide, armor};
    int magic_shield(int damage);
    void take_damage(int damage) override;
    void active_ability() override;
};


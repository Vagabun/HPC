#pragma once

#include "character.h"

class fresh_wizard : public character {
public:
    fresh_wizard();
    ~fresh_wizard();
private:
    int _armor, _mana;
    enum improvements {mana = 1, health, suicide, armor};
    int get_mana() const override;
    int get_armor() const override;
    int magic_shield(int damage);
    void take_damage(int damage) override;
    void active_ability() override;
};


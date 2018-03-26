#pragma once

#include "character.h"

class fresh_knight : public character {
public:
    fresh_knight();
    ~fresh_knight();
private:
    int _armor;
    int get_armor() const override;
    void active_ability() override;
    void naked_knight();
    void take_damage(int damage) override;
};


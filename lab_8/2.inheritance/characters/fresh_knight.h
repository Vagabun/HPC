#pragma once

#include "character.h"

class fresh_knight : public character {
public:
    fresh_knight();
    ~fresh_knight();
    void ability() override;
private:
    int _armor;
};


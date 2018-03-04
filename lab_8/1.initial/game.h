#pragma once

#include "player.h"

class game {
public:
    game();
    game(player p1, player p2);
    ~game();
    void attack(int who);
    void trigger(int who);

private:
    player _a, _b;
};


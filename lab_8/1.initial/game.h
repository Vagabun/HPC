#pragma once

#include "player.h"

class game {
public:
    game();
    game(player p1, player p2);
    ~game();
    void attack(int who);
    void ability(int who);
    bool is_dead(int who);
    void movement(int who);
    void check_status(int who);

private:
    player _a, _b;
    const int left_border = 1, right_border = 7;
    bool move_forward(int who);
    bool move_backward(int who);
    bool distance_handler(player &p);
};


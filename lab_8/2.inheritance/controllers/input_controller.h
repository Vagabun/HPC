#pragma once

#include "fresh_game.h"

class input_controller {
public:
    input_controller();
    ~input_controller();
    void start();
private:
    unique_ptr<fresh_game> _game;
    const enum actions {attack = 1, ability, move_forward, move_backward, check_status};
    int _players_counter;
    void create_players();
    const set<int> character_variants{ 1, 2, 3 };
};


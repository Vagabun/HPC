#pragma once

#include "fresh_game.h"

class input_controller {
public:
    input_controller();
    ~input_controller();
    void start();
private:
    unique_ptr<fresh_game> _game;
    enum actions {attack = 1, ability, move_forward, move_backward, check_status};
    const set<int> character_variants{ 1, 2, 3 };
    int _players_counter;
    void create_players();
};


#pragma once

#include "fresh_game.h"

class input_controller {
public:
    input_controller();
    ~input_controller() = default;
    void start();
private:
    unique_ptr<fresh_game> _game;
    enum _actions {attack = 1, ability, move_forward, move_backward, check_status};
    const set<int> _character_variants { 1, 2, 3 };
    int _players_counter;
    void _create_players();
	output_wrapper_interface &_output;
};


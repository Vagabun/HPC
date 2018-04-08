#pragma once

#include "fresh_player.h"

class fresh_game {
public:
    fresh_game();
    ~fresh_game();
    void add_player(int choice);
    void attack();
    //void ability();
private:
    vector< unique_ptr<fresh_player> > player;
    //unique_ptr<fresh_player> player1, player2;
    const int _left_border = 1, _right_border = 7;
    /*int _current_player;
    enum players {first = 1, second};
    bool distance_check(unique_ptr<fresh_player> const &p);*/
};


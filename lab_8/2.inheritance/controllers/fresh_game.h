#pragma once

#include "fresh_player.h"

class fresh_game {
public:
    fresh_game();
    ~fresh_game();
    void add_player(int choice);
    void attack();
    void ability();
	void move_forward();
	void move_backward();
private:
	void _get_player();
	void _switch_player();
	bool _distance_handler();
    queue< unique_ptr<fresh_player> > _players;
	unique_ptr<fresh_player> _current_player;
	//const map<string, int> _positions{ {"left_border", 1}, {"right_border", 7} };
	//array< unique_ptr<fresh_player>, 7 > _field;
	//array<int, 2> _positions = { {1, 7} };
    //unique_ptr<fresh_player> player1, player2;
    const int _left_border = 1, _right_border = 7;
	const enum borders {left = 1, right = 7};
    /*int _current_player;
    enum players {first = 1, second};
    bool distance_check(unique_ptr<fresh_player> const &p);*/
};


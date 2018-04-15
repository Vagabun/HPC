#pragma once

#include "fresh_player.h"

class fresh_game {
public:
    fresh_game();
    ~fresh_game();
    void add_player(string name);
    void set_class(int choice);
    string get_player_name() const;
    void attack();
    void ability();
    bool enemy_is_dead();
    void status() const;
	void move_forward();
	void move_backward();
private:
	void _get_player();
	void _switch_player();
	bool _distance_handler();
    queue< unique_ptr<fresh_player> > _players;
	unique_ptr<fresh_player> _current_player;
	enum _borders {left = 1, right = 7};
};


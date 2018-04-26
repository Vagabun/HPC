#include "fresh_game.h"

fresh_game::fresh_game() : _output(_output) {}

void fresh_game::add_player(string name) {
    _players.emplace(new fresh_player(name));
    _players.size() > 1 ? _players.back()->set_position(_borders::right) : _players.back()->set_position(_borders::left);
}

void fresh_game::set_class(int choice) {
    _players.back()->set_character_class(choice);
}

string fresh_game::get_player_name() const {
    return _players.front()->get_player_name();
}

void fresh_game::attack() {
	_get_player();
	if (_distance_handler()) {
		_players.front()->take_damage(_current_player->get_attack());
		_switch_player();
	}
    else {
		
        _output.print("enemy is too far for the attack");
        _switch_player();
    }
}

void fresh_game::ability() {
	_get_player();
	_players.front()->take_damage(_current_player->active_ability(_players.front()->get_health()));
    _switch_player();
}

bool fresh_game::enemy_is_dead() {
	return _players.size() < 2;
}

void fresh_game::status() const {
    cout << endl;
    cout << "player name: " << _players.front()->get_player_name() << endl;
    cout << "current class: " << _players.front()->get_current_class_name() << endl;
    cout << "current health: " << _players.front()->get_health() << endl;
    cout << "attack power: " << _players.front()->get_attack() << endl;
    cout << "attack distance: " << _players.front()->get_attack_distance() << endl;
    cout << "armor: " << _players.front()->get_armor() << endl;
    cout << "mana: " << _players.front()->get_mana() << endl;
    cout << "current position: " << _players.front()->get_position() << endl;
    cout << endl;

}

void fresh_game::move_forward() {
	_get_player();
    switch (_current_player->get_init_position()) {
        case _borders::left : {
            if (_current_player->get_position() + 1 != _players.front()->get_position())
                _current_player->set_position(_current_player->get_position() + 1);
            else
                _output.print("can't move forward, another player there");
            break;
        }
        case _borders::right : {
            if (_current_player->get_position() - 1 != _players.front()->get_position())
                _current_player->set_position(_current_player->get_position() - 1);
            else
                _output.print("can't move forward, another player there");
            break;
        }
    }
	_switch_player();
}

void fresh_game::move_backward() {
	_get_player();
    switch (_current_player->get_init_position()) {
        case _borders::left : {
            if (_current_player->get_position() - 1 >= _borders::left)
                _current_player->set_position(_current_player->get_position() - 1);
            else
                _output.print("can't move backward, reached the border");
            break;
        }
        case _borders::right : {
            if (_current_player->get_position() + 1 <= _borders::right)
                _current_player->set_position(_current_player->get_position() + 1);
            else
                _output.print("can't move backward, reached the border");
            break;
        }
    }
    _switch_player();
}

void fresh_game::_get_player() {
	_current_player = move(_players.front());
	_players.pop();
}

void fresh_game::_switch_player() {
	if (_players.front()->dead())
		_players.pop();
	else if (!_current_player->dead())
		_players.push(move(_current_player));
}

bool fresh_game::_distance_handler() {
	return _current_player->get_attack_distance() >= abs(_current_player->get_position() - _players.front()->get_position());
}
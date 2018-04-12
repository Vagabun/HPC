#include "fresh_game.h"

fresh_game::fresh_game() {}

fresh_game::~fresh_game() {
    cout << "game destructor" << endl;
}

//choice from listener
void fresh_game::add_player(int choice) {
	_players.emplace(new fresh_player(choice));
	_players.size() > 1 ? _players.back()->set_position(_right_border) : _players.back()->set_position(_left_border);
    //player.emplace(new fresh_player(choice));
	/*_players.size() > 1 ? _players.back()->set_position(_positions.find("left_border")) : 
    (player.size() > 1) ? player.back()->set_position(_right_border) : player.back()->set_position(_left_border);*/
}

void fresh_game::attack() {
	_get_player();
	if (_distance_handler()) {
		_players.front()->take_damage(_current_player->get_attack());
		_switch_player();
	}
	else
		cout << "enemy is too far for attack" << endl;
	
}

void fresh_game::ability() {
	_get_player();
	_players.front()->take_damage(_current_player->active_ability(_players.front()->get_health()));
	_switch_player();

}

void fresh_game::_get_player() {
	_current_player = move(_players.front());
	_players.pop();
}

void fresh_game::_switch_player() {
	_players.push(move(_current_player));
}

bool fresh_game::_distance_handler() {
	return _current_player->get_attack_distance >= abs(_current_player->get_position() - _players.front()->get_position());
}

//void fresh_game::ability() {
//    switch (_current_player) {
//    case players::first : {
//        if (player1->get_current_class() == "goblin") {
//            player2->take_damage(player1->active_ability(player2->get_health()));
//            break;
//        }
//        player1->active_ability();
//        break;
//    }
//    case players::second : {
//        if (player2->get_current_class() == "goblin") {
//            player1->take_damage(player2->active_ability(player1->get_health()));
//            break;
//        }
//        player2->active_ability();
//        break;
//    }
//    default:
//        break;
//    }
//}
//
//bool fresh_game::distance_check(unique_ptr<fresh_player> const &p) {
//    return (p->get_attack_distance() >= (player2->get_position() - player1->get_position()));
//}

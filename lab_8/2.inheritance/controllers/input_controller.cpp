#include "input_controller.h"

input_controller::input_controller() : _game(move(unique_ptr<fresh_game>(new fresh_game))), 
    _players_counter(0) {}

input_controller::~input_controller() {
    cout << "input controller destructor" << endl;
}

void input_controller::start() {
    cout << endl << "start..." << endl;
    int action;
    create_players();
    while (true) {
        cout << endl << "player " << _game->get_player_name() << " - choose one of five actions: " << endl;
        cout << "type 1 for attack, type 2 to use ability of your character, type 3 to move forward, type 4 to move backward, type 5 to check status of your character" << endl;
        cin >> action;
        switch (action) {
            case actions::attack : {
                cout << "attack!" << endl;
                _game->attack();
                break;
            }
            case actions::ability : {
                cout << "ability!" << endl;
                _game->ability();
                break;
            }
            case actions::move_forward : {
                _game->move_forward();
                break;
            }
            case actions::move_backward : {
                _game->move_backward();
                break;
            }
            case actions::check_status : {
                _game->status();
                break;
            }
            default: {
                cout << "wrong input, try again" << endl;
                break;
            } 
        }
        if (_game->enemy_is_dead()) {
            cout << endl << "enemy is dead" << endl;
            cout << endl << "player " << _game->get_player_name() << " won!" << endl;
            break;
        }
    }
}

void input_controller::create_players() {
    string name;
    int choice;
    while (_players_counter < 2) {
        cout << endl << "player, write your name" << endl;
        cin >> name;
        _game->add_player(name);
        cout << endl << "choose your class: " << endl;
        cout << "type 1 for the Knight class, type 2 for the Wizard class, type 3 for the Goblin class" << endl;
        while (true) {
            cin >> choice;
            if (character_variants.count(choice)) {
                _game->set_class(choice);
                break;
            }
            else
                cout << "wrong input, try again" << endl;
        }
        ++_players_counter;
    }
}

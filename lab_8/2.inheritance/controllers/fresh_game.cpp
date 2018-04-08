#include "fresh_game.h"

fresh_game::fresh_game() : _current_player(players::first) {
    //move to separate class (listener)
    cout << "player 1 - choose your hero" << endl;
    int choice;
    cin >> choice;
    player1 = move(unique_ptr<fresh_player>(new fresh_player(choice)));
    player1->set_position(_left_border);
    cout << "player 2 - choose your hero" << endl;
    cin >> choice;
    player2 = move(unique_ptr<fresh_player>(new fresh_player(choice)));
    player2->set_position(_right_border);
}


fresh_game::~fresh_game() {
    cout << "game destructor" << endl;
}

void fresh_game::attack() {
    switch (_current_player) {
    case players::first : {
        if (distance_check(player1))
            player2->take_damage(player1->get_attack());
        else
            cout << endl << "enemy is too far for attack" << endl;
        break;
    }
    case players::second : {
        if (distance_check(player2))
            player1->take_damage(player2->get_attack());
        else
            cout << endl << "enemy is too far for attack" << endl;
        break;
    }
    default:
        break;
    }
}

void fresh_game::ability() {
    switch (_current_player) {
    case players::first : {
        if (player1->get_current_class() == "goblin") {
            player2->take_damage(player1->active_ability(player2->get_health()));
            break;
        }
        player1->active_ability();
        break;
    }
    case players::second : {
        if (player2->get_current_class() == "goblin") {
            player1->take_damage(player2->active_ability(player1->get_health()));
            break;
        }
        player2->active_ability();
        break;
    }
    default:
        break;
    }
}

bool fresh_game::distance_check(unique_ptr<fresh_player> const &p) {
    return (p->get_attack_distance() >= (player2->get_position() - player1->get_position()));
}

#include "fresh_game.h"

fresh_game::fresh_game() {}

fresh_game::~fresh_game() {
    cout << "game destructor" << endl;
}

void fresh_game::add_player(int choice) {
    player.emplace_back(new fresh_player(choice));
    (player.size() > 1) ? player.back()->set_position(_right_border) : player.back()->set_position(_left_border);
}

void fresh_game::attack() {
    player.back()->take_damage(player.front()->get_attack());
    swap(player.front(), player.back());
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

#include "fresh_player.h"

fresh_player::fresh_player() {
    hero = move(unique_ptr<character> (new fresh_knight));
    hero->get_armor();

}

fresh_player::~fresh_player() {
    cout << "player destructor" << endl;
}

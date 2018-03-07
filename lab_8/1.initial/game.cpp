#include "game.h"

game::game() {}

game::game(player p1, player p2) {
    _a = p1;
    _b = p2;
}

game::~game() {}

void game::attack(int who) {
    switch (who) {
    case 1: {
        this->_b.take_damage(this->_a.get_damage());
        break;
    }
    case 2: {
        this->_a.take_damage(this->_b.get_damage());
        break;
    }
    default:
        break;
    }
}

void game::ability(int who) {
    switch (who) {
    case 1: {
        this->_a.ability(this->_b);
        break;
    }
    case 2: {
        this->_b.ability(this->_a);
        break;
    }
    default:
        break;
    }
}

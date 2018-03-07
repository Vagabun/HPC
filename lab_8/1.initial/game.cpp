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

bool game::is_dead(int who) {
    bool status;
    switch (who) {
    case 1: {
        status = this->_a.is_dead();
        break;
    }
    case 2: {
        status = this->_b.is_dead();
        break;
    }
    default:
        break;
    }
    return status;
}

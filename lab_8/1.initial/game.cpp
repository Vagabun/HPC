#include "game.h"

game::game() {}

game::game(player p1, player p2) {
    _a = p1;
    _a.current_position = 1;
    _b = p2;
    _b.current_position = 7;
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

void game::movement(int who) {
    int choice;
    bool result;
    while (1) {
        cout << "choose direction:\ntype 1 to move forward, type 2 to move backward" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            result = this->move_forward(who);
            break;
        }
        case 2: {
            result = this->move_backward(who);
            break;
        }
        default: {
            cout << "wrong input, try again" << endl;
            break;
        }
        }
        if (result)
            break;
    }
}

bool game::move_forward(int who) {
    bool result;
    switch (who) {
    case 1: {
        if (this->_a.current_position + 1 <= right_border) {
            this->_a.current_position += 1;
            result = true;
            cout << "your character moved forward" << endl;
        }
        else {
            cout << "your character can't move forward, reached the right border of arena, try again" << endl;
            result = false;
        } 
        break;
    }
    case 2: {
        if (this->_b.current_position - 1 >= left_border) {
            this->_b.current_position -= 1;
            result = true;
            cout << "your character moved forward" << endl;
        }
        else {
            cout << "your character can't move forward, reached the left border of arena, try again" << endl;
            result = false;
        }
        break;
    }
    default:
        break;
    }
    return result;
}

bool game::move_backward(int who) {
    bool result;
    switch (who) {
    case 1: {
        if (this->_a.current_position - 1 >= left_border) {
            this->_a.current_position -= 1;
            cout << "your character successfully moved backward" << endl;
            result = true;
        }
        else {
            cout << "your character can't move backward, reached the left border of arena, try again" << endl;
            result = false;
        }
        break;
    }
    case 2: {
        if (this->_b.current_position + 1 <= right_border) {
            this->_b.current_position += 1;
            result = true;
            cout << "your character successfully moved backward" << endl;
        }
        else {
            cout << "your character can't move backward, reached the right border of arena, try again" << endl;
            result = false;
        }
        break;
    }
    default:
        break;
    }
    return result;
}

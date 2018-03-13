#include "game.h"

game::game(player &p1, player &p2) {
    _a = p1;
    _a.set_position(1);
    _b = p2;
    _b.set_position(7);
}

game::~game() = default;

void game::attack(int who) {
    switch (who) {
    case 1: {
        if (distance_handler(this->_a))
            this->_b.take_damage(this->_a.get_damage());
        else
            cout << "enemy is too far for attack" << endl;
        break;
    }
    case 2: {
        if (distance_handler(this->_b))
            this->_a.take_damage(this->_b.get_damage());
        else
            cout << "enemy is too far for attack" << endl;
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
    while (true) {
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

void game::check_status(int who) {
    switch (who) {
    case 1: {
        cout << endl;
        cout << "current class: " << this->_a.get_type() << endl;
        cout << "current health: " << this->_a.get_hp() << endl;
        cout << "current position: " << this->_a.get_position() << endl;
        cout << "attack: " << this->_a.get_damage() << endl;
        cout << "attack distance: " << this->_a.get_attack_distance() << endl;
        cout << "armor: " << this->_a.get_armor() << endl;
        cout << endl;
        break;
    }
    case 2: {
        cout << endl;
        cout << "current class: " << this->_b.get_type() << endl;
        cout << "current health: " << this->_b.get_hp() << endl;
        cout << "current position: " << this->_b.get_position() << endl;
        cout << "attack: " << this->_b.get_damage() << endl;
        cout << "attack distance: " << this->_b.get_attack_distance() << endl;
        cout << "armor: " << this->_b.get_armor() << endl;
        cout << endl;
        break;
    }
    default:
        break;
    }
}

void game::start_game() {
    int current_choice;
    while (true) {
        cout << "player " << this->_current_player << ", choose your next move:" << endl;
        cout << "type 1 for attack, type 2 to use ability of your character, type 3 for movement, type 4 to check status of your character" << endl;
        cin >> current_choice;
        switch (current_choice) {
        case 1: {
            this->attack(this->_current_player);
            break;
        }
        case 2: {
            this->ability(this->_current_player);
            break;
        }
        case 3: {
            this->movement(this->_current_player);
            break;
        }
        case 4: {
            this->check_status(this->_current_player);
            continue;
        }
        default: {
            cout << "wrong input, try again" << endl;
            break;
        }
        }
        if (this->is_dead(1) && this->is_dead(2)) {
            cout << endl << "STANDOFF!" << endl;
            break;
        }
        else if (this->is_dead(1)) {
            cout << endl << "player 2 won!" << endl;
            break;
        }
        else if (this->is_dead(2)) {
            cout << endl << "player 1 won!" << endl;
            break;
        }
        this->switch_player();
    }
}

bool game::move_forward(int who) {
    bool result;
    switch (who) {
    case 1: {
        if (this->_a.get_position() + 1 <= right_border && this->_a.get_position() + 1 != this->_b.get_position()) {
            this->_a.set_position(this->_a.get_position() + 1);
            result = true;
            cout << "your character moved forward" << endl;
        }
        else {
            cout << "your character can't move forward, reached the right border of arena or position was already taken by your enemy, try again" << endl;
            result = false;
        } 
        break;
    }
    case 2: {
        if (this->_b.get_position() - 1 >= left_border && this->_b.get_position() - 1 != this->_a.get_position()) {
            this->_b.set_position(this->_b.get_position() - 1);
            result = true;
            cout << "your character moved forward" << endl;
        }
        else {
            cout << "your character can't move forward, reached the left border of arena or position was already taken by your enemy, try again" << endl;
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
        if (this->_a.get_position() - 1 >= left_border && this->_a.get_position() - 1 != this->_b.get_position()) {
            this->_a.set_position(this->_a.get_position() - 1);
            cout << "your character moved backward" << endl;
            result = true;
        }
        else {
            cout << "your character can't move backward, reached the left border of arena or position was already taken by your enemy, try again" << endl;
            result = false;
        }
        break;
    }
    case 2: {
        if (this->_b.get_position() + 1 <= right_border && this->_b.get_position() + 1 != this->_a.get_position()) {
            this->_b.set_position(this->_b.get_position() + 1);
            result = true;
            cout << "your character moved backward" << endl;
        }
        else {
            cout << "your character can't move backward, reached the right border of arena or position was already taken by your enemy, try again" << endl;
            result = false;
        }
        break;
    }
    default:
        break;
    }
    return result;
}

bool game::distance_handler(player &p) {
    return p.get_attack_distance() >= abs(this->_a.get_position() - this->_b.get_position());
}

void game::switch_player() {
    if (this->_current_player == 1)
        this->_current_player = 2;
    else
        this->_current_player = 1;
}

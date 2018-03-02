#include "common.h"
#include "goblin.h"

int goblin::call_counter = 0;

goblin::goblin() {
    _health = 100;
    _attack = rand_generator();
    _attack_dist = rand_generator();
}

goblin::~goblin() {}

void goblin::bomb() {
    switch (call_counter) {
    case 0: {
        cout << "constructing bomb..." << endl;
        ++call_counter;
        break;
    }
    case 1: {
        cout << "BOOM!" << endl;
        //call hp getter of enemy, pass it-1 to hp setter of enemy

        //call hp getter of me, pass it-1 to hp setter of me
        set_hp(get_hp() - (get_hp() - 1));
        call_counter = 0;
        break;
    }
    default:
        break;
    }
}

int goblin::get_hp() {
    return _health;
}

void goblin::set_hp(int data) {
    _health = data;
}

int goblin::rand_generator() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    return dist(gen);
}

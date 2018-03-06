#include "goblin.h"

int goblin::call_counter = 0;

goblin::goblin() {
    _health = 100;
    _attack = rand_generator();
    _attack_dist = rand_generator();
}

goblin::~goblin() {}

int goblin::damage() {
    return _attack;
}

void goblin::take_damage(int damage) {
    if (damage > _health) {
        _health = 0;
        cout << "goblin killed" << endl;
        return;
    }
    _health -= damage;
}

void goblin::bomb() {
    switch (call_counter) {
    case 0: {
        cout << "constructing bomb..." << endl;
        ++call_counter;
        break;
    }
    case 1: {
        cout << "BOOM!" << endl;
        _health -= _health - 1;
        call_counter = 0;
        break;
        //change hp of enemy likewise
    }
    default:
        break;
    }
}

//int goblin::get_hp() {
//    return _health;
//}
//
//void goblin::set_hp(int data) {
//    if (data > _health) {
//        cout << "goblin is dead" << endl;
//        return;
//    }
//    _health -= data;
//}

void goblin::coward(int damage) {
    if (damage > 0) {
        if (_health >= 50) {
            cout << "attacked himself" << endl;
            damage *= 2;
        }   
        else {
            cout << "dodged from attack!";
            damage = 0;
        }
            
    }
    _health -= damage;
}

int goblin::rand_generator() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    return dist(gen);
}

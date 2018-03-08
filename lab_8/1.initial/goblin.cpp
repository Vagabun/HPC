#include "goblin.h"

//int goblin::call_counter = 0;

goblin::goblin() {
    _health = 100;
    _attack = rand_generator("default");
    _attack_dist = rand_generator("distance");
}

goblin::~goblin() {}

int goblin::damage() {
    return this->_attack;
}

int goblin::get_hp() {
    return this->_health;
}

int goblin::get_attack_distance() {
    return this->_attack_dist;
}

void goblin::take_damage(int damage) {
    damage = this->coward(damage);
    if (damage > this->_health) {
        this->_health = 0;
        cout << "goblin killed" << endl;
        return;
    }
    this->_health -= damage;
}

int goblin::bomb(int enemy_health) {
    int damage;
    switch (this->call_counter) {
    case 0: {
        cout << "constructing bomb..." << endl;
        damage = 0;
        ++this->call_counter;
        break;
    }
    case 1: {
        cout << "BOOM!" << endl;
        this->_health -= this->_health - 1;
        damage = enemy_health - 1;
        this->call_counter = 0;
        break;
    }
    default:
        break;
    }
    return damage;
}

int goblin::coward(int damage) {
    if (damage > 0) {
        if (this->_health >= 50) {
            cout << "goblin attacked himself" << endl;
            damage *= 2;
        }   
        else {
            cout << "goblin dodged from attack!";
            damage = 0;
        }
    }
    return damage;
}

int goblin::rand_generator(string choice) {
    random_device rd;
    mt19937 gen(rd());
    if (choice == "default") {
        uniform_int_distribution<> dist(1, 100);
        return dist(gen);
    }
    else if (choice == "distance") {
        uniform_int_distribution<> dist(1, 7);
        return dist(gen);
    }
}

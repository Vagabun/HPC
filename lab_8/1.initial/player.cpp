#include "player.h"

player::player() {}

player::player(string choice) {
    if (choice == "1") {
        cout << "you have chosen Knight class" << endl << endl;
        current_class = "knight";
    } 
    else if (choice == "2") {
        cout << "you have chosen Wizard class" << endl << endl;
        current_class = "wizard";
    }
    else if (choice == "3") {
        cout << "you have chosen Goblin class" << endl << endl;
        current_class = "goblin";
    }
}

player::~player() {}

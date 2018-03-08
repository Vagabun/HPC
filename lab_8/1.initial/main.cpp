#include "game.h"

void start() {
    string choice;
    cout << "player 1 - choose your hero" << endl;
    cout << "type 1 for Knight class, type 2 for Wizard class, type 3 for Goblin class" << endl;
    cin >> choice;

    //write handler for incorrect input
    
    player player1(choice);


    cout << "player 2 - choose your hero" << endl;
    cout << "type 1 for Knight class, type 2 for Wizard class, type 3 for Goblin class" << endl;
    cin >> choice;
    player player2(choice);
    game g(player1, player2);
    g.movement(1);
    //g.movement(2);
    //g.attack(1);
    //bool t = player1.is_dead();


    cout << "hello";
}

int main() {

    start();
    return 0;
}
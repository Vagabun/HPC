#include "controllers/game.h"

void init() {
    string choice;
    cout << "player 1 - choose your hero:" << endl;
    cout << "type 1 for Knight class, type 2 for Wizard class, type 3 for Goblin class" << endl;
    cin >> choice;
    player player1(choice);
    cout << "player 2 - choose your hero:" << endl;
    cout << "type 1 for Knight class, type 2 for Wizard class, type 3 for Goblin class" << endl;
    cin >> choice;
    player player2(choice);

    game g(player1, player2);
    cout << "game starting..." << endl << endl;
    g.start_game();
}

int main() {
    
    init();
    return 0;
}
#include "game.h"

void start() {
    string choice;
    int current_player = 1, current_choice;
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
    while (true) {
        cout << "player " << current_player << ", choose your next move:" << endl;
        cout << "type 1 for attack, type 2 to use ability of your character, type 3 for movement, type 4 to check status of your character" << endl;
        cin >> current_choice;
        switch (current_choice) {
        case 1: {
            g.attack(current_player);
            break;
        }
        case 2: {
            g.ability(current_player);
            break;
        }
        case 3: {
            g.movement(current_player);
            break;
        }
        case 4: {
            g.check_status(current_player);
            continue;
        }
        default: {
            cout << "wrong input, try again" << endl;
            break;
        }
        }
        if (g.is_dead(1) && g.is_dead(2)) {
            cout << endl << "STANDOFF!" << endl;
            break;
        }
        else if (g.is_dead(1)) {
            cout << endl << "player 2 won!" << endl;
            break;
        }
        else if (g.is_dead(2)) {
            cout << endl << "player 1 won!" << endl;
            break;
        }
        if (current_player == 1)
            current_player = 2;
        else if (current_player == 2)
            current_player = 1;
        cout << endl;
    }
}

int main() {
    
    start();
    return 0;
}
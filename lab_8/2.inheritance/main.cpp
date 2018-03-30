#include "characters\character.h"
#include "characters\fresh_knight.h"
#include "characters\fresh_goblin.h"
#include "characters\fresh_wizard.h"
#include "controllers\fresh_player.h"

void init() {
    /*string choice;
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
    g.start_game();*/
}

int main() {
    
    //init();

    //character *hero1 = nullptr;
    //character *hero2 = nullptr;
    //character *hero3 = nullptr;

    //hero1 = new fresh_knight;
    //hero2 = new fresh_goblin;
    //hero3 = new fresh_wizard;
    //hero = new fresh_goblin;
    //hero1->take_damage(hero2->active_ability(hero1->get_health()));
    //hero1->take_damage(hero2->active_ability(hero1->get_health()));
    //fresh_knight b;

    fresh_player a(1);
    fresh_player b(3);

    a.take_damage(25);

    return 0;
}
#include "baker.h"

int bake(Baker b1, Baker b2, int win_counter) {
    std::array<Baker, 2> bakers = {b1, b2};
    int wins = 0, bake_quality = 0, common_experience = 0;
    bool early_win = false;
    while (wins < win_counter) {
        for (int i = 0; i < 25; ++i) {
            if (bake_quality > 300) {
                early_win = true;
                break;
            }
            for (auto &b : bakers) {
                std::random_device rd;
                std::mt19937 generator(rd());
                std::uniform_int_distribution<int> distribution(0, 2);
                switch (0) { //for win mingw because of a bug in random
//                switch (distribution(generator)) {
                    case 0 :
                        b.bake_pie();
                        bake_quality += b.get_tasty();
                        break;
                    case 1 :
                        b.eat_pie();
                        break;
                    case 2 :
                        b.return_pie(((i % 2) ? bakers.back() : bakers.front()));
                        break;
                }
            }
        }
        if (early_win) {
            int new_exp = 100;
            b1.set_new_exp(new_exp);
            b2.set_new_exp(new_exp);
            common_experience += new_exp + new_exp;
            early_win = false;
            bake_quality = 0;
            ++wins;
        }
        else {
            int new_exp = 50;
            b1.set_new_exp(new_exp);
            b2.set_new_exp(new_exp);
            common_experience += new_exp + new_exp;
        }
    }
    return common_experience;
}

int main() {

    Baker b(10);
    Baker c(10);
    bake(b, c, 15);
    b.set_new_exp(75);
    b.set_new_prof(55);
    c.set_new_exp(75);
    c.set_new_prof(55);

    return 0;
}
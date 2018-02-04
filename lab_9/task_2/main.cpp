#include "baker.h"

int bake(Baker b1, Baker b2, int win_counter) {
    std::vector<Baker> bakers;
    bakers.push_back(b1);
    bakers.push_back(b2);
    int i = 1, j = 0, bake_quality = 0, common_experience = 0;
    bool early_win;
    while (j < win_counter) {
        for (;;) {
            if (i > 25)
                break;
            else if (bake_quality > 300) {
                early_win = true;
                break;
            }
            for (auto b : bakers) {
                std::random_device rd;
                std::mt19937 generator(rd());
                std::uniform_int_distribution<int> distribution(0, 2);
                switch (distribution(generator)) {
                    case 0 :
                        b.bake_pie();
                        bake_quality += b.get_tasty();
                        break;
                    case 1 :
                        b.eat_pie();
                        break;
                    case 2 :
                        b.return_pie(bakers.back());
                        break;
                }
                std::swap(bakers.front(), bakers.back());
            }
            ++i;
        }
        if (early_win) {
            int new_exp = 100;
            b1.set_new_exp(new_exp);
            b2.set_new_exp(new_exp);
            common_experience += new_exp + new_exp;
            early_win = false;
            ++j;
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
//    b.bake_pie();
//    c.bake_pie();
//    c.bake_pie();
//    b.eat_pie();
//    b.eat_pie();
//    c.return_pie(b);
//    c.eat_pie();
//    std::cout << Pie::all_time_quantity << std::endl;

    return 0;
}
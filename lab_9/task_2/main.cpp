#include "baker.h"

int main() {

    Baker b;
    Baker c;
    b.bake_pie();
    c.bake_pie();
    c.bake_pie();
    b.eat_pie();
    b.eat_pie();
    c.return_pie(b);
    c.eat_pie();
    std::cout << Pie::all_time_quantity << std::endl;

    return 0;
}
#include "pie.h"

int main() {

    Pie p1;
    Pie p2;
    Pie p3;
    Pie::tastier(p1, p2);

    p1 = p2;

    Pie p4(67);
    Pie p5("choco pie");

    std::cout << Pie::quantity << std::endl;
    system("PAUSE");

    return 0;
}
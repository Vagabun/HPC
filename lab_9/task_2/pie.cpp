#include "pie.h"

int Pie::quantity = 0;

Pie::Pie() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> range(1, 3);
    std::uniform_int_distribution<> tastiness(1, 100);
    switch (range(gen)) {
        case 1:
        {
            title = "meat pie";
            tasty = tastiness(gen);
            ++quantity;
            break;
        }
        case 2:
        {
            title = "potato pie";
            tasty = tastiness(gen);
            ++quantity;
            break;
        }
        case 3:
        {
            title = "cheese and mushrooms pie";
            tasty = tastiness(gen);
            ++quantity;
            break;
        }
    }
    cout << "baked " << title << endl;
}

Pie::~Pie() {
    cout << title << " eaten" << endl;
}

void Pie::tastier(const Pie &obj1, const Pie &obj2) {
    if (obj1.tasty > obj2.tasty) {
        cout << obj1.title << " tastier than " << obj2.title << endl;
        return;
    }
    cout << obj2.title << " tastier than " << obj1.title << endl;
}
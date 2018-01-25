#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>

class Pie {
public:
    static int quantity;

    Pie() {
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
        std::cout << "baked " << title << std::endl;
    };
    ~Pie() {
        std::cout << "eaten" << std::endl;
    }

private:
    std::string title;
    int tasty;
};

int Pie::quantity = 0;

int main()
{
    Pie pie1;
    Pie pie2;
    system("PAUSE");
    return 0;
}


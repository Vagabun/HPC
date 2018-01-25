#include <iostream>
#include <random>
#include <chrono>

class Pie {
public:
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
//                ++quantity;
            }
            case 2:
            {
                title = "potato pie";
                tasty = tastiness(gen);
//                ++quantity;
            }
            case 3:
            {
                title = "cheese and mushrooms pie";
                tasty = tastiness(gen);
                //++quantity;
            }
        }
        std::cout << "baked " << title << std::endl;
    };
private:
    std::string title;
    int tasty;
    static int quantity;
};

int main() {

    Pie p1;
    Pie p2;

    return 0;
}
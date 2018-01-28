#include "pie.h"

int Pie::quantity = 0;

Pie::Pie() {
    std::uniform_int_distribution<int> pie_distribution(0, 2);
    std::uniform_int_distribution<int> tastiness(1, 100);
    title = pie_types[generate_rand(pie_distribution)];
    tasty = generate_rand(tastiness);
    // int value = distribution(generate_rand());  called object (distribution) is not a function?
    ++quantity;
    cout << "baked (constructor) " << title << endl;
}

Pie::~Pie() {
    cout << title << " eaten(destructor)" << endl;
}

Pie::Pie(const Pie &obj) {
    title = obj.title;
    tasty = obj.tasty;
    ++quantity;
    cout << "baked another(copy) " << title << endl;
}

Pie::Pie(string &new_title, int new_tasty) : title(new_title), tasty(new_tasty) { //how use std::move?
    ++quantity;
}

Pie::Pie(int new_tasty) {
    tasty = new_tasty;
    std::uniform_int_distribution<int> pie_distribution(0, 5);
    title = pie_types[generate_rand(pie_distribution)];
    ++quantity;
    cout << "baked (constructor) " << title << endl;
}

Pie::Pie(string &&new_title) { //rvalue?
    title = new_title;
    std::uniform_int_distribution<int> tastiness(1, 100);
    tasty = generate_rand(tastiness);
    ++quantity;
    cout << "baked (constructor) " << title << endl;
}

void Pie::tastier(const Pie &obj1, const Pie &obj2) {
    if (obj1.tasty > obj2.tasty) {
        cout << obj1.title << " tastier than " << obj2.title << endl;
        return;
    }
    cout << obj2.title << " tastier than " << obj1.title << endl;
}

Pie& Pie::operator= (const Pie& obj) {
    if (this == &obj)
        return *this;
    title = obj.title;
    tasty = obj.tasty;
    return *this;
}

int Pie::generate_rand(std::uniform_int_distribution<int> obj) {
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    return obj(generator);
}

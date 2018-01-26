#include "pie.h"

int Pie::quantity = 0;

Pie::Pie() {
    std::uniform_int_distribution<int> types_ranges(0, 2);
    std::uniform_int_distribution<int> tastiness(1, 100);
    title = types[types_ranges(generate_rand())];
    tasty = tastiness(generate_rand());
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

Pie::Pie(int tsty, string ttl) : tasty(tsty), title(ttl) {
    ++quantity;
}

Pie::Pie(int tsty) {
    tasty = tsty;
    std::uniform_int_distribution<int> types_range(0, 5);
    title = types[types_range(generate_rand())];
    ++quantity;
    cout << "baked (constructor) " << title << endl;
}

Pie::Pie(string ttl) {
    title = ttl;
    std::uniform_int_distribution<int> tastiness(1, 100);
    tasty = tastiness(generate_rand());
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

std::mt19937 Pie::generate_rand() {
    std::random_device rd;
    std::mt19937 gen(rd());
    return gen;
}

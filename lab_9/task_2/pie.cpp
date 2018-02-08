#include "pie.h"

int Pie::all_time_quantity = 0;

Pie::Pie() {
    std::uniform_int_distribution<int> pie_distribution(0, 2);
    std::uniform_int_distribution<int> tastiness(1, 100);
    title = pie_types[generate_rand(pie_distribution)];
    tasty = 0;
    //cout << "baked (constructor) " << title << endl;
}

Pie::~Pie() {
//    cout << title << " eaten(destructor)" << endl;
}

Pie::Pie(const Pie &obj) {
    title = obj.title;
    tasty = obj.tasty;
    ++all_time_quantity;
    cout << "copy: baked another pie" << title << endl;
}

Pie::Pie(string &new_title, int new_tasty) : title(new_title), tasty(new_tasty) { //how to use std::move?
    ++all_time_quantity;
    cout << "constructor: baked " << title << " pie with that tastiness - " << tasty << endl;
}

Pie::Pie(int new_tasty) {
    tasty = new_tasty;
    std::uniform_int_distribution<int> pie_distribution(0, 5);
    title = pie_types[generate_rand(pie_distribution)];
    ++all_time_quantity;
    cout << "baked (constructor) " << title << endl;
}

Pie::Pie(string &&new_title) { //rvalue?
    title = new_title;
    std::uniform_int_distribution<int> tastiness(1, 100);
    tasty = generate_rand(tastiness);
    ++all_time_quantity;
    cout << "baked (constructor) " << title << endl;
}

void Pie::tastier(const Pie &obj1, const Pie &obj2) { //rewrite
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
    std::random_device rd;
    std::mt19937 generator(rd());
    return obj(generator);
}

int Pie::get_tasty() const {
    return this->tasty;
}

void Pie::set_tasty(int new_tasty) {
    if (new_tasty >= 0)
        this->tasty = new_tasty;
    else
        cout << "set tasty: can't be such pie in the world, check your input" << endl;
}

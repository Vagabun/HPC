#include "pie.h"

int Pie::all_time_quantity = 0;

Pie::Pie() {
    std::uniform_int_distribution<int> pie_distribution(0, 2);
    std::uniform_int_distribution<int> tastiness(1, 100);
    _title = pie_types[generate_rand(pie_distribution)];
    _tasty = 0;
//    cout << "default constructor: baked " << _title << endl;
}

Pie::~Pie() {
//    cout << "default destructor" << endl;
}

Pie::Pie(const Pie &obj) {
    _title = obj._title;
    _tasty = obj._tasty;
    ++all_time_quantity;
    cout << "copy: baked another pie " << _title << endl;
}

Pie::Pie(string &new_title, int new_tasty) : _title(new_title), _tasty(new_tasty) {
    ++all_time_quantity;
    cout << "constructor: baked " << _title << " pie with that tastiness - " << _tasty << endl;
}

Pie::Pie(int new_tasty) {
    _tasty = new_tasty;
    std::uniform_int_distribution<int> pie_distribution(0, 5);
    _title = pie_types[generate_rand(pie_distribution)];
    ++all_time_quantity;
    cout << "baked (constructor) " << _title << endl;
}

Pie::Pie(string &&new_title) {
    _title = new_title;
    std::uniform_int_distribution<int> tastiness(1, 100);
    _tasty = generate_rand(tastiness);
    ++all_time_quantity;
    cout << "baked (constructor) " << _title << endl;
}

void Pie::tastier(const Pie &obj1, const Pie &obj2) {
    if (obj1._tasty > obj2._tasty) {
        cout << obj1._title << " tastier than " << obj2._title << endl;
        return;
    }
    cout << obj2._title << " tastier than " << obj1._title << endl;
}

Pie& Pie::operator= (const Pie& obj) {
    if (this == &obj)
        return *this;
    _title = obj._title;
    _tasty = obj._tasty;
    return *this;
}

int Pie::generate_rand(std::uniform_int_distribution<int> obj) {
    std::random_device rd;
    std::mt19937 generator(rd());
    return obj(generator);
}

int Pie::get_tasty() const {
    return this->_tasty;
}

void Pie::set_tasty(int new_tasty) {
    if (new_tasty >= 0)
        this->_tasty = new_tasty;
    else
        cout << "set tasty: can't be such pie in the world, check your input" << endl;
}

string Pie::get_title() const {
    return this->_title;
}

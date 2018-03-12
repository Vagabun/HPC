#include "baker.h"

Baker::Baker() {
    std::uniform_int_distribution<int> characteristics(1, 100);
    pies_array = new Pie[_max_pies_quantity];
    _pies_quantity = 0;
    _professionality = generate_rand(characteristics);
    _bellyful = generate_rand(characteristics);
    _experience = generate_rand(characteristics);
    cout << "constructor: meet the new baker with stats: " << endl;
    cout << "professionality: " << _professionality << endl;
    cout << "bellyful: " << _bellyful << endl;
    cout << "experience: " << _experience << endl << endl;
}

Baker::~Baker() {
    delete[] pies_array;
    cout << "destructor: working day is over" << endl << endl;
}

int Baker::generate_rand(std::uniform_int_distribution<int> obj) {
    std::random_device rd;
    std::mt19937 generator(rd());
    return obj(generator);
}

Baker::Baker(const Baker &obj) {
    pies_array = new Pie[_max_pies_quantity];
    for (int i = 0; i < _max_pies_quantity; ++i) {
        pies_array[i] = obj.pies_array[i];
    }
    _professionality = obj._professionality;
    _bellyful = obj._bellyful;
    _experience = obj._experience;
    _pies_quantity = obj._pies_quantity;
    cout << "copy: meet the new baker with stats: " << endl;
    cout << "professionality: " << _professionality << endl;
    cout << "bellyful: " << _bellyful << endl;
    cout << "experience: " << _experience << endl << endl;
}

Baker &Baker::operator= (const Baker &obj) {
    if (this == &obj)
        return *this;
    pies_array = obj.pies_array;
    _professionality = obj._professionality;
    _bellyful = obj._bellyful;
    _experience = obj._experience;
    return *this;
}

Baker::Baker(int new_pies_quantity) : Baker() { //delegate to default constructor
    _pies_quantity = new_pies_quantity;
    Pie::all_time_quantity += new_pies_quantity;
}

void Baker::bake_pie() {
    if (this->_bellyful < 50) {
        this->pies_array[++this->_pies_quantity-1].set_tasty(25);
        --this->_bellyful;
    }
    else if (this->_professionality > 50)
        this->pies_array[++this->_pies_quantity-1].set_tasty(75);
    else
        this->pies_array[++this->_pies_quantity-1].set_tasty(50);
    ++Pie::all_time_quantity;
    cout << "bake pie: this baker baked " << this->pies_array[this->_pies_quantity-1].get_title()
         << " with that tastiness - " << this->pies_array[this->_pies_quantity-1].get_tasty() << endl << endl;
}

void Baker::eat_pie() {
    if (this->_pies_quantity > 0) {
        this->_bellyful += 25;
        --this->_pies_quantity;
        cout << "eat pie: this baker ate " << this->pies_array[this->_pies_quantity-1].get_title() << endl << endl;
    }
    else
        cout << "eat pie: this baker doesn't have any pies" << endl << endl;
}

void Baker::return_pie(Baker &obj) {
    if (this->_pies_quantity > 0) {
        obj.pies_array[++obj._pies_quantity-1] = this->pies_array[--this->_pies_quantity];
        this->_bellyful = (this->_bellyful - 25 > 0) ? this->_bellyful - 25 : 0;
        cout << "give back pie: one baker gave his pie to another baker" << endl << endl;
    }
    else
        cout << "give back pie: that baker doesn't have any pies" << endl << endl;
}

int Baker::get_bake_tasty() const {
    if (this->_pies_quantity > 0)
        return this->pies_array[this->_pies_quantity-1].get_tasty();
    else {
        cout << "get _tasty: this baker doesn't have any pies" << endl << endl;
        return 0;
    }
}

void Baker::set_new_exp(int exp) {
    if (exp > 100) {
        cout << "set_new_exp: can't be so much experience, check input" << endl << endl;
        return;
    }
    this->_experience = exp;
}

void Baker::set_new_prof(int prof) {
    if (prof > 100) {
        cout << "set_new_prof: can't be so much professionality, check input" << endl << endl;
        return;
    }
    this->_professionality = prof;
}

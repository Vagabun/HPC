#include "baker.h"

Baker::Baker() {
    std::uniform_int_distribution<int> characteristics(1, 100);
    pies_array = new Pie[100];
    pies_quantity = 0;
    professionality = generate_rand(characteristics);
    bellyful = generate_rand(characteristics);
    experience = generate_rand(characteristics);
}

Baker::~Baker() { //add output
    delete[] pies_array;
}

int Baker::generate_rand(std::uniform_int_distribution<int> obj) {
    std::random_device rd;
    std::mt19937 generator(rd());
    return obj(generator);
}

Baker::Baker(const Baker &obj) {
    pies_array = new Pie[100];
    for (int i = 0; i < 100; ++i) {
        pies_array[i] = obj.pies_array[i];
    }
    professionality = obj.professionality;
    bellyful = obj.bellyful;
    experience = obj.experience;
    pies_quantity = obj.pies_quantity;
    cout << "copy: meet the new baker with " << pies_quantity << " pies" << endl;
}

Baker &Baker::operator= (const Baker &obj) {
    if (this == &obj)
        return *this;
    pies_array = obj.pies_array;
    professionality = obj.professionality;
    bellyful = obj.bellyful;
    experience = obj.experience;
    return *this;
}

//delegate constructor?
Baker::Baker(int new_pies_quantity) : Baker() { //add output
    pies_quantity = new_pies_quantity;
    Pie::all_time_quantity += new_pies_quantity;
}

void Baker::bake_pie() { //add output
    if (this->bellyful < 50) {
        this->pies_array[++this->pies_quantity-1].set_tasty(25);
        --this->bellyful;
    }
    else if (this->professionality > 50)
        this->pies_array[++this->pies_quantity-1].set_tasty(75);
    else
        this->pies_array[++this->pies_quantity-1].set_tasty(50);
    ++Pie::all_time_quantity;
}

void Baker::eat_pie() { //add output
    if (this->pies_quantity > 0) {
        this->bellyful += 25;
        --this->pies_quantity;
    }
    else
        cout << "eat pie: that baker doesn't have any pies" << endl;
}

void Baker::return_pie(Baker &obj) {
    if (this->pies_quantity > 0) {
        obj.pies_array[++obj.pies_quantity-1] = this->pies_array[--this->pies_quantity];
        this->bellyful = (this->bellyful - 25 > 0) ? this->bellyful - 25 : 0;
        cout << "give back pie: one baker gave his pie to another baker" << endl;
    }
    else
        cout << "give back pie: that baker doesn't have any pies" << endl;
}

int Baker::get_bake_tasty() const {
    if (this->pies_quantity > 0)
        return this->pies_array[this->pies_quantity-1].get_tasty();
    else {
        cout << "get tasty: that baker doesn't have any pies" << endl;
        return 0;
    }
}

void Baker::set_new_exp(int exp) { //add data check
    this->experience = exp;
}

void Baker::set_new_prof(int prof) { //add data check
    this->professionality = prof;
}

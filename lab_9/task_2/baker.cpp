#include "baker.h"

Baker::Baker() {
    std::uniform_int_distribution<int> pie_distribution(1, 10);
    std::uniform_int_distribution<int> characteristics(1, 100);
    int pies_quantity = generate_rand(pie_distribution);
    pies_array = new Pie[pies_quantity];
    professionality = generate_rand(characteristics);
    bellyful = generate_rand(characteristics);
    experience = generate_rand(characteristics);
}

Baker::~Baker() {
    delete[] pies_array;
}

int Baker::generate_rand(std::uniform_int_distribution<int> obj) {
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    return obj(generator);
}


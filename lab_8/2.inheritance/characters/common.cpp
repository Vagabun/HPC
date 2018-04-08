#include "common.h"

int service_functions::rand(int choice) {
    random_device rd;
    mt19937 gen(rd());
    switch (choice) {
    case rand_variants::standard : {
        uniform_int_distribution<> r(1, 100);
        return r(gen);
    }
    case rand_variants::distance : {
        uniform_int_distribution<> r(1, 6);
        return r(gen);
    }
    case rand_variants::wizard_ability : {
        uniform_int_distribution<> r(1, 4);
        return r(gen);
    }
    default:
        break;
    }
}

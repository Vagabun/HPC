#include "common.h"

int helpers::rand(helpers::rand_variants variant) {
    random_device rd;
    mt19937 gen(rd());
    switch (variant) {
	case helpers::rand_variants::standard : {
        uniform_int_distribution<> r(1, 100);
        return r(gen);
    }
	case helpers::rand_variants::distance : {
        uniform_int_distribution<> r(1, 6);
        return r(gen);
    }
	case helpers::rand_variants::wizard_ability : {
        uniform_int_distribution<> r(1, 4);
        return r(gen);
    }
    default:
        break;
    }
}

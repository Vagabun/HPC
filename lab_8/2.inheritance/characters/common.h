#pragma once

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::mt19937;
using std::string;
using std::unique_ptr;
using std::move;
using std::vector;
using std::iter_swap;
using std::swap;

enum rand_variants {
    standard, distance, wizard_ability
};

namespace service_functions {
    int rand(int choice);
}
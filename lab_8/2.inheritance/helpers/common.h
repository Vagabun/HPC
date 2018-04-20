#pragma once

#include "headers.h"

namespace helpers {
	enum class rand_variants {
		standard, distance, wizard_ability
	};
    int rand(rand_variants v);
}
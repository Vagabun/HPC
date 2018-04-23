#pragma once

#include "base_factory.h"
#include "../characters/fresh_goblin.h"

class goblin_factory : public base_factory {
public:
	unique_ptr<character> create_character();
};


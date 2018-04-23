#pragma once

#include "base_factory.h"
#include "../characters/fresh_knight.h"

class knight_factory : public base_factory {
public:
	unique_ptr<character> create_character();
};


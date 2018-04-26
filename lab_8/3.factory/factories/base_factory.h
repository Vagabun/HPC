#pragma once

#include "../characters/character.h"

class base_factory {
public:
	virtual unique_ptr<character> create_character() = 0;
	virtual ~base_factory();
};


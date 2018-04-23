#pragma once

#include "base_factory.h"
#include "../characters/fresh_wizard.h"

class wizard_factory : public base_factory {
public:
	unique_ptr<character> create_character();
};


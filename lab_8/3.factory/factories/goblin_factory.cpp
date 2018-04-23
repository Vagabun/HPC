#include "goblin_factory.h"

unique_ptr<character> goblin_factory::create_character() {
	return unique_ptr<character>(new fresh_goblin);
}

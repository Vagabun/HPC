#include "knight_factory.h"

unique_ptr<character> knight_factory::create_character() {
	return unique_ptr<character>(new fresh_knight);
}

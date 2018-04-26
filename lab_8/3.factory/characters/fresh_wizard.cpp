#include "fresh_wizard.h"

fresh_wizard::fresh_wizard() : character() {
    _mana = 100;
}

int fresh_wizard::magic_shield(int damage) {
	if (damage) {
		if (helpers::rand(helpers::rand_variants::standard) < 30) {
			if (_mana > damage * 2) {
				_mana -= damage * 2;
				damage = 0;
				_output.print("magic shield consumed all damage");
			}
			else {
				_output.print("not enough mana for magic shield");
			}
		}
	}
    return damage;
}

void fresh_wizard::take_damage(int damage) {
    damage = magic_shield(damage);
    if (damage) {
        if (_armor) {
            if (damage - _armor <= 0) {
                damage = 0;
				_output.print("all of the damage was consumed by wizard armor");
            }
            else
                damage -= _armor;
            _armor /= 2;
        }
    }
    character::take_damage(damage);
}

int fresh_wizard::active_ability(int enemy_health) {
	_output.print("selecting one of four improvements...");
    switch (helpers::rand(helpers::rand_variants::wizard_ability)) {
		case improvements::mana : {
			_mana *= 2;
			_output.print("wizard mana increased by 2 times");
			break;
		}
		case improvements::health : {
			_health *= 2;
			_output.print("wizard health increased by 2 times");
			break;
		}
		case improvements::suicide : {
			_health = 0;
			_output.print("oohps, looks like wizard suicide");
			break;
		}
		case improvements::armor : {
			_armor = 100;
			_output.print("wizard created armor");
			break;
		}
		default:
			break;
    }
    _mana = 0;
    return 0;
}

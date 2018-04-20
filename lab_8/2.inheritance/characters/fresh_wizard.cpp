#include "fresh_wizard.h"

fresh_wizard::fresh_wizard() : character() {
    _mana = 100;
}

fresh_wizard::~fresh_wizard() {}

int fresh_wizard::magic_shield(int damage) {
    if (helpers::rand(helpers::rand_variants::standard) < 30) {
        if (_mana > damage * 2) {
            _mana -= damage * 2;
            damage = 0;
			output_wrapper::instance().print("magic shield consumed all damage");
            //cout << endl << "magic shield consumed all damage" << endl;
        }
        else {
			output_wrapper::instance().print("not enough mana for magic shield");
            //cout << endl << "not enough mana for magic shield" << endl;
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
				output_wrapper::instance().print("all of the damage was consumed by wizard armor");
                //cout << endl << "all of the damage was consumed by wizard armor" << endl;
            }
            else
                damage -= _armor;
            _armor /= 2;
        }
    }
    character::take_damage(damage);
}

int fresh_wizard::active_ability(int enemy_health) {
    //cout << endl << "selecting one of four improvements..." << endl;
	output_wrapper::instance().print("selecting one of four improvements...");
    switch (helpers::rand(helpers::rand_variants::wizard_ability)) {
    case improvements::mana : {
        _mana *= 2;
        //cout << endl << "wizard mana increased by 2 times" << endl;
		output_wrapper::instance().print("wizard mana increased by 2 times");
        break;
    }
    case improvements::health : {
        _health *= 2;
        //cout << endl << "wizard health increased by 2 times" << endl;
		output_wrapper::instance().print("wizard health increased by 2 times");
        break;
    }
    case improvements::suicide : {
        _health = 0;
        //cout << endl << "oohps, looks like wizard suicide" << endl;
		output_wrapper::instance().print("oohps, looks like wizard suicide");
        break;
    }
    case improvements::armor : {
        _armor = 100;
        //cout << endl << "wizard created armor" << endl;
		output_wrapper::instance().print("wizard created armor");
        break;
    }
    default:
        break;
    }
    _mana = 0;
    return 0;
}

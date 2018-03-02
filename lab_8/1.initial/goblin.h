#pragma once
class goblin {

public:
    goblin();
	~goblin();
    void bomb();
    int get_hp();
    void set_hp(int data);

private:
    int _health, _attack, _attack_dist;
    static int call_counter;
    int rand_generator();
};


#pragma once

#include "common.h"

class character {
public:
    character();
    virtual ~character();
protected:
    virtual void ability() = 0;
private:
    int _health, _attack, _attack_distance;
    int rand_gen(const string &&choice) const;
};


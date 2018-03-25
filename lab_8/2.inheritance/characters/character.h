#pragma once

#include "common.h"

class character {
public:
    character();
    virtual ~character();
protected:
    virtual void ability() = 0;
    int rand_gen(const string &&choice) const;
private:
    int _health, _attack, _attack_distance;
};


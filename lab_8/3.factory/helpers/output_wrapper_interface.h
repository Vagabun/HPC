#pragma once

#include "headers.h"

class output_wrapper_interface {
public:
	virtual void print(string &&data) = 0;
};

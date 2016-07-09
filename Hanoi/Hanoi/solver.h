#pragma once
#include "hanoi.h"

class solver
{
private:
	uint16_t get_auxiliary(uint16_t source, uint16_t destination);

	void move_tower(hanoi &tower, uint16_t fromPole, uint16_t toPole, uint16_t withPole, uint16_t height);
public:
	solver();
	void solve(hanoi &tower, uint16_t destination);
	
};

#pragma once
#include "hanoi.h"

class solver
{
private:
	bool printing;
	uint16_t get_auxiliary(uint16_t source, uint16_t destination);
public:
	solver(bool printing);
	void solve(hanoi &tower, uint16_t destination);
	
};

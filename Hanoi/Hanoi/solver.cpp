#include "solver.h"

uint16_t solver::get_auxiliary(uint16_t source, uint16_t destination)
{
	if (source != 0 && destination != 0) return 0;
	if (source != 1 && destination != 1) return 1;
	else return 2;
}

solver::solver(bool printing)
{
	this->printing = printing;
}

void solver::solve(hanoi& tower, uint16_t destination)
{
	if (!tower.not_started()) return;

	uint16_t source = tower.get_source_number();

	uint16_t auxiliary = get_auxiliary(source, destination);
}

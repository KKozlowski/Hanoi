#include "solver.h"
#include <iostream>

uint16_t solver::get_auxiliary(uint16_t source, uint16_t destination)
{
	if (source != 0 && destination != 0) return 0;
	if (source != 1 && destination != 1) return 1;
	else return 2;
}

void solver::move_tower(hanoi& tower, uint16_t from, uint16_t to, uint16_t with, uint16_t height)
{
	if (height >= 1)
	{
		move_tower(tower, from, with, to, height - 1);

		tower.move_from_to(from, to);
		std::cout << tower.print_to_string() << std::endl;

		move_tower(tower, with, to, from, height - 1);
	}
}

solver::solver()
{
}

void solver::solve(hanoi& tower, uint16_t destination)
{
	if (!tower.not_started() || tower.get_source_number() == destination) return;

	uint16_t source = tower.get_source_number();
	uint16_t auxiliary = get_auxiliary(source, destination);

	move_tower(tower, source, destination, auxiliary, tower[source]->size());
}

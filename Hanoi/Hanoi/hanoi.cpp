#include "hanoi.h"
#include <ostream>
#include <iostream>

hanoi::hanoi(uint8_t disc_count)
{
	this->disk_count = disc_count;
	std::cout << "DISK COUNT ..: " << disk_count << std::endl;
	rods[0] = rod::get_filled_rod(disk_count);
	rods[1] = new rod();
	rods[2] = new rod();
}

bool hanoi::done() const
{
	return rods[2]->size() == disk_count;
}

uint8_t hanoi::get_disk_count() const
{
	return disk_count;
}

rod* hanoi::operator[](uint8_t i) const
{
	return rods[i];
}

rod* hanoi::at(uint8_t i) const
{
	return rods[i];
}

#include "hanoi.h"
#include <ostream>
#include <iostream>
#include <iomanip>
#include <sstream>

hanoi::hanoi(uint16_t disc_count, uint16_t source)
{
	this->disk_count = disc_count;
	this->max_disk_number = disc_count - 1;
	std::cout << "DISK COUNT ..: " << disk_count << std::endl;

	if (source < 0) source = 0;
	else if (source > 2) source = 2;

	source_number = source;

	std::cout << "SOURCE NUMBER ..: " << source_number << std::endl;

	for (int i = 0;i <= 2;i++)
	{
		rods[i] = (i == source) ? rod::get_filled_rod(disk_count) : new rod();
	}

	std::cout << print_to_string();
}

bool hanoi::completed() const
{
	return rods[2]->size() == disk_count;
}

uint16_t hanoi::get_disk_count() const
{
	return disk_count;
}

rod* hanoi::operator[](uint16_t i) const
{
	return rods[i];
}

rod* hanoi::at(uint16_t i) const
{
	return rods[i];
}

std::string hanoi::print_to_string() const
{
	std::string result = "";
	std::stringstream ss;
	for (int32_t i = disk_count - 1; i >= 0; i--)
	{
		for (rod *r : rods)
		{
			ss << std::setw(4);
			if (r->size() > i)
				ss << r->at(i);
			else
				ss << "|";
		}
		ss << '\n';
	}
	ss << "  --  --  --\n";
	return ss.str();
}

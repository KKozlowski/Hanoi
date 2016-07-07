#include "hanoi.h"
#include <ostream>
#include <iostream>
#include <iomanip>
#include <sstream>

hanoi::hanoi(uint16_t disc_count)
{
	this->disk_count = disc_count;
	std::cout << "DISK COUNT ..: " << disk_count << std::endl;
	rods[0] = rod::get_filled_rod(disk_count);
	rods[1] = new rod();
	rods[2] = new rod();

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

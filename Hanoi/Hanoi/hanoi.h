#pragma once
#include <string>
#include "rod.h"

class hanoi
{
private:
	uint16_t disk_count;
	rod *rods[3];
public:
	hanoi(uint16_t disk_count);
	bool completed() const;
	uint16_t get_disk_count() const;
	
	rod* operator[] (uint16_t) const;
	rod* at (uint16_t) const;

	std::string print_to_string() const;
};

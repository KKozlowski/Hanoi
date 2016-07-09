#pragma once
#include <string>
#include "rod.h"

class hanoi
{
private:
	uint16_t disk_count;
	uint16_t source_number;
	uint16_t max_disk_number;
	rod *rods[3];
public:
	hanoi(uint16_t disk_count, uint16_t source);
	bool not_started() const;
	bool get_source_number() const;
	uint16_t get_disk_count() const;
	
	rod* operator[] (uint16_t) const;
	rod* at (uint16_t) const;

	bool move_from_to(uint16_t source, uint16_t desc);

	std::string print_to_string() const;
};

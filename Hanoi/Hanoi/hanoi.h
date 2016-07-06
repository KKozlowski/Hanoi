#pragma once
#include "rod.h"

class hanoi
{
private:
	uint8_t disk_count;
	rod *rods[3];
public:
	hanoi(uint8_t disk_count);
	bool done() const;
	uint8_t get_disk_count() const;
	
	rod* operator[] (uint8_t) const;
	rod* at (uint8_t) const;
};

#include "rod.h"
#include <ostream>
#include <iostream>

rod::rod()
{
}

uint8_t rod::size() const {
	return disks.size();
}

bool rod::empty() const{
	return disks.empty();
}

uint8_t rod::top() const{
	return disks.back();
}

bool rod::push(uint8_t new_disk)
{
	if (empty() || top() > new_disk)
	{
		disks.push_back(new_disk);
		return  true;
	}

	return false;
}

bool rod::pop()
{
	if (!disks.empty())
	{
		disks.pop_back();
		return true;
	}
		
	return false;
}

uint8_t rod::operator[](int x) const
{
	return disks[x];
}

uint8_t rod::at(int x) const
{
	return disks[x];
}

rod* rod::get_filled_rod(int disk_number)
{
	rod *r = new rod();
	for (uint8_t i = disk_number - 1; i > 0; i--)
	{
		r->push(i);
	}
	r->push(0);
	return r;
}


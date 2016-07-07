#include "rod.h"
#include <ostream>
#include <sstream>

rod::rod()
{
}

uint16_t rod::size() const {
	return disks.size();
}

bool rod::empty() const{
	return disks.empty();
}

uint16_t rod::top() const{
	return disks.back();
}

bool rod::push(uint16_t new_disk)
{
	if (empty() || top() > new_disk)
	{
		disks.push_back(new_disk);
		dirty = true;
		return  true;
	}

	return false;
}

bool rod::pop()
{
	if (!disks.empty())
	{
		disks.pop_back();
		dirty = true;
		return true;
	}
		
	return false;
}

uint16_t rod::operator[](int x) const
{
	return disks[x];
}

rod::operator std::string()
{
	if (dirty)
	{
		std::stringstream ss;
		ss << "[ ";
		for(uint16_t i : disks)
		{
			ss << i << " ";
		}
		ss << "] (Rod)";
		str_rep = ss.str();
		dirty = false;
	}
	return str_rep;
}

uint16_t rod::at(int x) const
{
	return disks[x];
}

rod* rod::get_filled_rod(int disk_number)
{
	rod *r = new rod();
	for (uint16_t i = disk_number - 1; i > 0; i--)
	{
		r->push(i);
	}
	r->push(0);
	return r;
}


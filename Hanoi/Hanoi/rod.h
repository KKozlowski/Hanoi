#pragma once
#include <vector>
#include <string>

class rod
{
private:
	std::vector<uint16_t> disks;
	std::string str_rep;
	bool dirty = true;
public:
	rod();
	uint16_t size() const;
	bool empty() const;
	uint16_t top() const;
	bool push(uint16_t new_disk);
	bool pop();
	uint16_t operator[] (int x) const;
	explicit operator std::string();
	uint16_t at(int i) const;

	static rod *get_filled_rod(int disk_number);
};

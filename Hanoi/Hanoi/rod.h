#pragma once

#include <vector>

class rod
{
private:
	std::vector<uint8_t> disks;
public:
	rod();
	uint8_t size() const;
	bool empty() const;
	uint8_t top() const;
	bool push(uint8_t new_disk);
	bool pop();
	uint8_t operator[] (int x) const;
	uint8_t at(int i) const;

	static rod *get_filled_rod(int disk_number);
};

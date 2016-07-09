#include <iostream>
#include <sstream>
#include <string>

#include "hanoi.h"
#include "extensions.h"

using namespace std;

void main(int argc, char* argv[])
{
	uint16_t disk_count = 3;
	uint16_t source_rod = 0;

	if (argc > 1)
	{
		uint16_t nums[2] = { 0 };
		bool succs[2] = { 0 };

		succs[0] = try_get_uint16_from_chars(argv[1], nums[0]);
		if (argc > 2)
			succs[1] = try_get_uint16_from_chars(argv[2], nums[1]);

		if (succs[0]){
			if (nums[0] > 255){
				cout << "Nope";
				return;
			}
			disk_count = nums[0];
				
			if (succs[1])
			{
				source_rod = nums[1];
			}
		} else if (*argv[1] == 'h' || *argv[1] == 'H')
		{
			cout << "HELP\n";
			return;
		}
	}

	hanoi h(disk_count, source_rod);

	cin.get();
}
#include <iostream>
#include <sstream>
#include <string>

#include "hanoi.h"
#include "extensions.h"
#include "solver.h"

using namespace std;

void main(int argc, char* argv[])
{
	uint16_t disk_count = 3;
	uint16_t source_rod = 0;
	uint16_t dest_rod = 2;
	if (argc > 1)
	{
		uint16_t nums[3] = { 0 };
		bool succs[3] = { 0 };

		succs[0] = try_get_uint16_from_chars(argv[1], nums[0]);
		if (argc > 2)
			succs[1] = try_get_uint16_from_chars(argv[2], nums[1]);
		if (argc > 3)
			succs[2] = try_get_uint16_from_chars(argv[3], nums[2]);

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
			if (succs[2])
			{
				dest_rod = nums[2];
			}
		} else if (*argv[1] == 'h' || *argv[1] == 'H')
		{
			cout << "HELP\n";
			return;
		}
	}

	hanoi h(disk_count, source_rod);
	solver s;

	std::cout << "DISK COUNT: " << h.get_disk_count() << std::endl;
	std::cout << "SOURCE ROD: " << h.get_source_number() << std::endl;
	std::cout << "DESTINATION ROD: " << dest_rod << std::endl << std::endl;

	std::cout << h.print_to_string() << endl;

	s.solve(h, dest_rod);

	cin.get();
}
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
	bool printing = true;
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
			if (nums[0] > 31){
				cout << "Too many disks.";
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
			cout << "This program solves Towers of Hanoi puzzle with given parameters.\n\n"
				<< "Usage: Hanoi [n] [s] [d] [silent]\n\n"
				<< "n  -  number of disks in the puzzle, from 0 to 31 (defaulf: 3)\n"
				<< "s  -  number of the source rod, from 0 to 2 (default: 0)\n"
				<< "d  -  number of the destination rod, from 0 to 2 (default: 2)\n"
				<< "silent  -  if any of arguments is a letter 's', or a word starting with 's'\n"
				<< "           (eg. 'silent'), the program doesn't print the solution step\n"
				<< "           by step, but shows time statistics instead\n\n"
				<< "Examples:\n * Hanoi 3 0 2 s\n * Hanoi 3 1\n * Hanoi s\n * Hanoi 5 s\n * Hanoi 4 1 0\n";
			return;
		}

		for (int i = 1; i < argc;i++)
			if (*argv[i] == 's')
			{
				printing = false;
				break;
			}
	}

	hanoi h(disk_count, source_rod);
	solver s(printing);

	std::cout << "DISK COUNT: " << h.get_disk_count() << std::endl;
	std::cout << "SOURCE ROD: " << h.get_source_number() << std::endl;
	std::cout << "DESTINATION ROD: " << dest_rod << std::endl;
	std::cout << "PRINTING TO CONSOLE: " << (printing ? "true" : "false") << std::endl << std::endl;

	std::cout << h.print_to_string() << endl;

	s.solve(h, dest_rod);
}
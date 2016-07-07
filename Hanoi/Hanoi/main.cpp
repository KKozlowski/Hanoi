#include <iostream>
#include <sstream>
#include <string>

#include "hanoi.h"

using namespace std;

void main(int argc, char* argv[])
{
	uint16_t disk_count = 3;

	if (argc > 1)
	{
		string s(argv[1]);

		if (!s.empty() && s.find_first_not_of("0123456789") == string::npos)
		{
			short probe_disk_count;
			stringstream ss(s);
			ss >> probe_disk_count;
			if (disk_count > 255)
			{
				cout << "Nope";
				return;
			}

			disk_count = static_cast<uint16_t>(probe_disk_count);
				
		} else if (s == "help")
		{
			cout << "HELP\n";
			return;
		}
	}

	hanoi h(disk_count);

	cin.get();
}
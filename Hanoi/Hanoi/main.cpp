#include <iostream>
#include <sstream>
#include <string>

#include "hanoi.h"

using namespace std;

void main(int argc, char* argv[])
{
	cout <<  "Hello world";

	uint8_t disk_count = 3;

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

			disk_count = static_cast<uint8_t>(probe_disk_count);
				
		} else if (s == "help")
		{
			cout << "HELP\n";
			return;
		}
	}

	cout << "DISK COUNT: " << disk_count << endl;
	hanoi h(disk_count);

	cout << endl;
	cin.get();
}
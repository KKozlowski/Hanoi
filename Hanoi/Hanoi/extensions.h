#include <string>
#include <iostream>
#include <sstream>

bool try_get_uint16_from_chars(char *argv, uint16_t &out)
{
	std::string s(argv);

	if (!s.empty() && s.find_first_not_of("0123456789") == std::string::npos)
	{
		short probe_disk_count;
		std::stringstream ss(s);

		ss >> out;
		return true;
	}
	else
		return false;
}

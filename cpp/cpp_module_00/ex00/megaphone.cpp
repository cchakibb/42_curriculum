#include <iostream>
#include <string>
#include <cctype>

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < ac; i++)
	{
		std::string s = av[i];
		for (size_t c = 0; c < s.length(); c++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[c])));
	}
	std::cout << std::endl;
	return 0;
}

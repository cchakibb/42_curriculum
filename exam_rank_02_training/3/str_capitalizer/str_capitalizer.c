#include <unistd.h>

void capitalizer(int ac, char **av)
{
	int i = 1; // start from av[1]
	int k = 1; // start from 2nd char in each arg. 1st arg is handled separetely

	while (i < ac)
	{
		if (av[i][0] >= 'a' && 'z' >= av[i][0])
			av[i][0] -= 32;
		write(1, &av[i][0], 1);
		k = 1;
		while (av[i][k] != '\0')
		{
			if (av[i][k] >= 'A' && 'Z' >= av[i][k])
				av[i][k] += 32;
			if (av[i][k] >= 'a' && 'z' >= av[i][k] && 
			(av[i][k - 1] == ' ' || av[i][k - 1] == '\t'))
				av[i][k] -= 32;

			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

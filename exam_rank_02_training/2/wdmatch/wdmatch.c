#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int k = 0;
	int found = 0;
	if (ac == 3)
	{
		char *s1 = av[1];
		char *s2 = av[2];

		while (s1[i])
		{
			while (s2[k])
			{
				if (s1[i] == s2[k])
				{
					found++;
					break ;
				}
				k++;
			}
			k++;
			i++;
		}
		if (i == found)
		{
			write(1, s1, i);
		}
	}
	write(1, "\n", 1);
}

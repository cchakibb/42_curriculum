#include <unistd.h>

char isInStr(char c, char *str)
{
	while(*str)
	{
		if (c == *str)
			return 1;
		str++;
	}
	return 0;
}

void ft_union(char **av)
{
	
	int ascii[256] = {0};
	int i = 1;
	int k;
	while (i < 3)
	{
		k = 0;
		while(av[i][k])
		{
			if (ascii[(int)av[i][k]] == 0)
			{
				ascii[(int)av[i][k]] = 1;
				write(1, &av[i][k], 1);
			}
			k++;
		}
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
		ft_union(av);
	write(1, "\n", 1);
}
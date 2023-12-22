#include <unistd.h>

void	ft_union(int ac, char **av)
{
	int ascii[256] = {0};
	int i = 1;
	int k = 0;

	while (i < ac)
	{
		k = 0;
		while (av[i][k])
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
		ft_union(ac, av);
	write(1, "\n", 1);
	return 0;
}

#include <unistd.h>

int	charInStr(char c, char *str)
{
	while(*str)
	{
		if (c == *str)
			return 1;
		str++;
	}
	return 0;
}

void	inter(char **av)
{
	char unique[256] = "";
	int i = 0;
	char *s1 = av[1];
	char *s2 = av[2];

	while (s1[i])
	{
		if (!charInStr(s1[i], unique))
			unique[i] = s1[i];
		i++;
	}
	i = 0;
	while (unique[i])
	{
		if (charInStr(unique[i], s2))
			write(1, &unique[i], 1);
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
		inter(av);
	write(1, "\n", 1);
	return (0);
}
#include <unistd.h>

/*
int main (int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0;
		int y = 0;
		char *s1 = av[1];
		char *s2 = av[2];

		while (s1[i])
		{
			y = i + 1;
			while (s1[y])
			{
				if (s1[i] == s1[y])
					s1[y] = '0';
				y++;
			}
			i++;
		}
		i = 0;
		while (s1[i])
		{
			y = 0;
			while (s2[y])
			{
				if (s1[i] == s2[y])
				{
					write(1, &s1[i], 1);
					break ;
				}
				y++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
} */

int charInStr(char c, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av) {

	char unique[256] = {0};
	char *s1 = av[1];
	char *s2 = av[2];
	int i = 0;

	while (s1[i])
	{
		if (!charInStr(s1[i], unique))
			unique[i] = s1[i];
		i++;
	}
	i = 0;
	while(unique[i])
	{
		if(charInStr(unique[i], s2))
			write(1, &unique[i], 1);
		i++;
	}
    write(1, "\n", 1);
    return 0;
}


#include <unistd.h>

int main(int ac, char **av) //better solution
{
	if (ac == 3)
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
	write(1, "\n", 1);
	return (0);
}

/*void remove_doubles(char *str)
{
	int i = 0;
	int y;
	while(str[i])
		{
			y = i + 1;
			while(str[y])
			{
				if (str[i] == str[y])
					str[y] = '<';
				y++;
			}
			i++;
		}
}
#include <stdio.h>
int main (int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0;
		int y;
		char *s1 = av[1];
		char *s2 = av[2];

		remove_doubles(s1);
		remove_doubles(s2);
		y = 0;

		//printf("s2 = %s\n", s2);
		while (s2[y])
		{
			i = 0;
			while (s1[i])
			{
				if (s2[y] == s1[i])
					s2[y] = '<';
				i++;
			}
			y++;
		}
		i = 0;
		while (s1[i])
		{
			if (s1[i] != '<')
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (s2[i] != '<')
				write(1, &s2[i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
}*/






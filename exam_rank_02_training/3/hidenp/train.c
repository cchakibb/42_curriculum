#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

void hidenp(char **av)
{
	char *s1 = av[1];
	char *s2 = av[2];
	int i = 0;
	int k = 0;
	int count = 0;

	while(s1[i])
	{
		while(s2[k])
		{
			if (s1[i] == s2[k])
			{
				count++;
				break ;
			}
			k++;
		}
		i++;
	}
	(count == ft_strlen(s1)) ? write(1, "1", 1) : write(1, "0", 1); 
}

int main (int ac, char **av)
{
	if (ac == 3)
		hidenp(av);
	write(1, "\n", 1);
}
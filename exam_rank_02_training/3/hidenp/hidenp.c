#include <unistd.h>

void	hidenp(char **av)
{
	char *s1 = av[1];
	char *s2 = av[2];
	int i = 0;
	int k = 0;
	int len = 0;
	int found = 0;


	while(s1[len])
		len++;
	while(s1[i])
	{
		while(s2[k])
		{
			if (s1[i] == s2[k])
			{
				found++;
				break ;
			}
			k++;
		}
		i++;
	}
	(found == len) ? write(1, "1", 1) : write(1, "0", 1);

}

int main (int ac, char **av)
{
	if (ac == 3)
		hidenp(av);
	write(1, "\n", 1);
}

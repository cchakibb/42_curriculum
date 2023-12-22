#include <unistd.h>

int is_blank(char c)
{
	return (c <= ' ');
}

void	epur_str(char *s)
{
	int i = 0;
	int space = 0;
	while(is_blank(s[i]))
		i++;
	while(s[i])
	{
		if (is_blank(s[i]))
			space = 1;
		else if (!is_blank(s[i]))
		{
			if (space == 1)
			{
				write(1, " ", 1);
				space = 0;
			}
			write(1, &s[i], 1);
		}
		i++;
	}

}

int main (int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
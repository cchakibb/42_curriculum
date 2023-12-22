#include <unistd.h>

int is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

void	epur_str(char **av)
{
	char *str = av[1];
	int i = 0;
	int blank_flg = 0;
	while (is_blank(str[i]))
		i++;
	while (str[i])
	{
		if (is_blank(str[i]))
			blank_flg = 1;
		else if (!is_blank(str[i]))
		{
			if (blank_flg)
			{
				write(1, " ", 1);
				blank_flg = 0;
			}
			write(1, &str[i], 1);
		}
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av);
	write(1, "\n", 1);
	return (0);
}

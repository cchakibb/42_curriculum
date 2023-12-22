#include <unistd.h>

int is_blank(char c)
{
	return (c <= ' ');
}
int is_first_char_in_word(int idx, char *str)
{
	if(idx == 0 || is_blank(str[idx - 1]))
		return 1;
	return (0);
}
int is_lower(char c)
{
	return (c >= 'a' && 'z' >= c);
}
int is_upper(char c)
{
	return (c >= 'A' && 'Z' >= c);
}

void	str_capitalizer(int ac, char **av)
{
	int i = 1;
	int k;
	while(i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			if (is_first_char_in_word(k, av[i]) && is_lower(av[i][k]))
				av[i][k] -= 32;
			if (!is_first_char_in_word(k, av[i]) && is_upper(av[i][k]))
				av[i][k] += 32;
			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		str_capitalizer(ac, av);
	if (ac == 1)
		write(1, "\n", 1);
}
#include <unistd.h>

int	is_blank(char c)
{
	return (c <= ' ');
}
int	is_lower(char c)
{
	return (c >= 'a' && 'z' >= c);
}
int	is_upper(char c)
{
	return (c >= 'A' && 'Z' >= c);
}
int is_last_char_in_str(int idx, char *s)
{
	return (s[idx + 1] == '\0' || is_blank(s[idx + 1]));
}

void	rstr_cap(int ac, char **av)
{
	int i = 1;
	int k;
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			if (is_last_char_in_str(k, av[i]) && is_lower(av[i][k]))
				av[i][k] -= 32;
			if (!is_last_char_in_str(k, av[i]) && is_upper(av[i][k]))
				av[i][k] += 32;
			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}


int main (int ac, char **av)
{
	if (ac > 1)
		rstr_cap(ac, av);
	if (ac == 1)
		write(1, "\n", 1);
}
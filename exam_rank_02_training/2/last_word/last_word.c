#include <unistd.h>

void	last_word(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	i--;
	while(s[i] == ' ' || s[i] == '\t')
		i--;
	while(i >= 0 && s[i] > ' ')
		i--;
	i++;
	while(s[i] && s[i] > ' ')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}

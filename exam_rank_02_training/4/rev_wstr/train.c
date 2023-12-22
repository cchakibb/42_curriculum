#include <unistd.h>

int	is_blank(char c)
{
	return (c <= ' ');
}

void	rev_wstr(char *s)
{
	int i = 0;
	int end, start;
	while(s[i])
		i++;
	while(i >= 0)
	{
		while (s[i] == '\0' || is_blank(s[i]))
			i--;
		end = i;
		while(s[i] && !is_blank(s[i]))
			i--;
		start = i + 1;
		while(start <= end)
		{
			write(1, &s[start], 1);
			start++;
		}
		if (start != 0)
			write(1, " ", 1);
	}
}

main (int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}
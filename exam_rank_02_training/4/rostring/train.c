#include <unistd.h>

int is_blank(char c)
{
	return (c <= ' ');
}


void	rostring(char *s)
{
	int i = 0;
	int start = 0;
	int end = 0;

	while(s[i] && is_blank(s[i]))
		i++;
	start = i;
	while(s[i] && !is_blank(s[i]))
		i++;
	end = i;
	while (s[i] && is_blank(s[i]))
		i++;
	while(s[i])
	{
		while(is_blank(s[i]) && is_blank(s[i + 1]))
			i++;
		write(1, &s[i], 1);
		i++;
	}
	if(!is_blank(s[i - 1]))
		write(1, " ", 1);
	while (start < end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int main (int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);	
}
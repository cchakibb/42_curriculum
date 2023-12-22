#include <unistd.h>

int is_blank(char c)
{
	return (c <= ' ');
}

void	rostring(char *str)
{
	int start, end;
	int i = 0;
	while (str[i] && is_blank(str[i]))
		i++;
	start = i;
	while (str[i] && !is_blank(str[i]))
		i++;
	end = i;
	while (str[i] && is_blank(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && (is_blank(str[i]) && is_blank(str[i + 1])))
			i++;
		write(1, &str[i], 1);
		i++;
	}
	if (!is_blank(str[i - 1]))
		write(1, " ", 1);
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}


int main (int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
}
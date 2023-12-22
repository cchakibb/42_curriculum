#include <unistd.h>

int is_blank(char c)
{
	return (c == ' ' || c == '\t');
}
void	expand_str(char *str)
{
	int i = 0;
	int in_blank = 0;
	while(is_blank(str[i]))
		i++;
	while(str[i])
	{
		if (is_blank(str[i]))
			in_blank = 1;
		else if (!is_blank(str[i]))
		{
			if (in_blank)
				write(1, "   ", 3);
			in_blank = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main (int ac, char **av)
{
	char *str = av[1];
	if (ac == 2)
		expand_str(str);
	write(1, "\n", 1);
}

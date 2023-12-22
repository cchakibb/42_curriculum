#include <unistd.h>
void	rev_wstr(char *str)
{
	int start;
	int end;
	int i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
			i--;
		end = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		start = i + 1;
		while(start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		if (start != 0)
			write(1, " ", 1);
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}
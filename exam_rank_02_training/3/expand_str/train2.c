#include <unistd.h>

int is_blank(char c)
{
	return (c <= ' ');
}

void	expand_str(char *s)
{
	int i = 0;
	int flag = 0;

	while (s[i] && is_blank(s[i]))
		i++;
	while(s[i])
	{
		if(is_blank(s[i]))
			flag = 1;
		if(!is_blank(s[i]))
		{
			if (flag)
			{
				write(1, "   ", 3);
				flag = 0;
			}
			write(1, &s[i], 1);
		}
		i++;
	}
	
}
// this   time   it   will   be   more   complex$
// " this        time it      will     be    more complex  "

int main (int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
	
}
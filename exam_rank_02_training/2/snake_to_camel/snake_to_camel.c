#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	if(ac == 2)
	{
		char *str = av[1];
		while(str[i])
		{
			if(str[i] == '_')
			{
				i++;
				str[i] = str[i] - 32;
			}
			write(1, &str[i], 1);
			i++;
		}
	}
	return 0;
}

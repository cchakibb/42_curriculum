#include <unistd.h>
int ft_atoi(char *str)
{
	int res = 0;
	while(*str)
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return res;
}

void	print_hex(int nb)
{
	char *hex = "0123456789abcdef";
	if (nb >= 16)
	{
		print_hex(nb / 16);
	}
	write(1, &hex[nb % 16], 1);
}


int main (int ac, char **av)
{
	if (ac == 2)
	{
		int nb = ft_atoi(av[1]);
		print_hex(nb);
	}
		
	write(1, "\n", 1);
}
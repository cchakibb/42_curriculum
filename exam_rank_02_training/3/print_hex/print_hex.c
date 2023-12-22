#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	while(*str)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result);
}

void	print_hex(int nb)
{
	char * hex = "0123456789abcdef";
	if(nb >= 16)
		print_hex(nb / 16);
	write(1, &hex[nb % 16], 1);
}


int main (int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}



































/* #include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	while(*str != '\0')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result);
}

void	print_hex(int nb)
{
	char *hex = "0123456789abcdef";
	if (nb >= 16)
		print_hex(nb / 16);
	write(1, &hex[nb % 16], 1);

}

int main(int ac, char **av)
{
	int nb;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		print_hex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
 */
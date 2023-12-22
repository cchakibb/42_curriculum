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

void	print_hex(int dec)
{
	char *hex = "0123456789abcdef";
	if (dec >= 16)
	{
		print_hex(dec / 16);
	}
	write(1, &hex[dec % 16], 1);
}

int main(int ac, char **av)
{
	int dec = ft_atoi(av[1]);
	if (ac == 2)
		print_hex(dec);
	write(1, "\n", 1);
}

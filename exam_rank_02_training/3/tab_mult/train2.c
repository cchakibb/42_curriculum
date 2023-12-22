#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb)
{

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	ft_putchar(nb + '0');
}

int	ft_atoi(char *str)
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

void	tab_mult(int nb)
{
	int multiplier = 1;

	while (multiplier <= 9)
	{
		ft_putnbr(multiplier);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(multiplier * nb);
		ft_putchar('\n');
		multiplier++;
	}
}


int main (int ac, char **av)
{
	if (ac == 2)
		tab_mult(ft_atoi(av[1]));
	//write(1, "\n", 1);
}
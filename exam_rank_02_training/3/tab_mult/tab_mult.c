#include <unistd.h>

int		ft_atoi(char *str)
{
	int result = 0;
	while (*str)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}	

void	ft_putnbr(int nb)
{
	int n;
	n = nb;
	if (nb > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
}

void	tab_mult(int nb)
{
	int multiplier = 1;
	while(multiplier <= 9)
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

int		main (int ac, char **av)
{
    if (ac == 2)
    {   
        int nb = ft_atoi(av[1]);
        tab_mult(nb);
    }
}
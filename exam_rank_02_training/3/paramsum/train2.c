#include <unistd.h>

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

int main (int ac, char **av)
{
	(void)av;
	ac -= 1;
	ft_putnbr(ac);
	write(1, "\n", 1);
}
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int n;
	// no need to handle MIN_INT or negatives.
	n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
}

void	display_argc(int ac)
{
	ac -= 1; // ac = ac - 1 to exclude the program name.
	ft_putnbr(ac);
}

int main (int ac, char **av)
{
	// displays 0 if only prog name, or the numb of command line arguments
	display_argc(ac); 
	write(1, "\n", 1);
}

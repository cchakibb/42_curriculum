#include <unistd.h>

int	ft_atoi(char *s)
{
	int sign = 1;
	int result = 0;
	while(*s)
	{
		if(*s == '-')
		{
			sign = -1;
			s++;
		}
		if (*s >= '0' && '9' >= *s)
		{
			result *= 10;
			result += *s - '0';
		}
		s++;
	}
	return (result * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int n;
	n = nb;
	if(n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

int isPrime(int nb)
{
	int i = 2;
	if (nb <= 1)
		return (0);
	while(i * i <= nb)
	{
		if(nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(int nb)
{
	int i = 0;
	int sum = 0;
	while(nb > 0)
	{
		if(isPrime(nb))
			sum += nb;
		nb--;
	}
	ft_putnbr(sum);
}

int main(int ac, char **av)
{
	int nb;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb > 0)
			add_prime_sum(nb);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}
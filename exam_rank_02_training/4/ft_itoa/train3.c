#include <stdlib.h>


char	*ft_itoa(int nbr)
{
	char *res;
	int temp = nbr;
	int len = 0;
	int i;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	if (nbr <= 0)
		len++;
	res = malloc(len + 1);
	if(!res) return NULL;
	if(nbr == 0)
	{
		res[0] = '0';
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	i = len - 1;
	while (nbr != 0)
	{
		res[i] = (char)(nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	res[len] = '\0';
	return (res);
}

#include <stdio.h>
int main ()
{
	int i = -56;
	printf("%s", ft_itoa(i));
}
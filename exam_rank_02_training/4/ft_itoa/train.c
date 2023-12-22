#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int temp = nbr;
	int i;
	char *res;
	int length = 0;
	while (temp != 0)
	{
		temp /= 10;
		length++;
	}
	if (nbr <= 0)
		length++;
	res = malloc(length + 1);
	if (!res)
		return NULL;
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		res[0] = '0';
	i = length - 1;
	while (nbr != 0)
	{
		res[i] = (char)(nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	res[length] = '\0';
	return res;
}

#include <stdio.h>
int main()
{
	int i = 42187867;
	printf("%s", ft_itoa(i));
}
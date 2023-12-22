#include <stdlib.h>
char	*ft_itoa(int nbr)
{
	char *str;
	int temp = nbr;
	int length = 0;
	int i;
	while (temp != 0)
	{
		temp /= 10;
		length++;
	}
	if (nbr <= 0)
		length++;
	str = malloc(length + 1);
	if (!str)
		return NULL;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0) // !
		str[0] = '0';
	i = length - 1;
	while(nbr != 0)
	{
		str[i] = (char)(nbr % 10) + '0'; // !
		nbr /= 10; // !
		i--;
	}
	str[length] = '\0';
	return (str);
}

#include <stdio.h>
int main ()
{
	int i = 234;
	printf("%s", ft_itoa(i));
}

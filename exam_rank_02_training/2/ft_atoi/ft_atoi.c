int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str && ((*str == ' ') || (*str >= 9 && *str <= 13)))
		str++;
	//while (*str && (*str == '-' || *str == '+'))
	//{
		if (*str == '-')
			sign = -1;
		str++;
	//}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}

#include <stdlib.h> 
#include <stdio.h>
int main ()
{
	char *s = "-----5";
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
}

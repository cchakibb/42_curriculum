int	ft_atoi(const char *str)
{
	int sign = 1;
	int result = 0;

	while(*str)
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		if (*str >= '0' && '9' >= *str)
		{
			result *= 10;
			result += *str - '0';
		}
		str++;
	}
	return (result * sign);
}
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("+-32"));

}
int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(str[i])
	{
		result *= str_base;
		if (str[i] >= '0' && '9' >= str[i])
			result += str[i] - '0';
		else if (str[i] >= 'A' && 'Z' >= str[i])
			result += str[i] - '7';
		else if (str[i] >= 'a' && 'z' >= str[i])
			result += str[i] - 'W';
		i++;
	}
	return (result * sign);
}

#include <stdio.h>
int main ()
{
	printf("%d", ft_atoi_base("ff", 16));
}
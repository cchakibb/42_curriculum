int is_valid(char c)
{
	return ( (c >= '0' && '9' >= c) || (c >= 'a' && 'f' >= c ) || (c >= 'A' && 'F' >= c ) );
}

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign = 1;

	if(*str == '-')
	{
		sign = -1;
		str++;
	}

	while(*str && is_valid(*str))
	{
		res *= str_base;
		if (*str >= '0' && '9' >= *str)
			res += *str - '0';
		else if (*str >= 'a' && 'z' >= *str)
			res += *str - 'W';
		else if (*str >= 'A' && 'Z' >= *str)
			res += *str - '7';
		str++;
	}
		return (res * sign);
}


#include <stdio.h>
int main ()
{
	printf("%d", ft_atoi_base("-+ff", 16));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign = 1;
	int i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(str[i])
	{
		res *= str_base;
		if(str[i] >= '0' && '9' >= str[i])
			res += str[i] - '0';
		else if (str[i] >= 'a' && 'z' >= str[i])
			res += str[i] - '7';
		else if (str[i] >= 'A' && 'Z' >= str[i])
			res += str[i] - 'W';
		i++;
	}
	return (res * sign);
}
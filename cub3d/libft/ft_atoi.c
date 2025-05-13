/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:21:41 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:56:44 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static long int	expon(int y)
{
	long	x;

	if (y == 0)
		return (1);
	y = (long)y;
	x = 1;
	while (y > 0)
	{
		x *= 10;
		y--;
	}
	return (x);
}

static int	get_digits(int segnum, const char *str, int len)
{
	long long	temp;

	temp = 0;
	if (!('0' <= *str && *str <= '9'))
		return (0);
	while (('0' <= *str && *str <= '9') && len > 0)
	{
		temp += ((long long)expon(len - 1) * (long long)(*str - 48));
		str++;
		len--;
	}
	if (temp > INT_MAX && segnum == 1)
		temp = INT_MAX;
	if (temp > (-1 * (long long)INT_MIN) && segnum == -1)
		temp = -1 * (long long)INT_MIN;
	return ((int)(segnum * temp));
}

static int	get_num_count(const char *str)
{
	int	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	segnum;
	int	res;

	segnum = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			segnum *= -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		return (0);
	res = get_digits(segnum, str, get_num_count(str));
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	num[] = " 1 2 3";
	int		n;

	// char	num[] = "-2147483648";
	n = ft_atoi(num);
	printf("%d\n", n);
	printf("%d\n", atoi(num));
	return (0);
}
*/

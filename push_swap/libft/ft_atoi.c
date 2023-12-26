/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:24:19 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:00:26 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  atoi() function converts the initial portion of the
string pointed to by nptr to int. 
RETURN: The converted value or 0 on error. */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == ' ')
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while ('0' <= *nptr && *nptr <= '9')
	{
		result *= 10;
		result += (sign * (*(nptr++) - '0'));
	}
	return (result);
}
/*
int main()
{
	char *s = "   -1234ab567";
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
}
*/

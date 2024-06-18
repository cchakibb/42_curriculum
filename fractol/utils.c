/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:49:46 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/18 14:45:31 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char )*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

double	atodb(char *s)
{
	double	value;
	double	factor;
	int		sign;
	int		i;

	value = 0.0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		value = value * 10.0 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		factor = 0.1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			value += (s[i] - '0') * factor;
			factor *= 0.1;
			i++;
		}
	}
}

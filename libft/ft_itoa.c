/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:12:29 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:02:36 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. 
RETURN: The string representing the integer.
NULL if the allocation fails.
*/

static size_t	get_digits(int n)
{
	size_t	digits;

	digits = 1;
	while (n / 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int c)
{
	char		*str;
	size_t		digits;
	long int	num;

	num = c;
	digits = get_digits(c);
	if (c < 0)
	{
		num *= -1;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	*(str + digits) = 0;
	while (digits--)
	{
		*(str + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (c < 0)
		*(str + 0) = '-';
	return (str);
}
/* 
int main ()
{
	printf("%s\n", ft_itoa(95)); // a;
}
*/

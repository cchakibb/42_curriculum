/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:28 by stobin            #+#    #+#             */
/*   Updated: 2023/12/09 00:17:50 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	nn;

	nn = (long long)n;
	len = get_digits(n);
	if (n < 0)
	{
		nn = -nn;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, (len + 1) * sizeof(char));
	while (len--)
	{
		str[len] = nn % 10 + '0';
		nn = nn / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*num;
	int		n[] = {-623, 156, -0, -2147483648, 1, -1, 9, -9, 10, -10, 102, -102};
	int		i;

	i = 12;
	while (i > 0)
	{
		num = ft_itoa(n[i - 1]);
		printf("%p\n", num);
		printf("%s\n", num);
		i--;
		free(num);
	}
	return (0);
}
*/

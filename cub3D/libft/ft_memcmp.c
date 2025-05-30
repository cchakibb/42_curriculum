/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:04:35 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:52:02 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*string1;
	char	*string2;
	int		i;

	string1 = (char *)malloc(12);
	ft_bzero(string1, 12);
	string2 = (char *)malloc(12);
	ft_memset(string2, '0', 12);
	i = ft_memcmp(string1, string2, 10);
	printf("Output is:\t%d\n", i);
	return (0);
}
*/

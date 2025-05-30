/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:55:50 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:44:11 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ret;
	char	*ret2;
	char	*src;
	int		size;

	// char	str[] = "here have some stringy stringy!";
	src = "/|\x12\xff\x09\x42\2002\42|\\";
	size = 10;
	// ret = memchr(str, '!', 32);
	ret = memchr(src, '\200', size);
	ret2 = ft_memchr(src, '\200', size);
	printf("C: %s\n%p\n", ret, ret);
	printf("I: %s\n%p\n", ret2, ret2);
	return (0);
}
*/

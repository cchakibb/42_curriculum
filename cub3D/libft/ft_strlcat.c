/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:27:52 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:45:32 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	tlen;
	size_t	i;

	dlen = ft_strlen((char *)dst);
	slen = ft_strlen((char *)src);
	if (size <= dlen)
		tlen = size + slen;
	else
	{
		tlen = dlen + slen;
		i = 0;
		while (i < (size - 1 - dlen) && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (tlen);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	// char	s1[] = "aaaaa";
	// char	s2[] = "bbbbb";
	// size_t	i;

	char	*dest = "00000000000000000000";

	memset(dest, 'r', 14);
	printf("%ld", ft_strlcat(dest,
	(const char *)"lorem ipsum dolor sit amet", 15));
	write(1, "\n", 1);
	write(1, dest, 15);

	// const char	s2[] = "bbbbb";
	// char		s1b[] = "aaaaa";
	// const char	s2b[] = "bbbbb";
	// int			i;
	// printf("%s\n", s1);
	// i = ft_strlcat(s1, s2, 10);
	// printf("%d\n", i);
	// printf("%s\n", s1);
	// printf("%s\n", s1b);
	// i = strlcat(s1b, s2b, 10);
	// printf("%d\n", i);
	// printf("%s\n", s1b);

	// i = strlcat(s1, "thx to ntoniolo for this test !", 4);
	// printf("%ld\t%s\n", i, s1);
	// i = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	// printf("%ld\t%s\n", i, s2);
	return (0);
}
*/

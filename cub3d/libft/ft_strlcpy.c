/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:36:42 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 13:14:50 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	// char	s1[] = "aaaaa";
	// char	s2[] = "bbbbb";
	// size_t	i;
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
	// i = strlcpy(s1, (const char *)"thx to ntoniolo for this test !", 4);
	// printf("%ld\t%s\n", i, s1);
	// i = ft_strlcpy(s2, (const char *)"thx to ntoniolo for this test !", 4);
	// printf("%ld\t%s\n", i, s2);
	ft_strlcpy(NULL, NULL, 10);
	strlcpy(NULL, NULL, 10);
	return (0);
}
*/

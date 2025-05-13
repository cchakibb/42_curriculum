/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:11:28 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 12:02:12 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && i + j < len && big[i
					+ j] == little[j])
				j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	haystack1[] = "abcdef";
	char	haystack2[] = "abcdef";
	char	needle1[] = "g";
	char	needle2[] = "cde";
	char	haystack3[] = "abcdef";
	char	haystack4[] = "abcdef";
	char	needle3[] = "g";
	char	needle4[] = "cde";

	printf("I: No match:\t%s\t%s\t%s\n", needle1, haystack1,
		ft_strnstr(&haystack1[0], &needle1[0], 6));
	printf("I: Match:\t\t%s\t%s\t%s\n", needle2, haystack2,
		ft_strnstr(&haystack2[0], &needle2[0], 6));
	printf("C: No match:\t%s\t%s\t%s\n", needle1, haystack1,
		strnstr(&haystack3[0], &needle3[0], 6));
	printf("C: Match:\t\t%s\t%s\t%s\n", needle2, haystack2,
		strnstr(&haystack4[0], &needle4[0], 6));
}
*/

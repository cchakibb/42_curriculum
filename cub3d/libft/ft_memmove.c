/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:36 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:52:20 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	reverse_copy(char *dptr, char *sptr, int n)
{
	int	i;

	i = (int)(n - 1);
	while (i >= 0)
	{
		dptr[i] = sptr[i];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dptr;
	char	*sptr;
	int		i;

	if (!dest && !src)
		return (dest);
	dptr = (char *)dest;
	sptr = (char *)src;
	if (sptr < dptr)
	{
		reverse_copy(dptr, sptr, n);
		return (dest);
	}
	i = 0;
	while (i < (int)n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	void	*string1;
	char	string2[] = "aaaaaaaaaa";
	char	somestring[] = "bbbbbb";
	void	*blank;

	// char	*a;
	// a = "aa";
	string1 = &somestring;
	printf("Location is:\t%p\n", string1);
	blank = ft_memmove((void *)string1, (const void *)string2, 7);
	printf("Output1 is:\t%s\n", (char *)string1);
	printf("New location1 is:\t%p\n", string1);
	printf("Blank content is:\t%s\n", (char *)blank);
	printf("Blank location is:\t%p\n", blank);
	// printf("Output3 is:\t%s\n", string3);
	// printf("New location3 is:\t%p\n", string3);
	return (0);
}
*/

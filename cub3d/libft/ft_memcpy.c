/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:28:18 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:51:56 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dcopy;
	char	*scopy;

	if (dest == NULL && src == NULL)
		return (dest);
	dcopy = (char *)dest;
	scopy = (char *)src;
	while (n > 0)
	{
		*dcopy++ = *scopy++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	string1[] = "bbbbbbbbbbbbbbbbbbbbbbbbb";
	char	string2[] = "hello world!";
	char	*string3;

	// string1 = NULL;
	string3 = ft_memcpy(string1, string2, 3);
	printf("Output is:\t%s\n", string3);
	return (0);
}
*/

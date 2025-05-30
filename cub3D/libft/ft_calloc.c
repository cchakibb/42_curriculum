/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:04:48 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:57:21 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*p;
	unsigned long	bytes;

	p = NULL;
	bytes = (unsigned long)nmemb * (unsigned long)size;
	if (bytes > __SIZE_MAX__)
		return (0);
	p = (char *)malloc((size_t)bytes);
	if (!p)
		return (0);
	ft_bzero(p, (size_t)bytes);
	return ((void *)p);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	// s = (char *)ft_calloc(4, 2);
	// s = (char *)ft_calloc(0, 2);
	s = (char *)ft_calloc(0, 0);
	if (s != NULL)
		printf("%s\n", s);
	printf("%p\n", s);
	if (s)
		free(s);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:40 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:42:25 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>

int	main(void)
{
	char	p[16] = "Hello world yo!";
	int		i;

	i = 0;
	// char	*out;
	printf("%s\n", p);
	printf("%p\n", p);
	ft_bzero(p, 8);
	while (i < 16)
	{
		if (p[i] == '\0')
		{
			printf(" ");
			i++;
		}
		else
			printf("%c", p[i++]);
	}
	printf("\n");
	printf("%p\n", p);
	return (0);
}
*/

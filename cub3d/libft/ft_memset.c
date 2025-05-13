/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:11:47 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:44:41 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	while (n)
	{
		*(b++) = (unsigned char)c;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "something";

	printf("%s\n", (char *)ft_memset(s, 'a', 8));
	return (0);
}
*/

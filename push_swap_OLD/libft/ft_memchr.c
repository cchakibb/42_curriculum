/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:35:59 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:23:56 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  memchr() function scans the initial n bytes of the memory area pointed
to by s for the first instance of c. Both c and the bytes  of  the  memory
area pointed to by s are interpreted as unsigned char. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	c_ptr;

	s_ptr = (unsigned char *)s;
	c_ptr = (unsigned char)c;
	while (n--)
	{
		if (*s_ptr == c_ptr)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
/* 
int	main()
{
	size_t n = 8;
	char *s = "Chakib Bachir";
	int c = 'k';
	printf("%p\n", ft_memchr(s, c, n));
	printf("%p\n", memchr(s, c, n));
}
 */

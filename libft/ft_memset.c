/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:34:18 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:25:54 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memset() function fills the first n bytes of the memory area
pointed to by s with the constant byte c. */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;
	char			c1;

	s1 = (unsigned char *) s;
	c1 = (char) c;
	while (n--)
	{
		*s1++ = c1;
	}
	return (s);
}
/* 
int main()
{
	char s[] = "    is a dollar sign";
	ft_memset(s, '$', 3);
	printf("%s\n",s);
}
 */

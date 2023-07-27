/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:00:30 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:25:25 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memcpy() function copies n bytes from memory area src to memory
area dest. The memory areas must not overlap. Use memmove(3) if the 
memory areas do overlap. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;

	if (!(src || dest))
		return (NULL);
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}
/*
int main()
{
	size_t n = 3;
	char	 src[] = "start stop";
	char 	 dest[] = "start stop";
	ft_memcpy(dest, src + 6, n);
	printf("dest = %p\n", dest);
	printf("dest = %s\n", dest);

	memcpy(dest, src + 6, n);
	printf("dest = %p\n", dest);
	printf("dest = %s\n", dest);

}
*/

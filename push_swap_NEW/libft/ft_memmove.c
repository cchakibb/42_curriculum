/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:55:13 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/11 17:29:53 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memmove() function copies n bytes from memory area src to memory area dest.
The memory areas may overlap: copying takes place as though the bytes in src are
first copied into a temporary  array that does not overlap src or dest, and the 
bytes are then copied from the temporary array to dest. 
The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	if (!dest && !src)
		return (NULL);
	if (dest_ptr <= src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	return (dest);
}
/* 
int main()
{
	size_t n = 3;
	char	str[] = "start stop";
	ft_memmove(str, str + 2, n);
	printf("dest = %p\n", str);
	printf("dest = %s\n", str);

} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:26:47 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:33:14 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcpy() function copies up to size - 1 characters from the 
NUL-terminated ** string src to dst, NUL-terminating the result. 
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclength;

	i = 0;
	srclength = 0;
	while (src[srclength])
		srclength++;
	if (size)
	{
		while (i < size - 1)
		{
			if (src[i] != '\0')
				dst[i] = src[i];
			else
				break ;
			i++;
		}
		dst[i] = '\0';
	}
	return (srclength);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:49:22 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:33:35 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Note, however, that if strlcat() traverses size characters without finding a 
** NUL, the length of the string is considered to be size and the destination 
** string will not be NUL-terminated (since there was no space for the NUL).
** This keeps strlcat() from running off the end of a string. In practice this 
** should not happen (as it means that either size is incorrect or that dst is 
** not a proper ''C'' string). The check exists to prevent potential security
** problems in incorrect code.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

/*
int main(void)
{
    char* src = "xyz";
    char dst[100];

    dst[0] = 'a';
    dst[1] = 'a';
    dst[2] = 'a';
    dst[3] = 'a';
    dst[4] = '\0';

    unsigned int size = 6;
    printf("%u\n", ft_strlcat(dst, src, size));
    printf("%s\n", dst);

    dst[0] = 'a';
    dst[1] = 'a';
    dst[2] = 'a';
    dst[3] = 'a';
    dst[4] = '\0';

    printf("%zu\n", strlcat(dst, src, size));
    printf("%s\n", dst);
    return (0);
}
*/

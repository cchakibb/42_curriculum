/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:02:08 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:00:57 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function allocates memory for an array of  nmemb  elements
of  size bytes each and returns a pointer to the allocated memory.  The
memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
either  NULL,  or a unique pointer value that can later be successfully
passed to free().  If the multiplication of nmemb and size would result
in  integer  overflow, then calloc() returns an error.*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	space;

	space = nmemb * size;
	if (nmemb && (size != (space / nmemb)))
		return (NULL);
	ptr = (void *)malloc(space);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, space);
	return (ptr);
}

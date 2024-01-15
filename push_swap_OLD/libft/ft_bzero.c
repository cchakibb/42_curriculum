/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:11:47 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:00:52 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  bzero()  function  erases  the  data  in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes  con‐
taining '\0') to that area. */

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:18:35 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 11:52:33 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* checks  whether  c is a 7-bit unsigned char value that fits into the
ASCII character set. */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

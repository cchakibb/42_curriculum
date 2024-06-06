/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:48 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:48 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int	ft_putstring(char *value)
{
	int	len;

	len = 0;
	if (value == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (value[len])
	{
		ft_putchar(value[len]);
		len ++;
	}
	return (len);
}

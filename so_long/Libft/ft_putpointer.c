/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:42 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:42 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_pointerlen(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len ++;
	}
	return (len);
}

int	ft_put_pointer(unsigned long num)
{
	if (num < 16)
	{
		if (num < 10)
		{
			num = num + 48;
			write(1, &num, 1);
			return (0);
		}
		else
		{
			ft_putchar(num + 87);
			return (0);
		}
	}
	while (num >= 16)
	{
		ft_put_pointer(num / 16);
		num = num % 16;
		ft_put_pointer(num % 16);
	}
	return (1);
}

int	ft_putpointer(void *val)
{
	unsigned long	val1;
	int				count;

	count = 0;
	val1 = (unsigned long)val;
	if (val == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = ft_pointerlen(val1);
	count += write(1, "0x", 2);
	ft_put_pointer(val1);
	return (count);
}

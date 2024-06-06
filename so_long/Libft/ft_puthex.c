/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:25 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len ++;
	while (num != 0)
	{
		num = num / 16;
		len ++;
	}
	return (len);
}

int	ft_put_hex(unsigned int num, char ch)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, ch);
		ft_put_hex(num % 16, ch);
	}
	if (num < 16)
	{
		if (num < 10)
			ft_putchar(num + 48);
		else
		{
			if (ch == 'x')
				ft_putchar(num + 87);
			else
				ft_putchar(num + 55);
		}
	}
	return (1);
}

int	ft_puthex(unsigned int num, char ch)
{
	int	len;

	len = 0;
	ft_put_hex(num, ch);
	len = ft_hexlen(num);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:41:59 by chbachir          #+#    #+#             */
/*   Updated: 2023/06/13 12:19:16 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_arg(va_list args)
{
	char	c;
	int		bytes;

	bytes = 1;
	c = va_arg(args, int);
	write(1, &c, 1);
	return (bytes);
}

int	str_arg(va_list args)
{
	char	*str;
	int		bytes;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		bytes = 6;
		return (bytes);
	}
	bytes = ft_strlen(str);
	write(1, str, bytes);
	return (bytes);
}

int	addr_arg(va_list args)
{
	void	*p;
	int		bytes;

	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		bytes = 5;
		return (bytes);
	}
	else
	{
		bytes = base_length((unsigned long)p, 16) + 2;
		write(1, "0x", 2);
		write_base((unsigned long)p, 16, "0123456789abcdef");
		return (bytes);
	}
}

int	int_arg(va_list args)
{
	int	num;
	int	bytes;

	num = va_arg(args, int);
	bytes = int_length(num);
	ft_putnbr_fd(num, 1);
	return (bytes);
}

int	unsigned_arg(va_list args)
{
	int				bytes;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	bytes = base_length(num, 10);
	write_base(num, 10, "0123456789");
	return (bytes);
}

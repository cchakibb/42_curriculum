/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:30:35 by chbachir          #+#    #+#             */
/*   Updated: 2023/06/13 12:19:12 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_arg_lower(va_list args)
{
	int				bytes;
	unsigned int	num;

	num = va_arg(args, unsigned long);
	bytes = base_length(num, 16);
	write_base((unsigned long)num, 16, "0123456789abcdef");
	return (bytes);
}

int	hex_arg_upper(va_list args)
{
	int				bytes;
	unsigned int	num;

	num = va_arg(args, unsigned long);
	bytes = base_length(num, 16);
	write_base((unsigned long)num, 16, "0123456789ABCDEF");
	return (bytes);
}

int	percentage_arg(void)
{
	char	c;
	int		bytes;

	c = '%';
	bytes = 1;
	write(1, &c, 1);
	return (bytes);
}

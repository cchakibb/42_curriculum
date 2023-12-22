/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:54:24 by chbachir          #+#    #+#             */
/*   Updated: 2023/12/18 13:17:09 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_length(long int num)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		++len;
		num = -num;
	}
	while (num / 10)
	{
		++len;
		num = num / 10;
	}
	return (len);
}

int	base_length(unsigned long num, int base)
{
	int	len;

	len = 1;
	while (num / base)
	{
		++len;
		num /= base;
	}
	return (len);
}

void	write_base(unsigned long num, int base_len, char *base)
{
	int	i;

	if (num / base_len != 0)
		write_base(num / base_len, base_len, base);
	i = num % base_len;
	write(1, &base[i], 1);
}

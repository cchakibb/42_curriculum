/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:33 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:33 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len ++;
	}
	while (num != 0)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

int	ft_put_nbr(int num)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num <= 9)
	{
		ft_putchar(num + 48);
		return (0);
	}
	while (num > 9)
	{
		ft_put_nbr(num / 10);
		num = num % 10;
		ft_put_nbr(num % 10);
	}
	return (0);
}

int	ft_putnbr(int num)
{
	int	len;

	len = 0;
	ft_put_nbr(num);
	len += ft_len(num);
	return (len);
}
/*int main(void)
{
    ft_putnbr(123);
}*/

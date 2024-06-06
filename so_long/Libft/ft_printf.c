/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:13 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:13 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int	ft_formatconv(va_list vl, char format)
{
	int	count;

	count = 0;
	if (format == 's')
		count += ft_putstring (va_arg(vl, char *));
	if (format == 'c')
		count += ft_putchar(va_arg(vl, int));
	if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(vl, unsigned int), format);
	if (format == '%')
		count += ft_putchar('%');
	if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(vl, int));
	if (format == 'p')
		count += ft_putpointer(va_arg(vl, void *));
	if (format == 'u')
		count += ft_putunsigned_int(va_arg(vl, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_formatconv(args, str[i + 1]);
			i ++;
		}
		else
			count += ft_putchar(str[i]);
		i ++;
	}
	return (count);
}

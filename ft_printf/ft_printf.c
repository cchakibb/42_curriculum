/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:36:49 by chbachir          #+#    #+#             */
/*   Updated: 2023/06/13 12:26:46 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = char_arg(args);
	else if (c == 's')
		bytes = str_arg(args);
	else if (c == 'p')
		bytes = addr_arg(args);
	else if (c == 'd' || c == 'i')
		bytes = int_arg(args);
	else if (c == 'u')
		bytes = unsigned_arg(args);
	else if (c == 'x')
		bytes = hex_arg_lower(args);
	else if (c == 'X')
		bytes = hex_arg_upper(args);
	else if (c == '%')
		bytes = percentage_arg();
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;
	int		i;

	va_start(args, format);
	i = 0;
	chars_printed = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			chars_printed++;
		}
		else
			chars_printed += format_type(format[++i], args);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
/* 
#include <stdio.h>
int	main()
{
	char	c = 'c';
	char	*s = "string";
	int		d = 5;
	unsigned int i = 59;
	unsigned int u = 59;
	i = 11;
	int		*p = &d;
	ft_printf("c = %c\ns = %s\np = %p\nd = %d\ni = \
	%i\nu = %u\nx = %x\nX = %X\n%%\n", c, s, p, d, i, u, p, p);
}
 */

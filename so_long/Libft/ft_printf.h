/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:16 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:16 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_formatconv(va_list vl, char format);
int	ft_putchar(int c);
int	ft_putstring(char *value);
int	ft_puthex(unsigned int num, char ch);
int	ft_put_hex(unsigned int num, char ch);
int	ft_hexlen(unsigned int num);
int	ft_putunsigned_int(unsigned int num);
int	ft_unsigned_len(unsigned int num);
int	ft_put_unsigned_int(unsigned int num);
int	ft_putpointer(void *val);
int	ft_put_pointer(unsigned long num);
int	ft_pointerlen(unsigned long num);
int	ft_putnbr(int num);
int	ft_len(int num);
int	ft_put_nbr(int num);

#endif

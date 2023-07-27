/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:43:33 by chbachir          #+#    #+#             */
/*   Updated: 2023/06/13 12:19:35 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
/* Conversions 1 & 2 */
int		char_arg(va_list args);
int		str_arg(va_list args);
int		addr_arg(va_list args);
int		int_arg(va_list args);
int		unsigned_arg(va_list args);
int		hex_arg_lower(va_list args);
int		hex_arg_upper(va_list args);
int		percentage_arg(void);
/* extra_functions */
size_t	ft_strlen(const char *s);
int		int_length(long int num);
int		base_length(unsigned long num, int base);
void	ft_putnbr_fd(int n, int fd);
void	write_base(unsigned long num, int base_len, char *base);

#endif
